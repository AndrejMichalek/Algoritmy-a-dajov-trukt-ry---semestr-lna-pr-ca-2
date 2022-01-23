#pragma once
#include"unsorted_sequence_table.h"
#include<string>
#include"Kriterium.h"


template <typename T, typename O, typename K>
class Triedenie
{
public:
	/*void utried(UnsortedSequenceTable<std::string, O*>* tabulka, Kriterium<T, O>* kriterium, bool vzostupne) {
		bool dosloKZmene = false;
		do {
			dosloKZmene = false;
			for (int i = 0; i < (tabulka->size()-1); i++) {
				if (vzostupne) {
					if (kriterium->ohodnot(*(tabulka->getItemAtIndex(i).accessData())) > kriterium->ohodnot(*(tabulka->getItemAtIndex(i + 1).accessData()))) {
						tabulka->swap(tabulka->getItemAtIndex(i), tabulka->getItemAtIndex(i + 1));
						dosloKZmene = true;
					}
				}
				else {
					if (kriterium->ohodnot(*(tabulka->getItemAtIndex(i).accessData())) < kriterium->ohodnot(*(tabulka->getItemAtIndex(i + 1).accessData()))) {
						tabulka->swap(tabulka->getItemAtIndex(i), tabulka->getItemAtIndex(i + 1));
						dosloKZmene = true;
					}
				}
				
			}

		} while (dosloKZmene);
	}*/


	void tried(UnsortedSequenceTable<K, O*>* tabulka, Kriterium<T, O>* kriterium, bool vzostupne) {
		this->quickSort(0, tabulka->size() - 1,tabulka, kriterium, vzostupne);
	}

private:
	void quickSort(int min, int max, UnsortedSequenceTable<std::wstring, O*>* tabulka, Kriterium<T, O>* kriterium, bool vzostupne) {
		T pivot = kriterium->ohodnot(*(tabulka->getItemAtIndex((min + max) / 2).accessData()));
		int lavy = min;
		int pravy = max;
		
		do {
			if (vzostupne) {
				while (kriterium->ohodnot(*(tabulka->getItemAtIndex(lavy).accessData())) < pivot) {
					lavy++;
				}
				while (kriterium->ohodnot(*(tabulka->getItemAtIndex(pravy).accessData())) > pivot) {
					pravy--;
				}
			}
			else {
				while (kriterium->ohodnot(*(tabulka->getItemAtIndex(lavy).accessData())) > pivot) {
					lavy++;
				}
				while (kriterium->ohodnot(*(tabulka->getItemAtIndex(pravy).accessData())) < pivot) {
					pravy--;
				}

			}
			if (lavy <= pravy) {
				tabulka->swap(lavy, pravy);
				lavy++;
				pravy--;
			}
		} while (lavy <= pravy);

		if (min < pravy) {
			this->quickSort( min, pravy, tabulka, kriterium, vzostupne);
		}
		if (lavy < max) {
			this->quickSort(lavy, max,tabulka, kriterium, vzostupne);
		}
	}




};





