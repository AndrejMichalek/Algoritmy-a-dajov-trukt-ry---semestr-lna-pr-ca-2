#pragma once
#include"BytovaJednotka.h"
#define POCET_TYPOV 5
#define POCET_OSOB 11
#define POCET_OBYTNYCH_MIESTNOSTI 10
class FormatovacVypisuBytovejJednotky
{
public:
	std::wstring reprezentujBytovuJednotku(BytovaJednotka* bytovaJednotka) {
		std::wstring vrat;
		for (int i = 0; i < POCET_TYPOV; i++) {
			
			for (int j = 1; j <= POCET_OSOB; j++) {
				vrat += bytovaJednotka->dajMiStringZTypu(bytovaJednotka->dajMiTypZIntu(i)) + L" ";
				vrat += L" poèet osôb:" + std::to_wstring(j) + L" ";
				for (int k = 1; k <= POCET_OBYTNYCH_MIESTNOSTI; k++) {
					vrat += L" | " + std::to_wstring(k) + L" m - p: " + 
						std::to_wstring(bytovaJednotka->dajPocetZoskupeniaBJ(bytovaJednotka->dajMiTypZIntu(i), j, k));
				}
				vrat += L"\n";
			}
			
		}
		return vrat;
	}

	std::wstring reprezentujZoskupenieBJnaIndexe(BytovaJednotka* bytovaJednotka, int index) {
		std::wstring vrat;
		
		vrat = (bytovaJednotka->dajMiTypJednotkySIndexom(index)) +
			L", poèet osôb:" + std::to_wstring(bytovaJednotka->dajMiPocetOsobJednotkySIndexom(index)) +
			L", poèet izieb: " + std::to_wstring(bytovaJednotka->dajMiPocetIziebJednotkySIndexom(index)) + 
			L", poèet: " + std::to_wstring(bytovaJednotka->dajMiPocetJednotiekSIndexom(index)) + L"\n";
		return vrat;
	}

};

