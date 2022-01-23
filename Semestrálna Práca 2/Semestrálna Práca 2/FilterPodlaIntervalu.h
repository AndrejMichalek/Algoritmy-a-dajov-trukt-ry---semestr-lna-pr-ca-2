#pragma once
#include"Filter.h"

template <typename T, typename O>
class FilterPodlaIntervalu : public Filter<T, O>
{
private:
	T min;
	T max;
public:
	FilterPodlaIntervalu(T min, T max, Kriterium<T, O>* kriterium) : Filter<T,O>(kriterium) {
		this->min = min;
		this->max = max;
	}


	bool splnaFilter(O& omega) override {
		T hodnotaKriteria = this->getKriterium()->ohodnot(omega); 
		return (hodnotaKriteria >= min && hodnotaKriteria <= max);
	}
};

