#pragma once

#include"KriteriumUJ.h"
class KriteriumUJPocetProduktivnychObyvatelov : KriteriumUJ<int>
{
	int ohodnot(UzemnaJednotka& omega) override {
		return omega.getPocetProduktivnychObyvatelov();
	}
};

