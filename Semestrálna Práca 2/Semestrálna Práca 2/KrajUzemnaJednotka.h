#pragma once
#include "UzemnaJednotka.h"
#include"OkresUzemnaJednotka.h"
#include"sorted_sequence_table.h"
#include"unsorted_sequence_table.h"


class KrajUzemnaJednotka : public UzemnaJednotka
{
private:
	SortedSequenceTable<std::wstring, OkresUzemnaJednotka*> okresy;


public:
	KrajUzemnaJednotka(std::wstring& nazov, UzemnaJednotka* vyssiaUzemnaJednotka) : UzemnaJednotka(nazov, 0, 0, 0, 0, 0, KRAJ, vyssiaUzemnaJednotka) {
	}

	void pridajObec(ObecUzemnaJednotka* obec, std::wstring& nazovOkresu, UnsortedSequenceTable<std::wstring, UzemnaJednotka*>* vsetkyOkresy
	, SortedSequenceTable<std::wstring, UzemnaJednotka*>* sortedVsetkyOkresy) {
		if (this->okresy.containsKey(nazovOkresu)) {
			this->aktualizujAtributy(obec);
			this->okresy[nazovOkresu]->pridajObec(obec);
		}
		else {
			OkresUzemnaJednotka* novyOkres = new OkresUzemnaJednotka(nazovOkresu, this);
			vsetkyOkresy->insert(nazovOkresu, novyOkres);
			sortedVsetkyOkresy->insert(nazovOkresu, novyOkres);
			this->okresy.insert(nazovOkresu, novyOkres);
			this->pridajObec(obec, nazovOkresu, vsetkyOkresy, sortedVsetkyOkresy);
		}
	}
};

