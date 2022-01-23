#pragma once
#include"KriteriumUJ.h"

class KriteriumUJPocetPreproduktivnychObyvatelov : public KriteriumUJ<int>
{
	int ohodnot(UzemnaJednotka& omega) override {
		return omega.getPocetPreproduktivnychObyvatelov();
	}
};

