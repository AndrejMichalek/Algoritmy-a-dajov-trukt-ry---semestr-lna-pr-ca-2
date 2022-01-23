#pragma once
#include"UzemnaJednotka.h"

class ObecUzemnaJednotka : public UzemnaJednotka
{
public:
	ObecUzemnaJednotka(std::wstring nazov, int preproduktivniObyvatelia, int produktivniObyvatelia,
		int poproduktivniObyvatelia, double celkovaVymera,
		double zastavanaPlocha) :
		UzemnaJednotka(nazov, preproduktivniObyvatelia, produktivniObyvatelia, poproduktivniObyvatelia, 
			celkovaVymera, zastavanaPlocha, OBEC, nullptr) {

	}

};

