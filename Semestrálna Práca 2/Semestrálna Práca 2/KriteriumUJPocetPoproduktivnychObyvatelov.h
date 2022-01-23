#pragma once
#include"KriteriumUJ.h"
class KriteriumUJPocetPoproduktivnychObyvatelov : KriteriumUJ<int>
{
	int ohodnot(UzemnaJednotka& omega) override {
		return omega.getPocetPoproduktivnychObyvatelov();
	}

};

