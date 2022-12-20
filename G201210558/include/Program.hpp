/**
* @file Program.hpp
* @description Kullanici arayüzünü olusturur, listeler üzerinde islemler yapilabilir hale gelir
* @course 2A
* @assignment Ödev 1
* @date 27.11.2022
* @author Fuad Garibli
*/

#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include"DosyaOku.hpp"
#include<iomanip>

class Program
{
	DosyaOku* file;
	YoneticiListesi* yListesi;
	string fileName;
	int screenLimit;
	int width;
	int random;
	bool del;
public:
	Program();
	void StartProgram();
	void PrintTop(int);
	int CharControl(int);
	void PrintYoneticiNodes(int);
	void PrintSatirNodes(int);
	void AddSpacing(int);
	void AddLineOfChar(char);
	void RandomAta(int);
	int DeleteSatirNode(int);
	~Program();
};

#endif