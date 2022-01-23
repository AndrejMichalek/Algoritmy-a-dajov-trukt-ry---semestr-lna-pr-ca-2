#pragma once
#include"TypBytovejJednotky.h"

class ZoskupenieBytovychJednotiek
{
private:
	int pocet;
	int pocetOsob;
	int pocetIzieb;
	TybBytovejJednotky typ;
public:
	ZoskupenieBytovychJednotiek(TybBytovejJednotky typ, int pocetOsob, int pocetIzieb, int pocet) {
		this->pocet = pocet;
		this->pocetOsob = pocetOsob;
		this->pocetIzieb = pocetIzieb;
		this->typ = typ;
	}

	int getPocet() {
		return this->pocet;
	}
	int getPocetOsob() {
		return this->pocetOsob;
	}
	int getPocetIzieb() {
		return this->pocetIzieb;
	}
	TybBytovejJednotky getTyp() {
		return this->typ;
	}

};

