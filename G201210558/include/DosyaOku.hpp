/**
* @file DosyaOku.hpp
* @description "Veriler.txt" okunur, her satir için satir listesi olusturulur ve satir listeleri yönetici dügümlerine ortalamasina göre atanir
* @course 2A
* @assignment Ödev 1
* @date 25.11.2022
* @author Fuad Garibli
*/

#ifndef DOSYAOKU_HPP
#define DOSYAOKU_HPP

#include"YoneticiListesi.hpp"
#include<fstream>
#include<sstream>

class DosyaOku
{
	YoneticiListesi* yoneticiListesi;
	string fileName;
public:
	DosyaOku(string = "veriler.txt");
	YoneticiListesi* getList();
	void readAndAssign();
	~DosyaOku();
};

#endif