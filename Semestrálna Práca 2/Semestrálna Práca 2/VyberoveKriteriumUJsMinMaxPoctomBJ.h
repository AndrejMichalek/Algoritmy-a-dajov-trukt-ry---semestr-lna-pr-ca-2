#pragma once
#include"KriteriumUJpocetBJ.h"
#include"unsorted_sequence_table.h"
class VyberoveKriteriumUJsMinMaxPoctomBJ
{
	KriteriumUJpocetBJ* kriterium;
public:
	VyberoveKriteriumUJsMinMaxPoctomBJ(KriteriumBJPocetSVlastnostami* kriterium) {
		this->kriterium = new KriteriumUJpocetBJ(kriterium);
	}
	~VyberoveKriteriumUJsMinMaxPoctomBJ() {
		delete this->kriterium;
	}

	void vypocitajMinAMax(Table<std::wstring, UzemnaJednotka*>* tabulka, UzemnaJednotka*& ujSMinPoctomBj, int& minPocetBJ,
		UzemnaJednotka*& ujSMaxPoctomBj, int& maxPocetBJ) {
		int maximalnyPocetBJ = 0;
		int minimalnyPocetBJ = INT_MAX;
		UzemnaJednotka* maximalnaUJ = nullptr;
		UzemnaJednotka* minimalnaUJ = nullptr;


		for (auto itema : *tabulka) {
			UzemnaJednotka* prehladavanaUj = itema->accessData();
			int aktualnyPocetBJvUj = kriterium->ohodnot(*prehladavanaUj);
			if (aktualnyPocetBJvUj < minimalnyPocetBJ) {
				minimalnyPocetBJ = aktualnyPocetBJvUj;
				minimalnaUJ = prehladavanaUj;
			} 
			if (aktualnyPocetBJvUj > maximalnyPocetBJ) {
				maximalnyPocetBJ = aktualnyPocetBJvUj;
				maximalnaUJ = prehladavanaUj;
			}
		}

		ujSMinPoctomBj = minimalnaUJ;
		minPocetBJ = minimalnyPocetBJ;
		ujSMaxPoctomBj = maximalnaUJ;
		maxPocetBJ = maximalnyPocetBJ;
	}

};

