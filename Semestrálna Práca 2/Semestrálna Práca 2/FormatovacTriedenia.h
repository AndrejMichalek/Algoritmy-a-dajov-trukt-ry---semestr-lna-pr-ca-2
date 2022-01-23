#pragma once
#include"Triedenie.h"
#include<iostream>
#include"CitacZKlavesnice.h"
template <typename T, typename O, typename K>
class FormatovacTriedenia
{
public:
	void tried(UnsortedSequenceTable<K, O*>* tabulka, Kriterium<T, O>* kriterium) {
		bool vzostupne;
		std::wcout << L"Zadajte, èi chcete triedi vzostupne alebo zostupne\n";
		std::wcout << L"[1] vzostupne\n";
		std::wcout << L"[?] zostupne\n";

		std::wstring vstup;
		/*std::wcin.ignore();
		std::getline(std::wcin, vstup);*/
		//std::wcin >> vstup;
		vstup = CitacZKlavesnice::citajString();
		//std::getline(std::wcin, vstup);
		if (vstup == L"1") {
			vzostupne = true;
		}
		else {
			vzostupne = false;
		}
		Triedenie<T, O, K> triedenie;
		triedenie.tried(tabulka, kriterium, vzostupne);
	}

};

