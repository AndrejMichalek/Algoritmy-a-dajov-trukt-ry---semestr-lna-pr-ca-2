#pragma once
#include"array_list.h"
#include"BytovaJednotka.h"
#include<iostream>
#include"KriteriumBJPocetSVlastnostami.h"
#include"CitacZKlavesnice.h"
class FormatovacFiltraBytovaJednotka
{
public:
	KriteriumBJPocetSVlastnostami* dajMiKriteriumBJPocetSVlastnostami() {
		TybBytovejJednotky typ;
		int pocetOsobMin = -1; 
		int pocetOsobMax = -1; 
		int pocetIziebMin = -1;
		int pocetIziebMax = -1;

		this->nacitajVstupOdUzivatela(typ, pocetOsobMin, pocetOsobMax, pocetIziebMin, pocetIziebMax);
		KriteriumBJPocetSVlastnostami* kriterium = new KriteriumBJPocetSVlastnostami(typ, pocetOsobMin, pocetOsobMax, pocetIziebMin, pocetIziebMax);
		return kriterium;
	}


private:
	void nacitajVstupOdUzivatela(TybBytovejJednotky& typ, int& pocetOsobMin, int& pocetOsobMax, int& pocetIziebMin, int& pocetIziebMax) {
		
		std::wcout << L"Tento filter umo��uje filtrova� bytov� jednotky pod�a typu.\n";
		bool aplikovatFilterTyp = this->prajeteSiHoAplikovat();
		if (aplikovatFilterTyp) {
			uplatniFilterBJTyp(typ);
		}
		else {
			typ = NEDEFINOVANY;
		}

		std::wcout << L"Tento filter umo��uje filtrova� bytov� jednotky pod�a po�tu os�b.\n";
		bool aplikovatFilterPocetOsob = this->prajeteSiHoAplikovat();
		if (aplikovatFilterPocetOsob) {
			uplatniFilterBJPocetOsob(pocetOsobMin, pocetOsobMax);
		}
		else {
			pocetOsobMin = -1;
			pocetOsobMax = -1;
		}

		std::wcout << L"Tento filter umo��uje filtrova� bytov� jednotky pod�a po�tu obytn�ch miestnost�.\n";
		bool aplikovatFilterPocetIzieb = this->prajeteSiHoAplikovat();
		if (aplikovatFilterPocetIzieb) {
			uplatniFilterBJPocetIzieb(pocetIziebMin, pocetIziebMax);
		}
		else {
			pocetIziebMin = -1;
			pocetIziebMax = -1;
		}

	}

	void uplatniFilterBJPocetOsob(int& pocetOsobMin, int& pocetOsobMax) {
		bool podariloSaNacitat = false;
		int min = 0;
		int max = 0;
		while (!podariloSaNacitat) {
			std::wstring vstup;
			std::wcout << L"Zvo�te minim�lny po�et os�b.\n";
			this->vypytajOdUzivatelaPocetOsob(min);
			std::wcout << L"Zvo�te maxim�lny po�et os�b.\n";
			this->vypytajOdUzivatelaPocetOsob(max);
			if (min <= max) {
				podariloSaNacitat = true;
			}
			else {
				std::wcout << L"Doln� hranica mus� by� men�ia alebo rovnak� ako doln�.\n";
				std::wcout << L"Vy ste zadali interval: <." << std::to_wstring(min) << L"," <<
					std::to_wstring(max) <<L"\n";
			}
		}
		pocetOsobMin = min;
		pocetOsobMax = max;
	}

	void vypytajOdUzivatelaPocetOsob(int& pocet) {
		std::wstring vstup;
		std::wcout << L"Ak zad�te po�et in� ako 1-10, bude pova�ovan� za 11 a viac os�b.\n";
		vstup = CitacZKlavesnice::citajString();
		if (vstup != L"1" && vstup != L"2" && vstup != L"3" && vstup != L"4" && vstup != L"5"
			&& vstup != L"6" && vstup != L"7" && vstup != L"8" && vstup != L"9" && vstup != L"10")
		{
			pocet = 11;
		}
		else {
			pocet = std::stoi(vstup);
		}
	}
	void uplatniFilterBJPocetIzieb(int& pocetIziebMin, int& pocetIziebMax) {
		bool podariloSaNacitat = false;
		int min = 0;
		int max = 0;
		while (!podariloSaNacitat) {
			std::wstring vstup;
			std::wcout << L"Zvo�te minim�lny po�et izieb.\n";
			this->vypytajOdUzivatelaPocetIzieb(min);
			std::wcout << L"Zvo�te maxim�lny po�et izieb.\n";
			this->vypytajOdUzivatelaPocetIzieb(max);
			if (min <= max) {
				podariloSaNacitat = true;
			}
		}
		pocetIziebMin = min;
		pocetIziebMax = max;
	}

	void vypytajOdUzivatelaPocetIzieb(int& pocet) {
		std::wstring vstup;
		std::wcout << L"Ak zad�te po�et in� ako 1-9, bude pova�ovan� za nezisten�.\n";
		vstup = CitacZKlavesnice::citajString();
		if (vstup != L"1" && vstup != L"2" && vstup != L"3" && vstup != L"4" && vstup != L"5"
			&& vstup != L"6" && vstup != L"7" && vstup != L"8" && vstup != L"9")
		{
			pocet = 10;
		}
		else {
			pocet = std::stoi(vstup);
		}
	}

	void uplatniFilterBJTyp(TybBytovejJednotky& typ) {
		std::wstring volba;
		std::wcout << "Vyberte si typ: \n";
		for (int i = 0; i < BytovaJednotka::getMaxPocetTypov(); i++) {
			std::wcout << L"[" << std::to_wstring(i) << L"] " << BytovaJednotka::dajMiStringTypuZIndexuTypu(i) << L"\n";
		}
		volba = CitacZKlavesnice::citajString();
		int indexTypu = 0;
		if (volba != L"0" && volba != L"1" && volba != L"2" && volba != L"3" && volba != L"4"
			&& volba != L"5") {
			indexTypu = 5;
		}
		else {
			indexTypu = std::stoi(volba);
		}
		typ = BytovaJednotka::dajMiTypZIntu(indexTypu);
	}


	bool prajeteSiHoAplikovat() {
		std::wstring volba;
		std::wcout << L"Prajete si ho aplikova�?.\n";
		std::wcout << L"[1] �no\n";
		std::wcout << L"[?] Nie\n";
		volba = CitacZKlavesnice::citajString();
		if (volba == L"1") {
			return true;
		}
		else {
			return false;
		}
	}

};

