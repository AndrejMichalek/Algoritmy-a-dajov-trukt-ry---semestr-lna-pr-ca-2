#pragma once
#include"KriteriumUJ.h"
#include"KriteriumBJPocetSVlastnostami.h"
class KriteriumUJpocetBJ : public KriteriumUJ<int> 
{

	KriteriumBJPocetSVlastnostami* kriteriumNadBJ;
public:
	KriteriumUJpocetBJ(KriteriumBJPocetSVlastnostami* kriteriumNadBJ) {
		this->kriteriumNadBJ = kriteriumNadBJ;
	}
	
	~KriteriumUJpocetBJ() {
		delete this->kriteriumNadBJ;
	}
	

	int ohodnot(UzemnaJednotka& omega) override {
		return  this->kriteriumNadBJ->ohodnot(*omega.getBytovaJednotka());
	}

};

