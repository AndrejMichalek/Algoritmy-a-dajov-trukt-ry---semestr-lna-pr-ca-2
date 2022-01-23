#pragma once
#include"KriteriumUJ.h"
class KriteriumUJZastavanost : public KriteriumUJ<double>
{
	double ohodnot(UzemnaJednotka& omega) override {
		return omega.getZastavanost();
	}
};

