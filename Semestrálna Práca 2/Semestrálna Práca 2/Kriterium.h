#pragma once
template<typename T, typename O>
class Kriterium
{
public:
	virtual ~Kriterium() {};

	virtual T ohodnot(O& omega) = 0;
};

