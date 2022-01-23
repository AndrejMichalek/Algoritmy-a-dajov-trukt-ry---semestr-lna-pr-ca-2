#pragma once
#include"BytovaJednotka.h"
#include"Kriterium.h"
template<typename T>
class KriteriumBJ : public Kriterium<T, BytovaJednotka>
{
public:
	virtual ~KriteriumBJ() {};
	virtual T ohodnot(BytovaJednotka& omega) = 0;

};

