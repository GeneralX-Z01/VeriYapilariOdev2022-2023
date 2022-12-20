/**
* @file DosyaOku.cpp
* @description "Veriler.txt" okunur, her satir i�in satir listesi olusturulur ve satir listeleri y�netici d�g�mlerine ortalamasina g�re atanir
* @course 2A
* @assignment �dev 1
* @date 25.11.2022
* @author Fuad Garibli
*/


#include"DosyaOku.hpp"

DosyaOku::DosyaOku(string fileName)
	{
		yoneticiListesi = new YoneticiListesi();
		this->fileName = fileName;
		readAndAssign();
	}
YoneticiListesi* DosyaOku::getList()
	{
		return yoneticiListesi;
	}
void DosyaOku::readAndAssign()
	{
		ifstream myfile;
		string line;
		myfile.open(fileName);
		if (!myfile.is_open())
		{
			cerr << "Dosya Acilamadi";
			exit(EXIT_FAILURE);
		}
		while (getline(myfile, line)) {
			SatirListesi* sListesi = new SatirListesi();
			string word = "";
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] != ' ')
					word += line[i];
				else
				{
					stringstream ss(word);
					int number = 0;
					ss >> number;
					sListesi->add(number);
					word = "";
				}
			}
			yoneticiListesi->add(sListesi);
		}
	}
DosyaOku::~DosyaOku()
	{
		delete yoneticiListesi;
	}
