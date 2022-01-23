// Semestrálna Práca 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"unsorted_sequence_table.h"
#include"sorted_sequence_table.h"
#include <iostream>
#include"UzivatelskeProstredie.h"
#include"ZlozenyFilter.h"
#include<io.h>
#include<fcntl.h>
#include"CitacZKlavesnice.h"

int main()
{

    initHeapMonitor();
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    
    //setlocale(LC_ALL, ".utf8");
    //setlocale(LC_ALL, "");



    
    UzivatelskeProstredie ui;
    ui.menu();
    
   
   /* std::wstring nazovMesta = CitacZKlavesnice::citajString();
    std::wcout << nazovMesta;
    int cislo = CitacZKlavesnice::citajInt();
    std::wcout << cislo;*/
    
    


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

