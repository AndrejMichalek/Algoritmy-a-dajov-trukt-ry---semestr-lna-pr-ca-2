#pragma once
#include"FormatovacFiltra.h"
#include"UzemnaJednotka.h"
#include"KriteriumUJPrislusnost.h"
#include<iostream>
#include"FilterPodlaHodnoty.h"

class FormatovacFiltraPrislusnost : public FormatovacFiltra<UzemnaJednotka, bool> 
{
	virtual Filter<bool, UzemnaJednotka>* vytvorFilter() override {
		
		std::wstring nazov;
		std::wcout << L"Zadajte nazov vyssej uzemnej jednotky.";
		
		//std::wcin >> nazov;
		//std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//std::getline(std::wcin, nazov);
		nazov = CitacZKlavesnice::citajString();

		std::wcout << L"Prislusnost : " << nazov << L"\n";
		//std::wcin.ignore();
		//std::getline(std::wcin, nazov);


		KriteriumUJPrislusnost* kriterium = new KriteriumUJPrislusnost(nazov);

		FilterPodlaHodnoty<bool, UzemnaJednotka>* filter = new FilterPodlaHodnoty<bool, UzemnaJednotka>(true, kriterium);
		return filter;
	}

	virtual void vypisInformacieOFiltri() override {
		std::wcout << L"Tento filter umožòuje filtrova územné jednotky pod¾a príslušnosti ku vyššej jednotke.\n";
	}
};

