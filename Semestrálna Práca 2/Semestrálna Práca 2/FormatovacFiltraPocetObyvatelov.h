#pragma once
#include"UzemnaJednotka.h"
#include"FormatovacFiltra.h"
#include"KriteriumUJPocetObyvatelov.h"
#include<iostream>
#include"FilterPodlaIntervalu.h"

class FormatovacFiltraPocetObyvatelov : public FormatovacFiltra<UzemnaJednotka, int>
{
protected:
	FilterPodlaIntervalu<int, UzemnaJednotka>* vytvorFilter() override {
		KriteriumUJPocetObyvatelov* kriterium = new KriteriumUJPocetObyvatelov();
		int max = 0;
		int min = 0;
		std::wcout << L"Zadajte maximalny pocet obyvatelov.";
		max = CitacZKlavesnice::citajInt();
		//std::wcin >> max;
		std::wcout << L"Zadajte minimalny pocet obyvatelov.";
		min = CitacZKlavesnice::citajInt();

		//std::wcin >> min;

		FilterPodlaIntervalu<int, UzemnaJednotka>* filter = new FilterPodlaIntervalu<int, UzemnaJednotka>(min, max, kriterium);
		return filter;
	}

	void vypisInformacieOFiltri() override {
		std::wcout << L"Tento filter umoznuje odfiltrovat data podla poctu obyvatelov.\n";
	}
};

