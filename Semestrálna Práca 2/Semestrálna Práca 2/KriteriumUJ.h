#pragma once
#include"Kriterium.h"
#include"UzemnaJednotka.h"

template<typename T>
class KriteriumUJ : public Kriterium<T, UzemnaJednotka>
{
public:
	virtual ~KriteriumUJ() {};

	virtual T ohodnot(UzemnaJednotka& omega) override = 0;
};

