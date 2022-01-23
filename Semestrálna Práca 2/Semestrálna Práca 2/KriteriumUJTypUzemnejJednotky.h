#pragma once
#include"KriteriumUJ.h"
class KriteriumUJTypUzemnejJednotky : public KriteriumUJ<TypUzemnejJednotky>
{
	TypUzemnejJednotky ohodnot(UzemnaJednotka& omega) override {
		return omega.getTyp();
	}
};

