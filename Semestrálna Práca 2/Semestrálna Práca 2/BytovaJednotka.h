#pragma once
#define POCET_TYPOV 5
#define POCET_OSOB 11
#define POCET_OBYTNYCH_MIESTNOSTI 10
#include"TypBytovejJednotky.h"
#include"ZoskupenieBytovychJednotiek.h"
#include<string>
#include"array_list.h"



class BytovaJednotka
{
private:
	int pocet;
	int zoskupeniaBJ[POCET_TYPOV * POCET_OSOB * POCET_OBYTNYCH_MIESTNOSTI];

public:

	/*void setBytovaJednotka(ArrayList<int>* vsetkyZoskupeniaBJ) {
		if (vsetkyZoskupeniaBJ->size() == POCET_TYPOV * POCET_OSOB * POCET_OBYTNYCH_MIESTNOSTI) {
			for (int i = 0; i < POCET_TYPOV * POCET_OSOB * POCET_OBYTNYCH_MIESTNOSTI; i++) {
				zoskupeniaBJ[i] = (*vsetkyZoskupeniaBJ)[i];
			}
		}
		else {
			throw std::logic_error("Taketo udaje sa nedaju do BytovejJednotky ulozit");
		}
	}*/
	void setBytovaJednotka(Array<int>* pole, int index) {
		this->pocet = 0;
			for (int i = 0; i < POCET_TYPOV * POCET_OSOB * POCET_OBYTNYCH_MIESTNOSTI; i++) {
				zoskupeniaBJ[i] = (*pole)[i + index];
				this->pocet += (*pole)[i + index];
				
			}
		
	}
	int getSumarnyPocetVsetkychZoskupeni() {
		return this->pocet;
	}



	static int dajMiIndexPrvkuSVlastnostami(TybBytovejJednotky typ, int pocetOsob, int pocetObytnychMiestnosti) {

		int index = 0;
		int odskokTyp = POCET_OSOB * POCET_OBYTNYCH_MIESTNOSTI;
		index = odskokTyp * typ;

		index = index +(pocetOsob - 1) * POCET_OBYTNYCH_MIESTNOSTI;
		index = index + pocetObytnychMiestnosti - 1;
		return index;
	}
	void nastavPocetZoskupeniuBJ(TybBytovejJednotky typ, int pocetOsob, int pocetObytnychMiestnosti, int pocetZoskupeniDanehoTypu) {
		int index = this->dajMiIndexPrvkuSVlastnostami(typ, pocetOsob, pocetObytnychMiestnosti);
		pocet = pocet - this->zoskupeniaBJ[index] + pocetZoskupeniDanehoTypu;
		this->zoskupeniaBJ[index] = pocetZoskupeniDanehoTypu;
	}
	int dajPocetZoskupeniaBJ(TybBytovejJednotky typ, int pocetOsob, int pocetObytnychMiestnosti) {
		int index = this->dajMiIndexPrvkuSVlastnostami(typ, pocetOsob, pocetObytnychMiestnosti);
		return this->zoskupeniaBJ[index];
	}
	




	void pripocitaj(BytovaJednotka* vstup) {
		for (int i = 0; i < POCET_TYPOV * POCET_OSOB * POCET_OBYTNYCH_MIESTNOSTI; i++) {
			this->zoskupeniaBJ[i] = this->zoskupeniaBJ[i] + vstup->zoskupeniaBJ[i];
		}
	}


	static ArrayList<int>* dajMiZoskupeniaSplnajuceFilter(TybBytovejJednotky typ, int pocetOsobMin, int pocetOsobMax, int pocetIziebMin, int pocetIziebMax) {
		int typDolnaHranica = 0;
		int typHornaHranica = POCET_TYPOV-1;

		int pocetOsobDolnaHranica = 1;
		int pocetOsobHornaHranica = POCET_OSOB;

		int pocetIziebDolnaHranica = 1;
		int pocetIziebHornaHranica = POCET_OBYTNYCH_MIESTNOSTI;


		if (typ != NEDEFINOVANY) {
			typDolnaHranica = typ;
			typHornaHranica = typ;
		} 
		if (pocetOsobMin != -1) {
			pocetOsobDolnaHranica = pocetOsobMin;
			pocetOsobHornaHranica = pocetOsobMax;
		}
		if (pocetIziebMin != -1) {
			pocetIziebDolnaHranica = pocetIziebMin;
			pocetIziebHornaHranica = pocetIziebMax;
		}
		ArrayList<int>* indexyZoskupeniSplnajucichFilter = new ArrayList <int>();
		
		
		for (int i = typDolnaHranica; i < typHornaHranica; i++) {
			for (int j = pocetOsobDolnaHranica; j < pocetOsobHornaHranica; j++) {
				for (int k = pocetIziebDolnaHranica; k < pocetIziebHornaHranica; k++) {

					int indexVPoli = dajMiIndexPrvkuSVlastnostami(dajMiTypZIntu(i), j, k);
					indexyZoskupeniSplnajucichFilter->add(indexVPoli);
				}
			}
		}
		return indexyZoskupeniSplnajucichFilter;
	}

	std::wstring dajMiTypJednotkySIndexom(int index) {
		return this->dajMiStringZTypu(this->dajMiTypZIntu(index / (POCET_OSOB * POCET_OBYTNYCH_MIESTNOSTI)));
	}
	int dajMiPocetOsobJednotkySIndexom(int index) {
		return (((index % (POCET_OBYTNYCH_MIESTNOSTI * POCET_OSOB)) / POCET_OSOB) + 1);
	}
	int dajMiPocetJednotiekSIndexom(int index) {
		return this->zoskupeniaBJ[index];
	}
	int dajMiPocetIziebJednotkySIndexom(int index) {
		return index % POCET_OBYTNYCH_MIESTNOSTI+1;
	}
	static std::wstring dajMiStringTypuZIndexuTypu(int index) {
		return dajMiStringZTypu(dajMiTypZIntu(index));
	}

	static std::wstring dajMiStringZTypu(TybBytovejJednotky typ) {
		switch (typ) {
		case BYTY_V_BUDOVACH_S_JEDNYM_BYTOM: 
			return L"Byty v budovách s jedným bytom";
			break;
		case BYTY_V_BUDOVACH_S_DVOMA_BYTMI:
			return L"Byty v budovách s dvoma bytmi";
			break;
		case BYTY_V_BUDOVACH_S_TROMA_ALEBO_VIAC_BYTMI:
			return L"Byty v budovách s troma alebo viac bytmi";
			break;
		case BYTY_V_NEBYTOVYCH_BUDOVACH:
			return L"Byty v nebytových budovách";
			break;
		case NEZISTENE:
			return L"Nezistené";
			break;
		default :
			return L"Nedefinované";
			break;
		

		}
	}

	static TybBytovejJednotky dajMiTypZIntu(int typ) {
		switch(typ) {
		case 0: return BYTY_V_BUDOVACH_S_JEDNYM_BYTOM;
			break;
		case 1: 
			return BYTY_V_BUDOVACH_S_DVOMA_BYTMI;
			break;
		case 2:
			return BYTY_V_BUDOVACH_S_TROMA_ALEBO_VIAC_BYTMI;
			break;
		case 3:
			return BYTY_V_NEBYTOVYCH_BUDOVACH;
			break;
		case 4:
			return NEZISTENE;
			break;
		default:
			return NEDEFINOVANY;
			break;
		
		
		}
	}



   
	int dajMiSumarnyPocetZoskupeniSplnajucichFilter(TybBytovejJednotky typ, int pocetOsobMin, int pocetOsobMax, int pocetIziebMin, int pocetIziebMax) {
		int typDolnaHranica = 0;
		int typHornaHranica = POCET_TYPOV - 1;

		int pocetOsobDolnaHranica = 1;
		int pocetOsobHornaHranica = POCET_OSOB;

		int pocetIziebDolnaHranica = 1;
		int pocetIziebHornaHranica = POCET_OBYTNYCH_MIESTNOSTI;


		if (typ != NEDEFINOVANY) {
			typDolnaHranica = typ;
			typHornaHranica = typ;
		}
		if (pocetOsobMin != -1) {
			pocetOsobDolnaHranica = pocetOsobMin;
			pocetOsobHornaHranica = pocetOsobMax;
		}
		if (pocetIziebMin != -1) {
			pocetIziebDolnaHranica = pocetIziebMin;
			pocetIziebHornaHranica = pocetIziebMax;
		}
		
		
		int sumarnyPocet = 0;

		for (int i = typDolnaHranica; i <= typHornaHranica; i++) {
			for (int j = pocetOsobDolnaHranica; j <= pocetOsobHornaHranica; j++) {
				for (int k = pocetIziebDolnaHranica; k <= pocetIziebHornaHranica; k++) {

					int indexVPoli = dajMiIndexPrvkuSVlastnostami(dajMiTypZIntu(i), j, k);
					sumarnyPocet += this->dajMiPocetJednotiekSIndexom(indexVPoli);
				}
			}
		}
		return sumarnyPocet;
	}

	


	std::wstring getRetazec() {
		std::wstring vrat = L"";
		for (int i = 0; i < POCET_TYPOV * POCET_OSOB * POCET_OBYTNYCH_MIESTNOSTI; i++) {
			if (i % 11 == 0) {
				vrat += L"\n";
			}
			vrat += std::to_wstring(zoskupeniaBJ[i]) + L", ";
			
		}
		return vrat;
	}

	

	/*void getHraniceTyp(std::wstring typ, int& dolna, int& horna) {
		int odskokTyp = POCET_OSOB * POCET_OBYTNYCH_MIESTNOSTI;
		if (typ == L"Byty v budovách s jedným bytom") {
			dolna = odskokTyp*0;
			horna = odskokTyp * 1 - 1;
		}
		else if (typ == L"Byty v budovách s dvoma bytmi") {
			dolna = odskokTyp * 1;
			horna = odskokTyp * 2 - 1;
		}
		else if (typ == L"Byty v budovách s troma alebo viac bytmi") {
			dolna = odskokTyp * 2;
			horna = odskokTyp * 3 - 1;
		}
		else if (typ == L"Byty v nebytových budovách") {
			dolna = odskokTyp * 3;
			horna = odskokTyp * 4 - 1;
		}
		else {
			dolna = odskokTyp * 4;
			horna = odskokTyp * 5 - 1;
		}
	}

	ArrayList<int>* getIndexyPocetObytnychMiestnosti(int dolna, int horna, int pocetMiestnosti) {
		ArrayList<int>* indexy = new ArrayList<int>();
		while (dolna <= horna) {
			if (dolna % pocetMiestnosti == 0) {
				indexy->add(dolna);
			}
			dolna++;
		}
	}*/
	static int getMaxPocetTypov() {
		return POCET_TYPOV;
	}
	static int getMaxPocetOsob() {
		return POCET_OSOB;
	}
	static int getMaxPocetObytnychMiestnosti() {
		return POCET_OBYTNYCH_MIESTNOSTI;
	}
};





