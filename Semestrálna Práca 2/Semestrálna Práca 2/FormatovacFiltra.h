#pragma once
#include"Filter.h"
#include"AbstraktnyFilter.h"
#include<fcntl.h>
#include"CitacZKlavesnice.h"

template<typename O, typename T>
class FormatovacFiltra
{
public:
	Filter<T, O>* vratFilter() {
		std::wstring volba = L"0";
		this->vypisInformacieOFiltri();
		std::wcout << L"Prajete si aplikovat tento filter?\n";
		std::wcout << L"[1] Ano?\n";
		std::wcout << L"[?] Nie?\n";
		//std::wcin >> volba;
		volba = CitacZKlavesnice::citajString();
		if (volba == L"1") {
			return this->vytvorFilter();
		}
		else {
			return nullptr;
		}

	}
protected:
	virtual Filter<T, O>* vytvorFilter() = 0;

	virtual void vypisInformacieOFiltri() = 0;



};

