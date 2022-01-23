#pragma once
#include "UzemnaJednotka.h"
#include "sorted_sequence_table.h"
#include"unsorted_sequence_table.h"
#include "KrajUzemnaJednotka.h"
#include "OkresUzemnaJednotka.h"
#include "ObecUzemnaJednotka.h"


class StatUzemnaJednotka :public UzemnaJednotka
{
private:
	SortedSequenceTable<std::wstring, KrajUzemnaJednotka*> kraje;

	UnsortedSequenceTable<std::wstring, UzemnaJednotka*> vsetkyKraje;
	UnsortedSequenceTable<std::wstring, UzemnaJednotka*> vsetkyOkresy;
	UnsortedSequenceTable<std::wstring, UzemnaJednotka*> vsetkyObce;

	SortedSequenceTable<std::wstring, UzemnaJednotka*> sortedVsetkyKraje;
	SortedSequenceTable<std::wstring, UzemnaJednotka*> sortedVsetkyOkresy;
	SortedSequenceTable<std::wstring, UzemnaJednotka*> sortedVsetkyObce;

public:
	StatUzemnaJednotka() : UzemnaJednotka(L"Slovensko", 0, 0, 0, 0, 0, STAT, nullptr){
	}
	~StatUzemnaJednotka() {
		for (TableItem<std::wstring, UzemnaJednotka*>* kraj : vsetkyKraje) {
			KrajUzemnaJednotka* zmaz = reinterpret_cast<KrajUzemnaJednotka*>(kraj->accessData());
			delete zmaz;
		}
		for (TableItem<std::wstring, UzemnaJednotka*>* okres : vsetkyOkresy) {
			OkresUzemnaJednotka* zmaz = reinterpret_cast<OkresUzemnaJednotka*>(okres->accessData());
			delete zmaz;
		}
		for (TableItem<std::wstring, UzemnaJednotka*>* obec : vsetkyObce) {
			ObecUzemnaJednotka* zmaz = reinterpret_cast<ObecUzemnaJednotka*>(obec->accessData());
			delete zmaz;
		}
	}
	

	void pridajObec(ObecUzemnaJednotka* obec, std::wstring& nazovOkresu, std::wstring& nazovKraja) {
		if (this->kraje.containsKey(nazovKraja)) {
			this->aktualizujAtributy(obec);
			this->sortedVsetkyObce.insert(obec->getNazov(), obec);
			this->vsetkyObce.insert(obec->getNazov(), obec);
			this->kraje[nazovKraja]->pridajObec(obec, nazovOkresu,&vsetkyOkresy, &sortedVsetkyOkresy);
		}
		else {
			KrajUzemnaJednotka* novyKraj = new KrajUzemnaJednotka(nazovKraja, this);
			this->sortedVsetkyKraje.insert(nazovKraja, novyKraj);
			this->vsetkyKraje.insert(nazovKraja, novyKraj);
			this->kraje.insert(nazovKraja, novyKraj);
			this->pridajObec(obec, nazovOkresu, nazovKraja);
		}

	}

	UnsortedSequenceTable<std::wstring, UzemnaJednotka*>& getObce() {
		return this->vsetkyObce;
	}

	UnsortedSequenceTable<std::wstring, UzemnaJednotka*>& getKraje() {
		return this->vsetkyKraje;
	}


	UnsortedSequenceTable<std::wstring, UzemnaJednotka*>& getOkresy() {
		return this->vsetkyOkresy;
	}

	SortedSequenceTable<std::wstring, UzemnaJednotka*>& getSortedObce() {
		return this->sortedVsetkyObce;
	}

	SortedSequenceTable<std::wstring, UzemnaJednotka*>& getSortedKraje() {
		return this->sortedVsetkyKraje;
	}


	SortedSequenceTable<std::wstring, UzemnaJednotka*>& getSortedOkresy() {
		return this->sortedVsetkyOkresy;
	}

};

