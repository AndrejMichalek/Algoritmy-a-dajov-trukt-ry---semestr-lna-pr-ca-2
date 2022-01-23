#pragma once
#include"KriteriumUJ.h"

class KriteriumUJCelkovaVymera : public KriteriumUJ<double>
{
public:
	double ohodnot(UzemnaJednotka& omega)  override {
		return omega.getCelkovaVymera();
	}

};

