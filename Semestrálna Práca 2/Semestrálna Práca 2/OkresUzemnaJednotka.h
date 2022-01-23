#pragma once
#include "UzemnaJednotka.h"
#include "ObecUzemnaJednotka.h"
#include"sorted_sequence_table.h"

class OkresUzemnaJednotka : public UzemnaJednotka
{
private:
	SortedSequenceTable<std::wstring, ObecUzemnaJednotka*> obce;

public:
	OkresUzemnaJednotka(std::wstring& nazov, UzemnaJednotka* vyssiaUzemnaJednotka) : UzemnaJednotka(nazov, 0, 0, 0, 0, 0, OKRES, vyssiaUzemnaJednotka) {
		
	}

	void pridajObec(ObecUzemnaJednotka* obec) {
		this->aktualizujAtributy(obec);
		obec->setVyssiaUzemnaJedntka(this);
		this->obce.insert(obec->getNazov(), obec);
	}

};

