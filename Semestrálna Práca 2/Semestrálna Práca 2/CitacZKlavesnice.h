#pragma once
#include<iostream>
#include<string>
class CitacZKlavesnice
{
public:
	static std::wstring citajString() {
		std::wstring vstup;
		std::wcin >> vstup;
		for (int i = 0; i < vstup.size(); i++) {
			if (vstup[i] == L'_') {
				vstup[i] = L' ';
			}
		}
		return vstup;
	}
	static int citajInt() {
		int vystup;
		std::wcin >> vystup;
		return vystup;
	}
};

