#pragma once
#include"BytovaJednotka.h"
class VyberoveKriteriumBJPocet
{
public:
	void vypocitajMinAMax(int& minIndex, int& maxIndex,BytovaJednotka* bytovaJednotka) {
		int min = INT_MAX;
		int indexMinima = 0;
		int max = 0;
		int indexMaxima = 0;
		

		int pocetPrvkov = bytovaJednotka->getMaxPocetOsob() 
			* bytovaJednotka->getMaxPocetTypov() 
			* bytovaJednotka->getMaxPocetObytnychMiestnosti();

		for (int i = 0; i < pocetPrvkov; i++) {
			int pocetAktualny = bytovaJednotka->dajMiPocetJednotiekSIndexom(i);
			if (pocetAktualny > max) {
				max = pocetAktualny;
				indexMaxima = i;
			} 
			if (pocetAktualny < min) {
				min = pocetAktualny;
				indexMinima = i;
			}
		}
		minIndex = indexMinima;
		maxIndex = indexMaxima;
	}


};

