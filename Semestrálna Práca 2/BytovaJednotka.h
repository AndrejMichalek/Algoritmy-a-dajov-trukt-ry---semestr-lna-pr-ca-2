//#pragma once
//#include<string>
//#include"sorted_sequence_table.h"
//#include"array.h"
//
//
//#define POCET_TYPOV 5
//#define POCET_OSOB 11
//#define OBYTNE_MIESTNOSTI_POCET 10
//
//
//enum TybBytovejJednotky {
//	BYTY_V_BUDOVACH_S_JEDNYM_BYTOM,
//	BYTY_V_BUDOVACH_S_DVOMA_BYTMI,
//	BYTY_V_BUDOVACH_S_TROMA_ALEBO_VIAC_BYTMI,
//	BYTY_V_NEBYTOVYCH_BUDOVACH,
//	NEZISTENE
//};
//
//class BytovaJednotkaUrovenTyp;
////----------------------------------------------------------------------------------------------------------------------
//class BytovaJednotka
//{
//
//
//private:
//	Array<BytovaJednotkaUrovenTyp*>* typy;
//	
//
//public:
//	BytovaJednotka() {
//		this->typy = new Array<BytovaJednotkaUrovenTyp*>(POCET_TYPOV);
//
//		TybBytovejJednotky typ[POCET_TYPOV];
//		typ[0] = BYTY_V_BUDOVACH_S_JEDNYM_BYTOM;
//		typ[1] = BYTY_V_BUDOVACH_S_DVOMA_BYTMI;
//		typ[2] = BYTY_V_BUDOVACH_S_TROMA_ALEBO_VIAC_BYTMI;
//		typ[3] = BYTY_V_NEBYTOVYCH_BUDOVACH;
//		typ[4] = NEZISTENE;
//
//		for (int i = 0; i < POCET_TYPOV; i++) {
//			(*typy)[i] = new BytovaJednotkaUrovenTyp(typ[i]);
//		}
//	}
//	~BytovaJednotka() {
//		for (int i = 0; i < POCET_TYPOV; i++) {
//			delete (*typy)[i];
//		}
//		delete this->typy;
//	}
//
//	void zaradUdaje(std::wstring typ, int pocetOsob, int* obytnaMiestnostPocet, bool zvysTrueNastavFalse) {
//		
//		if (typ == L"Byty v budovách s jedným bytom") {
//			(*this->typy)[0]->zaradUdaje(pocetOsob, obytnaMiestnostPocet, zvysTrueNastavFalse);
//		}
//		else if (typ == L"Byty v budovách s dvoma bytmi") {
//			(*this->typy)[1]->zaradUdaje(pocetOsob, obytnaMiestnostPocet, zvysTrueNastavFalse);
//		}
//		else if (typ == L"Byty v budovách s troma alebo viac bytmi") {
//			(*this->typy)[2]->zaradUdaje(pocetOsob, obytnaMiestnostPocet, zvysTrueNastavFalse);
//		}
//		else if (typ == L"Byty v nebytových budovách") {
//			(*this->typy)[3]->zaradUdaje(pocetOsob, obytnaMiestnostPocet, zvysTrueNastavFalse);
//		}
//		else {
//			(*this->typy)[4]->zaradUdaje(pocetOsob, obytnaMiestnostPocet, zvysTrueNastavFalse);
//		}
//
//	}
//
//	int getZoskupeniePocet(std::wstring typ, int pocetOsob, int pocetObytnychMiestnosti) {
//		if (typ == L"Byty v budovách s jedným bytom") {
//			return (*this->typy)[0]->getPocet(pocetOsob, pocetObytnychMiestnosti);
//		}
//		else if (typ == L"Byty v budovách s dvoma bytmi") {
//			return (*this->typy)[1]->getPocet(pocetOsob, pocetObytnychMiestnosti);
//		}
//		else if (typ == L"Byty v budovách s troma alebo viac bytmi") {
//			return (*this->typy)[2]->getPocet(pocetOsob, pocetObytnychMiestnosti);
//		}
//		else if (typ == L"Byty v nebytových budovách") {
//			return (*this->typy)[3]->getPocet(pocetOsob, pocetObytnychMiestnosti);
//		}
//		else {
//			return (*this->typy)[4]->getPocet(pocetOsob, pocetObytnychMiestnosti);
//		}
//	}
//
//	void zvys(BytovaJednotka* bj) {
//		for (int k = 0; k < POCET_TYPOV; k++) {
//			BytovaJednotkaUrovenTyp* bjtyp = (*this->typy)[k];
//			Array<BytovaJednotkaUrovenPocetOsob*>* urovenPocetOsob = bjtyp->getUrovenPocetOsob();
//			for (int i = 0; i < POCET_OSOB; i++) {
//				BytovaJednotkaUrovenPocetOsob* zoskupenieBJ = (*urovenPocetOsob)[i]->getUrovenZoskupenieBytovaJednotka();
//				for (int j = 0; j < OBYTNE_MIESTNOSTI_POCET; j++) {
//					ZoskupenieBytovaJednotka* konkretna = (*zoskupenieBJ)[j];
//					konkretna->setPocet(bj->getZoskupeniePocet(konkretna->getTyp(), konkretna->pocetOsobVBytovejJednotke(), konkretna->getPocetIzieb()));
//				}
//			}
//		}
//	}
//
//	
//};
//
//class BytovaJednotkaUrovenTyp {
//
//
//
//
//	Array<BytovaJednotkaUrovenPocetOsob*>* urovenPocetOsob;
//
//	TybBytovejJednotky typ;
//
//
//public:
//	BytovaJednotkaUrovenTyp(TybBytovejJednotky typ) {
//		urovenPocetOsob = new Array<BytovaJednotkaUrovenPocetOsob*>(POCET_OSOB);
//		this->typ = typ;
//
//		int pocetOsob = 1;
//		for (int i = 0; i < POCET_OSOB; i++) {
//			(*this->urovenPocetOsob)[i] = new BytovaJednotkaUrovenPocetOsob(pocetOsob, this);
//			pocetOsob++;
//		}
//	}
//
//	~BytovaJednotkaUrovenTyp() {
//		for (int i = 0; i < POCET_OSOB; i++) {
//			delete (*this->urovenPocetOsob)[i];
//		}
//		delete this->urovenPocetOsob;
//	}
//
//	void zaradUdaje(int pocetOsob, int* obytnaMiestnostPocet, bool zvysTrueNastavFalse) {
//		(*this->urovenPocetOsob)[pocetOsob - 1]->zaradUdaje(obytnaMiestnostPocet, zvysTrueNastavFalse);
//	}
//
//	int getPocet(int pocetOsob, int pocetObytnychMiestnosti) {
//		return (*urovenPocetOsob)[pocetOsob - 1]->getPocet(pocetObytnychMiestnosti);
//	}
//
//	Array<BytovaJednotkaUrovenPocetOsob*>* getUrovenPocetOsob() {
//		return this->urovenPocetOsob;
//	}
//
//	TybBytovejJednotky getTyp() {
//		return this->typ;
//	}
//
//	void setTyp(TybBytovejJednotky typ) {
//		this->typ = typ;
//	}
//};
//
//class ZoskupenieBytovaJednotka {
//
//
//	BytovaJednotkaUrovenPocetOsob* urovenPocetOsob;
//	int pocet;
//	int pocetIzieb;
//
//
//public:
//	ZoskupenieBytovaJednotka(int pocet, int pocetIzieb, BytovaJednotkaUrovenPocetOsob* urovenPocetOsob) {
//		this->pocet = pocet;
//		this->urovenPocetOsob = urovenPocetOsob;
//		this->pocetIzieb = pocetIzieb;
//	}
//	void zvysPocet(int pocet) {
//		this->pocet += pocet;
//	}
//
//	void setPocet(int pocet) {
//		this->pocet += pocet;
//	}
//
//
//	std::wstring getTyp() {
//
//		TybBytovejJednotky typ = urovenPocetOsob->getUrovenTyp()->getTyp();
//		switch (typ) {
//		case BYTY_V_BUDOVACH_S_JEDNYM_BYTOM: return L"Byty v budovách s jedným bytom";
//			break;
//		case BYTY_V_BUDOVACH_S_DVOMA_BYTMI: return L"Byty v budovách s dvoma bytmi";
//			break;
//		case BYTY_V_BUDOVACH_S_TROMA_ALEBO_VIAC_BYTMI: return L"Byty v budovách s troma alebo viacerými bytmi";
//			break;
//		case BYTY_V_NEBYTOVYCH_BUDOVACH: return L"Byty v nebytových budovách";
//			break;
//		case NEZISTENE: return L"Nezistene";
//			break;
//		}
//	}
//
//	int pocetOsobVBytovejJednotke() {
//		return this->urovenPocetOsob->getPocetOsob();
//	}
//
//	int getPocetIzieb() {
//		return this->pocetIzieb;
//	}
//
//	int getPocet() {
//		return this->pocet;
//	}
//};
//
//class BytovaJednotkaUrovenPocetOsob {
//
//
//
//
//private:
//	int pocetOsob;
//	BytovaJednotkaUrovenTyp* urovenTyp;
//	Array<ZoskupenieBytovaJednotka*>* urovenZoskupenieBJ;
//
//
//public:
//	BytovaJednotkaUrovenPocetOsob(int pocetOsob, BytovaJednotkaUrovenTyp* urovenTyp) {
//		this->urovenZoskupenieBJ = new Array<ZoskupenieBytovaJednotka*>(OBYTNE_MIESTNOSTI_POCET);
//		this->pocetOsob = pocetOsob;
//		this->urovenTyp = urovenTyp;
//		int pocetIzieb = 1;
//		for (int i = 0; i < OBYTNE_MIESTNOSTI_POCET; i++) {
//			(*urovenZoskupenieBJ)[i] = new ZoskupenieBytovaJednotka(0, pocetIzieb, this);
//			pocetIzieb++;
//		}
//	}
//
//	~BytovaJednotkaUrovenPocetOsob() {
//		for (int i = 0; i < OBYTNE_MIESTNOSTI_POCET; i++) {
//			delete (*urovenZoskupenieBJ)[i];
//
//		}
//		delete this->urovenZoskupenieBJ;
//
//	}
//	int getPocet(int pocetMiestnosti) {
//		return (*urovenZoskupenieBJ)[pocetMiestnosti - 1]->getPocet();
//	}
//
//	void zaradUdaje(int* obytnaMiestnostPocet, bool zvysTrueNastavFalse) {
//
//		for (int i = 0; i < OBYTNE_MIESTNOSTI_POCET; i++) {
//			if (zvysTrueNastavFalse) {
//				(*this->urovenZoskupenieBJ)[i]->zvysPocet(obytnaMiestnostPocet[i]);
//			}
//			else {
//				(*this->urovenZoskupenieBJ)[i]->setPocet(obytnaMiestnostPocet[i]);
//			}
//
//		}
//	}
//
//	Array<ZoskupenieBytovaJednotka*>* getUrovenZoskupenieBytovaJednotka() {
//		return this->urovenZoskupenieBJ;
//	}
//
//	BytovaJednotkaUrovenTyp* getUrovenTyp() {
//		return this->urovenTyp;
//	}
//
//	int getPocetOsob() {
//		return this->pocetOsob;
//	}
//};