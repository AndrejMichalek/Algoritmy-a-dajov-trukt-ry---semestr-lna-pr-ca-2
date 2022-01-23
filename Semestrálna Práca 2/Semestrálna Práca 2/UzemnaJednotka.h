#pragma once
#include<string>
#include<io.h>
#include<fcntl.h>
#include"BytovaJednotka.h"


enum TypUzemnejJednotky {
	OBEC,
	OKRES,
	KRAJ ,
	STAT
};

class UzemnaJednotka
{
private:
	UzemnaJednotka* vyssiaUzemnaJednotka;
	//atributy z 1obce sr
	std::wstring nazov;
	int preproduktivniObyvatelia;
	int produktivniObyvatelia;
	int poproduktivniObyvatelia;
	double celkovaVymera;
	double zastavanaPlocha;
	TypUzemnejJednotky typ;
	BytovaJednotka* bytovaJednotka;


public:
	UzemnaJednotka(std::wstring nazov, int preproduktivniObyvatelia, int produktivniObyvatelia, 
		int poproduktivniObyvatelia, double celkovaVymera,
		double zastavanaPlocha, TypUzemnejJednotky typ, UzemnaJednotka* vyssiaUzemnaJednotka) {
		//vlastnosti z dokumentu 1Obce SR
		this->nazov = nazov;
		this->preproduktivniObyvatelia = preproduktivniObyvatelia;
		this->produktivniObyvatelia = produktivniObyvatelia;
		this->poproduktivniObyvatelia = poproduktivniObyvatelia;
		this->celkovaVymera = celkovaVymera;
		this->zastavanaPlocha = zastavanaPlocha;
		this->typ = typ;
		//rodic v strome
		this->vyssiaUzemnaJednotka = vyssiaUzemnaJednotka;


		this->bytovaJednotka = new BytovaJednotka();
	}
	~UzemnaJednotka() {
		delete this->bytovaJednotka;
	}


	
	std::wstring getNazov() {
		return this->nazov;
	}

	TypUzemnejJednotky getTyp() {
		return this->typ;
	}
	bool patriDoVyssiehoCelku(std::wstring nazovVyssiehoCelku) {
		if (this->nazov == nazovVyssiehoCelku) {
			return true;
		}
		if (this->vyssiaUzemnaJednotka == nullptr) {
			return false;
		}
		else {
			return this->vyssiaUzemnaJednotka->patriDoVyssiehoCelku(nazovVyssiehoCelku);
		}
	}

	int getPocetPreproduktivnychObyvatelov() {
		return this->preproduktivniObyvatelia;
	}
	int getPocetProduktivnychObyvatelov() {
		return this->produktivniObyvatelia;
	}
	int getPocetPoproduktivnychObyvatelov() {
		return this->poproduktivniObyvatelia;
	}
	int getPocetObyvatelov() {
		return (this->getPocetPreproduktivnychObyvatelov() + this->getPocetProduktivnychObyvatelov() + this->getPocetPoproduktivnychObyvatelov());
	}
	double getCelkovaVymera() {
		return this->celkovaVymera;
	}
	double getZastavanaPlocha() {
		return this->zastavanaPlocha;
	}
	double getZastavanost() {
		return 100*(this->zastavanaPlocha / this->celkovaVymera);
	}
	std::wstring getTypAkoRetazec() {
		switch (this->typ) {
		case OBEC :
			return L"obec";
		case OKRES :
			return L"";
		case KRAJ :
			return L"kraj";
		case STAT :
			return L"stat";
		}
	}
	


protected:
	void setNazov(std::wstring nazov) {
		this->nazov = nazov;
	}
	void setPreproduktivniObyvatelia(int preproduktivniObyvatelia) {
		this->preproduktivniObyvatelia = preproduktivniObyvatelia;
	}
	void setProduktivniObyvatelia(int produktivniObyvatelia) {
		this->produktivniObyvatelia = produktivniObyvatelia;
	}
	void setPoProduktivniObyvatelia(int poproduktivniObyvatelia) {
		this->poproduktivniObyvatelia = poproduktivniObyvatelia;
	}
	void setCelkovaVymera(double celkovaVymera) {
		this->celkovaVymera = celkovaVymera;
	}
	void setZastavanaPlocha(double zastavanaPlocha) {
		this->zastavanaPlocha = zastavanaPlocha;
	}



	

	void aktualizujAtributy(UzemnaJednotka* uj) {
		this->setCelkovaVymera(this->getCelkovaVymera() + uj->getCelkovaVymera());
		this->setPreproduktivniObyvatelia(this->getPocetPreproduktivnychObyvatelov() + uj->getPocetPreproduktivnychObyvatelov());
		this->setProduktivniObyvatelia(this->getPocetProduktivnychObyvatelov() + uj->getPocetProduktivnychObyvatelov());
		this->setPoProduktivniObyvatelia(this->getPocetPoproduktivnychObyvatelov() + uj->getPocetPoproduktivnychObyvatelov());
		this->setZastavanaPlocha(this->getZastavanaPlocha() + uj->getZastavanaPlocha());

		this->bytovaJednotka->pripocitaj(uj->getBytovaJednotka());
	}
public:
		void setVyssiaUzemnaJedntka(UzemnaJednotka* otec) {
			this->vyssiaUzemnaJednotka = otec;
		}
		UzemnaJednotka* getVyssiaUzemnaJednotka() {
			return this->vyssiaUzemnaJednotka;
		}
		BytovaJednotka* getBytovaJednotka() {
			return bytovaJednotka;
		}
};

 