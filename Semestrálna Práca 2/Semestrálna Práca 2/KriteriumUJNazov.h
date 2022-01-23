#pragma once
#include <string>
#include "KriteriumUJ.h"
#include<fcntl.h>

class KriteriumUJNazov : public KriteriumUJ<std::wstring>
{
	std::wstring ohodnot(UzemnaJednotka& omega) override{
		return omega.getNazov();
	}

};

