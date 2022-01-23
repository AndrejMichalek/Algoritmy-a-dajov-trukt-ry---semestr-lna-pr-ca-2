#pragma once
#include"KriteriumUJ.h"

class KriteriumUJPocetObyvatelov : public KriteriumUJ<int>
{
	int ohodnot(UzemnaJednotka& omega) override {
		return omega.getPocetObyvatelov();
	}
};

