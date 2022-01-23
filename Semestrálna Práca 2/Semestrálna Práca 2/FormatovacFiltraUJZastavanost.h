#pragma once
#include"FilterPodlaIntervalu.h"
#include"UzemnaJednotka.h"
#include"KriteriumUJZastavanost.h"
#include"FormatovacFiltra.h"
#include<iostream>

class FormatovacFiltraUJZastavanost : public FormatovacFiltra<UzemnaJednotka, double>
{
protected:
	FilterPodlaIntervalu<double, UzemnaJednotka>* vytvorFilter() override {
		KriteriumUJZastavanost* kriterium = new KriteriumUJZastavanost();
		/*double max = 0;
		double min = 0;
		std::wcout << L"Zadajte maximalnu zastavanost.";
		std::wcin >> max;
		std::wcout << L"Zadajte minimalnu zastavanost.";
		std::wcin >> min;*/


		int max = 0;
		int min = 0;
		std::wcout << L"Zadajte maximálnu zastavanos.";
		
		max = CitacZKlavesnice::citajInt();

		std::wcout << L"Max hranica: " << max << L"\n";
		//std::wcin >> max;
		std::wcout << L"Zadajte minimálnu zastavanos.";
		
		min = CitacZKlavesnice::citajInt();

		std::wcout << L"Min hranica: " << min << L"\n";

		FilterPodlaIntervalu<double, UzemnaJednotka>* filter = new FilterPodlaIntervalu<double, UzemnaJednotka>(min, max, kriterium);
		return filter;
	}

	void vypisInformacieOFiltri() override {
		std::wcout << L"Tento filter umoznuje odfiltrovat data podla zastavanosti.\n";
	}
};

