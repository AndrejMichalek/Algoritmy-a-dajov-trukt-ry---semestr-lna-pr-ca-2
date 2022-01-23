#pragma once
#include"Filter.h"

template <typename T, typename O> 
class FilterPodlaHodnoty : public Filter<T, O>
{
private:
	T hodnota;
public:
	FilterPodlaHodnoty(T hodnota, Kriterium<T, O>* kriterium): Filter<T, O>(kriterium) {
		this->hodnota = hodnota;
	}


	bool splnaFilter(O& omega) override {
		return this->getKriterium()->ohodnot(omega) == hodnota;
	}

};

