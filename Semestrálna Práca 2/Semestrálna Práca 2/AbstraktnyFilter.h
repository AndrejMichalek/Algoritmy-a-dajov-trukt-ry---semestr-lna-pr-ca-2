#pragma once
template <typename O>
class AbstraktnyFilter
{
public:
	virtual ~AbstraktnyFilter() {};
	
	virtual bool splnaFilter(O& omega) = 0;
};

