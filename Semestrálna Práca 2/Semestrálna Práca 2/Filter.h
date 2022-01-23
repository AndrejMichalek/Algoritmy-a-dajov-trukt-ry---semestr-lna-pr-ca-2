#pragma once
#include"Kriterium.h"
#include"AbstraktnyFilter.h"

template<typename T, typename O>
class Filter : public AbstraktnyFilter<O>
{
protected:
	Kriterium<T, O>* kriterium;

public:
	Filter(Kriterium<T, O>* kriterium) {
		this->kriterium = kriterium;
	}
	virtual ~Filter() {
		delete this->kriterium;
	}

	
 	
	virtual bool splnaFilter(O& omega) override = 0;
protected:
	Kriterium<T, O>* getKriterium() {
		return this->kriterium;
	}
};

