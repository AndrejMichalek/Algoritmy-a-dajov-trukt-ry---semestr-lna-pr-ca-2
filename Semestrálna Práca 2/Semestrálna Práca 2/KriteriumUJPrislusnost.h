#pragma once
#include"KriteriumUJ.h"
class KriteriumUJPrislusnost : public KriteriumUJ<bool>
{
private:
	std::wstring vyssiCelok;
public:
	KriteriumUJPrislusnost(std::wstring vyssiCelok) {
		this->vyssiCelok = vyssiCelok;
	}
	 bool ohodnot(UzemnaJednotka& omega) override {
		 return omega.patriDoVyssiehoCelku(vyssiCelok);
	}
};

