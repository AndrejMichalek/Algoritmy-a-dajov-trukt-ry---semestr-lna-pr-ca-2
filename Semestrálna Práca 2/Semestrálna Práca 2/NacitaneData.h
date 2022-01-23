#pragma once
#include<fstream>
#include<string>
#include<sstream>
#include"StatUzemnaJednotka.h"
#include<iostream>
#include"Triedenie.h"
#include"KriteriumUJCelkovaVymera.h"
#include"array.h"

#define POCET_TYPOV 5
#define POCET_OSOB 11
#define POCET_OBYTNYCH_MIESTNOSTI 10
#define BJ_SUBOR_STLPCOV 13

class NacitaneData
{
private:
	StatUzemnaJednotka* slovensko;

public:
	NacitaneData() {
		slovensko = new StatUzemnaJednotka();
		nacitajUzemneJednotky();
	}
	~NacitaneData() {
		delete this->slovensko;
	}



	void triedPodla() {
		
		



		//for (TableItem<std::string, KrajUzemnaJednotka*>* kraj : slovensko->getKraj()) {
		//	std::cout << kraj->accessData()->getNazov() << "\n";
		//}
		std::cout << "\n";
		int i = 0;

		Triedenie<double, UzemnaJednotka, std::wstring> triedenie;
		
		KriteriumUJCelkovaVymera kriterium;

		triedenie.tried(&(slovensko->getObce()), &kriterium, false);


		//wpfko
		
		//shell sort
		//quick sort
		for (TableItem<std::wstring, UzemnaJednotka*>* obec : slovensko->getObce()) {
			std::wcout << i << "." << obec->accessData()->getNazov() << "\n";
	
			i++;
		}
	}
	
	StatUzemnaJednotka* getSlovensko() {
		return this->slovensko;
	}



private:

	//void nacitajUzemneJednotky() {
	//	std::wifstream citacObce1;
	//	std::wifstream citacObce2;

	//	citacObce1.imbue(std::locale("Slovak"));
	//	citacObce2.imbue(std::locale("Slovak"));
	//	citacObce1.open("1 Obce SR.csv");
	//	citacObce2.open("2 Územné èlenenie SR.csv");


	//	std::wstring riadokObce1;
	//	std::wstring riadokObce2;

	//	

	//	ArrayList<ArrayList<int>*>* nacitaneInformaciePreBJ = this->nacitajBytoveJednotky();

	//	int indexArrayListu = 0;
	//	//nazov - string
	//	//preproduktivni int
	//	//produktivni int
	//	//poproduktivni int
	//	//celkova vymera double
	//	//zastavana plocha double
	//	std::getline(citacObce1, riadokObce1);
	//	std::getline(citacObce2, riadokObce2);



	//	while (std::getline(citacObce1, riadokObce1)) {
	//		std::wstringstream bunkovac(riadokObce1);
	//		std::wstring rozkuskovanyRiadok[6];
	//		

	//		for (int i = 0; i < 6; i++) {
	//			std::getline(bunkovac, rozkuskovanyRiadok[i], L';');
	//		}
	//		
	//		std::wstring nazovObce = rozkuskovanyRiadok[0];
	//		int pocetPreproduktivnych = std::stoi(rozkuskovanyRiadok[1]);
	//		int pocetProduktivnych = std::stoi(rozkuskovanyRiadok[2]);
	//		int pocetPoproduktivnych = std::stoi(rozkuskovanyRiadok[3]);
	//		double celkovaVymera = std::stod(rozkuskovanyRiadok[4]);
	//		double zastavanaPlocha = std::stod(rozkuskovanyRiadok[5]);



	//		std::getline(citacObce2, riadokObce2);
	//		std::wstringstream bunkovac2(riadokObce2);
	//		std::wstring rozkuskovanyRiadok2[3];

	//		for (int i = 0; i < 3; i++) {
	//			std::getline(bunkovac2, rozkuskovanyRiadok2[i], L';');
	//		}
	//		std::wstring nazovOkresu = rozkuskovanyRiadok2[1];
	//		std::wstring nazovKraja = rozkuskovanyRiadok2[2];
	//		//nacitanie BJ
	//		//------------------------------------




	//		//------------------------------------

	//		ObecUzemnaJednotka* obec = new ObecUzemnaJednotka(nazovObce, pocetPreproduktivnych, pocetProduktivnych, pocetPoproduktivnych, celkovaVymera, zastavanaPlocha);
	//		obec->getBytovaJednotka()->setBytovaJednotka((*nacitaneInformaciePreBJ)[indexArrayListu]);


	//		//


	//		slovensko->pridajObec(obec, nazovOkresu, nazovKraja);
	//		indexArrayListu++;
	//	}

	//	for (ArrayList<int>* arrayList : *nacitaneInformaciePreBJ) {
	//		delete arrayList;
	//	}
	//	delete nacitaneInformaciePreBJ;

	//}


	
	ArrayList<ArrayList<int>*>* nacitajBytoveJednotky() {

		ArrayList<ArrayList<int>*>* vystup = new ArrayList <ArrayList<int>*>();
		(*vystup).add(new ArrayList<int>());

		std::wifstream citacBytoveJednotky;

		citacBytoveJednotky.imbue(std::locale("Slovak"));
		citacBytoveJednotky.open("4 Bytové jednotky SR.csv");


		std::wstring riadokBJ;




		int indexArrayListu = 0;
		int pocetNacitanych = 0;

		int riadok = 0;

		std::getline(citacBytoveJednotky, riadokBJ);

		while (std::getline(citacBytoveJednotky, riadokBJ)) {
			std::wstringstream bunkovac(riadokBJ);
			std::wstring rozkuskovanyRiadok[BJ_SUBOR_STLPCOV];


			for (int i = 0; i < BJ_SUBOR_STLPCOV; i++) {
				std::getline(bunkovac, rozkuskovanyRiadok[i], L';');
			}

			for (int i = 3; i < 13; i++) {
				(*vystup)[indexArrayListu]->add(std::stoi(rozkuskovanyRiadok[i]));
			}

			pocetNacitanych++;
			if (pocetNacitanych == (POCET_TYPOV * POCET_OSOB)) {
				pocetNacitanych = 0;
				vystup->add(new ArrayList<int>());
				indexArrayListu++;
			}
			/*if (riadok % 100 == 0) {
				std::wcout << riadok << "\n";
			}*/
			//std::wcout << std::to_wstring(riadok) << "\n";
			riadok++;
		}

		return vystup;
	}

	void nacitajUzemneJednotky() {
		std::wifstream citacObce1;
		std::wifstream citacObce2;

		citacObce1.imbue(std::locale("Slovak"));
		citacObce2.imbue(std::locale("Slovak"));
		citacObce1.open("1 Obce SR.csv");
		citacObce2.open("2 Územné èlenenie SR.csv");


		std::wstring riadokObce1;
		std::wstring riadokObce2;



		Array<int>* pole = this->nacitajBJAkoInt();

		int indexUzemnejJednotky = 0;
		//nazov - string
		//preproduktivni int
		//produktivni int
		//poproduktivni int
		//celkova vymera double
		//zastavana plocha double
		std::getline(citacObce1, riadokObce1);
		std::getline(citacObce2, riadokObce2);


		 
		while (std::getline(citacObce1, riadokObce1)) {
			std::wstringstream bunkovac(riadokObce1);
			std::wstring rozkuskovanyRiadok[6];


			for (int i = 0; i < 6; i++) {
				std::getline(bunkovac, rozkuskovanyRiadok[i], L';');
			}

			std::wstring nazovObce = rozkuskovanyRiadok[0];
			int pocetPreproduktivnych = std::stoi(rozkuskovanyRiadok[1]);
			int pocetProduktivnych = std::stoi(rozkuskovanyRiadok[2]);
			int pocetPoproduktivnych = std::stoi(rozkuskovanyRiadok[3]);
			double celkovaVymera = std::stod(rozkuskovanyRiadok[4]);
			double zastavanaPlocha = std::stod(rozkuskovanyRiadok[5]);



			std::getline(citacObce2, riadokObce2);
			std::wstringstream bunkovac2(riadokObce2);
			std::wstring rozkuskovanyRiadok2[3];

			for (int i = 0; i < 3; i++) {
				std::getline(bunkovac2, rozkuskovanyRiadok2[i], L';');
			}
			std::wstring nazovOkresu = rozkuskovanyRiadok2[1];
			std::wstring nazovKraja = rozkuskovanyRiadok2[2];
			

			ObecUzemnaJednotka* obec = new ObecUzemnaJednotka(nazovObce, pocetPreproduktivnych, pocetProduktivnych, pocetPoproduktivnych, celkovaVymera, zastavanaPlocha);
			obec->getBytovaJednotka()->setBytovaJednotka(pole, indexUzemnejJednotky* POCET_TYPOV * POCET_OSOB * POCET_OBYTNYCH_MIESTNOSTI);


			//


			slovensko->pridajObec(obec, nazovOkresu, nazovKraja);
			indexUzemnejJednotky++;
		}

		delete pole;

	}


	Array<int>* nacitajBJAkoInt() {

		Array<int>* vrat = new Array<int>(POCET_TYPOV * POCET_OSOB * POCET_OBYTNYCH_MIESTNOSTI * 2926);

		std::wifstream citacBytoveJednotky;

		citacBytoveJednotky.imbue(std::locale("Slovak"));
		citacBytoveJednotky.open("4 Bytové jednotky SR.csv");


		std::wstring riadokBJ;




		int indexArrayListu = 0;
		int pocetNacitanych = 0;

		int riadok = 0;

		std::getline(citacBytoveJednotky, riadokBJ);

		while (std::getline(citacBytoveJednotky, riadokBJ)) {
			std::wstringstream bunkovac(riadokBJ);
			std::wstring rozkuskovanyRiadok[BJ_SUBOR_STLPCOV];


			for (int i = 0; i < BJ_SUBOR_STLPCOV; i++) {
				std::getline(bunkovac, rozkuskovanyRiadok[i], L';');
			}

			for (int i = 3; i < 13; i++) {
				
				(*vrat)[riadok] = std::stoi(rozkuskovanyRiadok[i]);
				riadok++;
			}
			//std::wcout << riadok << "\n";
			
			/*if (riadok % 100 == 0) {
				std::wcout << riadok << "\n";
			}*/
			//std::wcout << std::to_wstring(riadok) << "\n";
			
		}

		return vrat;
	}


};

