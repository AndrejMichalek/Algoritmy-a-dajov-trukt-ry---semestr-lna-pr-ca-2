#pragma once
#include"KriteriumUJ.h"
class KriteriumUJZastavanaPlocha : public KriteriumUJ<double>
{
	double ohodnot(UzemnaJednotka& omega) override {
		return omega.getZastavanaPlocha();
	}

};

