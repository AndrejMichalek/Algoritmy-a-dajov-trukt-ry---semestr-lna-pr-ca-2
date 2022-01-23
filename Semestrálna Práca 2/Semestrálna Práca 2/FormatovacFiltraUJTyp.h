#pragma once
#include"StatUzemnaJednotka.h"
#include"CitacZKlavesnice.h"

#include<iostream>
#include<io.h>
#include<fcntl.h>
class FormatovacFiltraUJTyp
{
public:
	Table<std::wstring, UzemnaJednotka*>& dajMiVhodnuTabulku(StatUzemnaJednotka* slovensko, bool& trebaMazatTabulku, bool utriedena) {
		
		do {
			trebaMazatTabulku = false;
			std::wstring volba = L"0";
			std::wcout << L"Ktory typ uzemnej jednotky potrebujete?\n";
			std::wcout << L"[1] Obce\n";
			std::wcout << L"[2] Kraje\n";
			std::wcout << L"[3] Okresy\n";
			std::wcout << L"[4] Slovensko\n";
			std::wcout << L"[5] Neaplikuj, chcem vidiet vsetko\n";
			//std::wcin >> volba;
			//std::getline(std::wcin, volba);

			volba = CitacZKlavesnice::citajString();
			if (volba == L"1") {
				if (utriedena == true) {
					return slovensko->getSortedObce();
				}
				else {
					return slovensko->getObce();
				}
				
			}
			else if (volba == L"2") {
				if (utriedena == true) {
					return slovensko->getSortedKraje();
				}
				else {
					return slovensko->getKraje();
				}
				
			}
			else if (volba == L"3") {
				if (utriedena == true) {
					return slovensko->getSortedOkresy();
				}
				else {
					return slovensko->getOkresy();
				}
				
			}
			else if (volba == L"4") {
				trebaMazatTabulku = true;
				if (utriedena == true) {
					SortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulka =
						new SortedSequenceTable<std::wstring, UzemnaJednotka*>();
					tabulka->insert(slovensko->getNazov(), slovensko);
					return *tabulka;
				}
				else {
					UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulka =
						new UnsortedSequenceTable<std::wstring, UzemnaJednotka*>();
					tabulka->insert(slovensko->getNazov(), slovensko);
					return *tabulka;
				}
			}
			else if(volba == L"5") {
				trebaMazatTabulku = true;
				Table<std::wstring, UzemnaJednotka*>* tabulka;
				if (utriedena == true) {
					tabulka = new SortedSequenceTable<std::wstring, UzemnaJednotka*>();
				}
				else {
					tabulka = new UnsortedSequenceTable<std::wstring, UzemnaJednotka*>();
				}

				UnsortedSequenceTable<std::wstring, UzemnaJednotka*>& obce = slovensko->getObce();
				for (TableItem<std::wstring, UzemnaJednotka*>* itema : obce) {
					tabulka->insert(itema->getKey(), itema->accessData());
				}
				UnsortedSequenceTable<std::wstring, UzemnaJednotka*>& okresy = slovensko->getOkresy();
				for (TableItem<std::wstring, UzemnaJednotka*>* itema : okresy) {
					tabulka->insert(itema->getKey(), itema->accessData());
				}
				UnsortedSequenceTable<std::wstring, UzemnaJednotka*>& kraje = slovensko->getKraje();
				for (TableItem<std::wstring, UzemnaJednotka*>* itema : kraje) {
					tabulka->insert(itema->getKey(), itema->accessData());
				}
				return *tabulka;
			}
			else {
				std::wcout << L"Zadali ste nespravnu moznost, prosim opakujte svoju volbu\n";
			}
		} while (true);
	}
};

