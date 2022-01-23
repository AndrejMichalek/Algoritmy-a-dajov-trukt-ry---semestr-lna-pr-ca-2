#pragma once
#include"FormatovacFiltra.h"
#include"UzemnaJednotka.h"
#include"FilterPodlaHodnoty.h"
#include"KriteriumUJNazov.h"
#include<iostream>
#include<limits>
class FormatovacFiltraUJNazov
{
public:
	SortedSequenceTable<std::wstring, UzemnaJednotka*>* uplatniFilter(SortedSequenceTable<std::wstring, UzemnaJednotka*>* vstupnaTabulka, bool& aplikovalSaFilter) {
		std::wstring volba;
		this->vypisInformacieOFiltri();
		std::wcout << L"Prajete si aplikovat tento filter?\n";
		std::wcout << L"[1] Ano?\n";
		std::wcout << L"[?] Nie?\n";
		std::wcin >> volba;
		if (volba == L"1") {
			std::wstring nazov;
			std::wcout << L"Zadajte nazov uzemnej jednotky.";
			/*std::wcin.ignore();
			std::getline(std::wcin, nazov);*/

			//std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//std::getline(std::wcin, nazov); 
			//std::wcin >> nazov;

			nazov = CitacZKlavesnice::citajString();

			std::wcout << L"Nazov : " << nazov << L"\n";

			aplikovalSaFilter = true;
			SortedSequenceTable<std::wstring, UzemnaJednotka*>* tabulkaVrat = new SortedSequenceTable<std::wstring, UzemnaJednotka*>();
			UzemnaJednotka* pridaj = nullptr;

			bool podariloSaNajst = vstupnaTabulka->tryFind(nazov, pridaj);
			if (!podariloSaNajst) {
				return tabulkaVrat;
			}
			else {
				tabulkaVrat->insert(pridaj->getNazov(), pridaj);
				return tabulkaVrat;
			}
		}
		else {
			aplikovalSaFilter = false;
			return vstupnaTabulka;
		}
	}
private:
	void vypisInformacieOFiltri()  {
		std::wcout << L"Tento filter umoznuje odfiltrovat data podla nazvu.\n";
	}
};

