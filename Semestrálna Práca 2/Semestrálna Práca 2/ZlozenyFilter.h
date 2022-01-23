#pragma once
#include"array_list.h"
#include"AbstraktnyFilter.h"
#include"unsorted_sequence_table.h"
#include"table.h"
template<typename O, typename K>
class ZlozenyFilter 
{
	ArrayList<AbstraktnyFilter<O>*> filtre;



public:
	~ZlozenyFilter() {
		for (AbstraktnyFilter<O>* filter : filtre) {
			delete filter;
		}
	}
	
	void vyfiltruj(Table<K, O*>& tabulkaVstup, UnsortedSequenceTable<K, O*>& tabulkaVystup) {
		for (auto prvokTabulky : tabulkaVstup) {
			bool splna = true;
			for (auto filter : filtre) {
				if (!filter->splnaFilter( *(prvokTabulky->accessData()))) {
					splna = false;
				}
			}
			if (splna) {
				tabulkaVystup.insert(prvokTabulky->getKey(), prvokTabulky->accessData());
			}
		}
	}
	

	void pridajFilter(AbstraktnyFilter<O>* filter) {
		if (filter != nullptr) {
			filtre.add(filter);
		}
		
	}

	

};

