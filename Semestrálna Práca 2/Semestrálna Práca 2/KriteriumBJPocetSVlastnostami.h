#pragma once
#include"KriteriumBJ.h"
#include"TypBytovejJednotky.h"
#include<iostream>
class KriteriumBJPocetSVlastnostami : public KriteriumBJ<int>
{
	TybBytovejJednotky typ;
	int pocetOsobMin;
	int pocetOsobMax;
	int pocetIziebMin; 
	int pocetIziebMax;

public:
	KriteriumBJPocetSVlastnostami(TybBytovejJednotky typ, int pocetOsobMin, int pocetOsobMax, int pocetIziebMin, int pocetIziebMax) {
		this->typ = typ;
		this->pocetOsobMin = pocetOsobMin;
		this->pocetOsobMax = pocetOsobMax;
		this->pocetIziebMin = pocetIziebMin;
		this->pocetIziebMax = pocetIziebMax;

		

		std::wcout << L"Bolo vytvorene kriterium:\n";
		std::wcout << L"Typ: \n" << BytovaJednotka::dajMiStringZTypu(typ) << L"\n";
		std::wcout << L"pocetOsobMin:\n" << std::to_wstring(pocetOsobMin) << L"\n";
		std::wcout << L"pocetOsobMax:\n" << std::to_wstring(pocetOsobMax) << L"\n";
		std::wcout << L"pocetiziebMin:\n" << std::to_wstring(pocetIziebMin) << L"\n";
		std::wcout << L"pocetiziebMax:\n" << std::to_wstring(pocetIziebMax) << L"\n";
		

	}

	int ohodnot(BytovaJednotka& omega) override {
		return omega.dajMiSumarnyPocetZoskupeniSplnajucichFilter(typ, pocetOsobMin, pocetOsobMax, pocetIziebMin, pocetIziebMax);
	}
};

