#pragma once
#include"NacitaneData.h"
#include<string>
#include"FormatovacFiltraUJTyp.h"
#include"FormatovacFiltraPocetObyvatelov.h"
#include"ZlozenyFilter.h"
#include"FormatovacFiltraUJNazov.h"
#include"FormatovacFiltraUJZastavanost.h"
#include<io.h>
#include<fcntl.h>
#include"Triedenie.h"
#include"FormatovacFiltraPrislusnost.h"
#include"FormatovacTriedenia.h"
#include"FormatovacVypisuBytovejJednotky.h"
#include"FormatovacFiltraBytovaJednotka.h"
#include"KriteriumUJpocetBJ.h"
#include"VyberoveKriteriumBJPocet.h"
#include"VyberoveKriteriumUJsMinMaxPoctomBJ.h"

class UzivatelskeProstredie
{
	NacitaneData* data;
public:
	UzivatelskeProstredie() {
		std::wcout << "Prebieha nacitanie dat zo suboru, cakajte prosim.\n";
		this->data = new NacitaneData();
	}
	~UzivatelskeProstredie() {
		delete this->data;
	}

	void menu() { 
		std::wstring volba = L"";
		do {
			volba = L"0";
			std::wcout << L"------------------------------------------------------------------\n";
			std::wcout << L"Zadajte cislo pre zvolenie prislusnej moznosti a stlacte enter\n";
			std::wcout << L"\n";
			std::wcout << L"[1] [zadanie 3] Vypisanie informacii o uzemnych jednotkach\n";
			std::wcout << L"[2] [zadanie 4] Zoradenie uzemnych jednotiek splnajucich dany filter\n";
			std::wcout << L"[3] [zadanie 5] VypÌsanie inform·ciÌ o zoskupeniach bytov˝ch jednotiek vo zvolenej ˙zemnej jednotke\n";
			std::wcout << L"[4] [zadanie 6] VypÌsanie sum·rnych inform·ciÌ o poËtoch bytov˝ch jednotiek vo zvolen˝ch ⁄J\n";
			std::wcout << L"[5] [zadanie 7] Zoradneie ˙zemn˝ch jednotiek podæa sum·rneho poËtu zvolen˝ch bytov˝ch jednotiek\n";
			std::wcout << L"[6] [zadanie 8] VypÌsanie v˝berov˝ch kritÈriÌ pre zoskupenia bytov˝ch jednotiek vo zvolen˝ch ˙zemn˝ch jednotk·ch\n";
			std::wcout << L"[7] [zadanie 9] VypÌsanie v˝berov˝ch kritÈriÌ pre ˙zemnÈ jednotky na z·klade zvolen˝ch zoskupenÌ bytov˝ch jednotiek\n";

			std::wcout << "\n[0] Ukoncit\n";
			//std::getline(std::wcin, volba);
			volba = CitacZKlavesnice::citajString();
			//std::wcin >> volba;
			if (volba == L"1") {
				this->informacieOUzemnychJednotkach();
			}
			else if (volba == L"2") {
				this->zoradenieUzemnychJednotiekSFiltrom();
			}
			else if (volba == L"3") {
				this->informacieOBytovychJednotkach();
			}
			else if (volba == L"4") {
				this->informacieSumarnychInformaciiOPoctochBJ();
			}
			else if (volba == L"5") {
				this->zoradenieUJPodlaSumarnehoPoctuZvolenychBJ();
			}
			else if (volba == L"6") {
				this->vyberoveKriteriaPreBJ();
			}
			else if (volba == L"7") {
				this->vyberoveKriteriaPreUJ();
			}
		} while (volba != L"0");
	}
private:
	UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* filtrujUzemneJednotky() {
		//FILTER UJ TYP- filtrovanie podlat typu
		FormatovacFiltraUJTyp formatovacTypu;
		bool trebaMazatTabulku = false;

		SortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaVstupna =
			reinterpret_cast<SortedSequenceTable<std::wstring, UzemnaJednotka*>*>
			(&formatovacTypu.dajMiVhodnuTabulku(this->data->getSlovensko(), trebaMazatTabulku, true));


		//FILTER UJ NAZOV - bodove vyhladanie podla nazvu
		bool trebaMazatPodlaNazov = false;
		FormatovacFiltraUJNazov formatovacUJNazov;
		SortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaVstupna2 = formatovacUJNazov.uplatniFilter(tabulkaVstupna, trebaMazatPodlaNazov);
		//prazdna tabulka pre zlozeny filter
		UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaVystupna = new UnsortedSequenceTable<std::wstring, UzemnaJednotka*>();


		ZlozenyFilter<UzemnaJednotka, std::wstring> zlozenyFilter;
		//FILTER UJ pocet obyvatelov
		FormatovacFiltraPocetObyvatelov formatovacPocetObyvatelov;
		//FILTER UJ zastavanost
		FormatovacFiltraUJZastavanost formatovacZastavanost;
		//filter prislusnost
		FormatovacFiltraPrislusnost formatovacPrislusnost;

		Filter<int, UzemnaJednotka>* filterPocetObyv = formatovacPocetObyvatelov.vratFilter();
		zlozenyFilter.pridajFilter(filterPocetObyv);

		Filter<double, UzemnaJednotka>* filterZastavanost = formatovacZastavanost.vratFilter();
		zlozenyFilter.pridajFilter(filterZastavanost);
		
		Filter<bool, UzemnaJednotka>* filterPrislusnost = formatovacPrislusnost.vratFilter();
		zlozenyFilter.pridajFilter(filterPrislusnost);

		zlozenyFilter.vyfiltruj(*tabulkaVstupna2, *tabulkaVystupna);


		if (trebaMazatTabulku) {
			delete tabulkaVstupna;
		}
		if (trebaMazatPodlaNazov) {
			delete tabulkaVstupna2;
		}


		

		return tabulkaVystupna;
		


	}
	





	//3
	void informacieOUzemnychJednotkach() {

		UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaVystupna = this->filtrujUzemneJednotky();
		

		for (auto itema : *tabulkaVystupna) {
			std::wcout << this->getVypisUzemnaJednotka(*itema->accessData()) << "\n";
		}

		delete tabulkaVystupna;
	}


	std::wstring getVypisUzemnaJednotka(UzemnaJednotka& uj) {
		std::wstring vrat;
		vrat += uj.getTypAkoRetazec() + L": " + uj.getNazov();
		UzemnaJednotka* vyssiaJednotka = nullptr;
		vyssiaJednotka = uj.getVyssiaUzemnaJednotka();
		while (vyssiaJednotka != nullptr) {
			vrat += L" " + vyssiaJednotka->getTypAkoRetazec() + L": " + vyssiaJednotka->getNazov();
			vyssiaJednotka = vyssiaJednotka->getVyssiaUzemnaJednotka();
		}
		vrat += L"\n";
		vrat += L"PoËet obyvateæov: " + std::to_wstring(uj.getPocetObyvatelov()) + L"\n";
		vrat += L"PoËet preproduktÌvnych obyvateæov: " + std::to_wstring(uj.getPocetPreproduktivnychObyvatelov()) + L"\n";
		vrat += L"PoËet produktÌvnych obyvateæov: " + std::to_wstring(uj.getPocetProduktivnychObyvatelov()) + L"\n";
		vrat += L"PoËet poproduktÌvnych obyvateæov: " + std::to_wstring(uj.getPocetPoproduktivnychObyvatelov()) + L"\n";
		vrat += L"Zastavanosù: " + std::to_wstring(uj.getZastavanost()) + L"\n";
		vrat += L"Celkov· v˝mera: " + std::to_wstring(uj.getCelkovaVymera()) + L"\n";
		vrat += L"Zastavan· plocha: " + std::to_wstring(uj.getZastavanaPlocha()) + L"\n";
		
		return vrat;
	}


	//4
	void zoradenieUzemnychJednotiekSFiltrom() {
		UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaVystupna = this->filtrujUzemneJednotky();
		

		std::wstring vstup;
		std::wcout << L"[1] Triedenie podla UJ nazov\n";
		std::wcout << L"[2] Triedenie podla poctu obyvatelov\n";
		std::wcout << L"[3] Triedenie podla zastavanosti\n";

		vstup = CitacZKlavesnice::citajString();


		//triedenie podla UJ nazov
		if (vstup == L"1") {
			
			KriteriumUJNazov kriteriumNazov;
			FormatovacTriedenia<std::wstring, UzemnaJednotka, std::wstring> formatovacTriedenia;
			formatovacTriedenia.tried(tabulkaVystupna, &kriteriumNazov);
			for (TableItem<std::wstring, UzemnaJednotka*>* itema : *tabulkaVystupna) {
				std::wcout << itema->accessData()->getNazov() << L" \n";
			}
		} 
		//triedenie podla poctu obyvatelov
		else if (vstup == L"2") {
			KriteriumUJPocetObyvatelov kriteriumPocetObyvatelov;
			FormatovacTriedenia<int, UzemnaJednotka, std::wstring> formatovacTriedenia;
			formatovacTriedenia.tried(tabulkaVystupna, &kriteriumPocetObyvatelov);
			for (TableItem<std::wstring, UzemnaJednotka*>* itema : *tabulkaVystupna) {
				std::wcout << itema->accessData()->getNazov() << L",poËet obyvateæov: " << itema->accessData()->getPocetObyvatelov() << "\n";
			}

		}
		//triedenie podla zastavanosti
		else if (vstup == L"3") {
			KriteriumUJZastavanost kriteriumZastavanost;
			FormatovacTriedenia<double, UzemnaJednotka, std::wstring> formatovacTriedenia;
			formatovacTriedenia.tried(tabulkaVystupna, &kriteriumZastavanost);
			for (TableItem<std::wstring, UzemnaJednotka*>* itema : *tabulkaVystupna) {
				std::wcout << itema->accessData()->getNazov() << L",zastavanosù: " << itema->accessData()->getZastavanost() << "\n";
			}

		}
		

		delete tabulkaVystupna;
	}


	//5
	void informacieOBytovychJednotkach() {
		//TYP uzemnej jednotky
		UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaVystupna = this->filtrujUzemneJednotky();

		FormatovacVypisuBytovejJednotky vypisBJ;

		for (auto itema : *tabulkaVystupna) {
			std::wcout << this->getVypisUzemnaJednotka(*itema->accessData());
			std::wcout << L"\n" << vypisBJ.reprezentujBytovuJednotku(itema->accessData()->getBytovaJednotka());
		}


		delete tabulkaVystupna;
	}
	//6
	void informacieSumarnychInformaciiOPoctochBJ() {
		UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaVystupna = this->filtrujUzemneJednotky();


		FormatovacFiltraBytovaJednotka formatovacBJ;
		
		KriteriumBJPocetSVlastnostami* kriteriumBJ = formatovacBJ.dajMiKriteriumBJPocetSVlastnostami();

		for (auto itema : *tabulkaVystupna) {
			UzemnaJednotka* uzemnaJednotka = itema->accessData();
			std::wcout << this->getVypisUzemnaJednotka(*uzemnaJednotka) << L"poËet vyhovuj˙cich bytov˝ch jednotiek:" <<
				std::to_wstring(kriteriumBJ->ohodnot(*uzemnaJednotka->getBytovaJednotka())) << L"\n\n";
		}
		delete kriteriumBJ;
		delete tabulkaVystupna;
	}

	//7 
	void zoradenieUJPodlaSumarnehoPoctuZvolenychBJ() {
		UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaVystupna = this->filtrujUzemneJednotky();


		FormatovacFiltraBytovaJednotka formatovacBJ;

		KriteriumBJPocetSVlastnostami* kriteriumBJ = formatovacBJ.dajMiKriteriumBJPocetSVlastnostami();


		


		FormatovacTriedenia<int, UzemnaJednotka, std::wstring> formatovacTriedenia;
		KriteriumUJpocetBJ kriteriumUJpocetbj(kriteriumBJ);

		formatovacTriedenia.tried(tabulkaVystupna, &kriteriumUJpocetbj);

		for (auto itema : *tabulkaVystupna) {
			UzemnaJednotka* uzemnaJednotka = itema->accessData();
			std::wcout << this->getVypisUzemnaJednotka(*uzemnaJednotka) << L"poËet vyhovuj˙cich bytov˝ch jednotiek:" <<
				std::to_wstring(kriteriumBJ->ohodnot(*uzemnaJednotka->getBytovaJednotka())) << L"\n\n";
		}

		delete tabulkaVystupna;
		
	}

	//8
	void vyberoveKriteriaPreBJ() {
		UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaVystupna = this->filtrujUzemneJednotky();



		VyberoveKriteriumBJPocet vyberoveKriterium;
		FormatovacVypisuBytovejJednotky formatovacVypisuBJ;

		for (auto itema : *tabulkaVystupna) {
			UzemnaJednotka* uj = itema->accessData();
			std::wcout << uj->getNazov() << L" \n";
			int minIndex;
			int maxIndex;
			vyberoveKriterium.vypocitajMinAMax(minIndex, maxIndex, uj->getBytovaJednotka());

			std::wcout << L"Zoskupenie BJ s minim·lnym poËtom:\n";
			std::wstring posliDoStreamu =  formatovacVypisuBJ.reprezentujZoskupenieBJnaIndexe(uj->getBytovaJednotka(), minIndex);
			std::wcout << posliDoStreamu;

			std::wcout << L"Zoskupenie BJ s maxim·lnym poËtom:\n";
			posliDoStreamu =  formatovacVypisuBJ.reprezentujZoskupenieBJnaIndexe(uj->getBytovaJednotka(), maxIndex);
			std::wcout << posliDoStreamu;

			std::wcout << "\n";
		}

		delete tabulkaVystupna;
	}

	//9
	void vyberoveKriteriaPreUJ() {
		UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaVystupna = this->filtrujUzemneJednotky();



		FormatovacFiltraBytovaJednotka formatovacBJ;

		KriteriumBJPocetSVlastnostami* kriteriumBJ = formatovacBJ.dajMiKriteriumBJPocetSVlastnostami();




		UzemnaJednotka* minUJ;
		int pocetMin = 0;
		UzemnaJednotka* maxUJ;
		int pocetMax = 0;




		VyberoveKriteriumUJsMinMaxPoctomBJ vyberoveKriteriumUJ(kriteriumBJ);
		vyberoveKriteriumUJ.vypocitajMinAMax(tabulkaVystupna, minUJ, pocetMin, maxUJ, pocetMax);

		if (minUJ != nullptr && maxUJ != nullptr) {
			std::wcout << L"⁄zemn· jednotka s minim·lnym poËtom bytov˝ch jednotiek: \n";
			std::wcout << minUJ->getNazov() << L", poËet BJ v jednotke: " << pocetMin << L"\n";
			std::wcout << L"⁄zemn· jednotka s maxim·lnym poËtom bytov˝ch jednotiek: \n";
			std::wcout << maxUJ->getNazov() << L", poËet BJ v ˙zemnej jednotke: " << pocetMax << L"\n";

		}


		
		delete tabulkaVystupna;
	}



};

