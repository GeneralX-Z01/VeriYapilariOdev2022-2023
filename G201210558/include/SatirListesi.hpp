/**
* @file SatirListesi.hpp
* @description Veriler.txt deki bir satirin içerisindeki sayilari saklayan tek yönlü bagli liste
* @course 2A
* @assignment Ödev 1
* @date 26.11.2022
* @author Fuad Garibli
*/

#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP

#include"SatirDugum.hpp"

class SatirListesi {
private:
	SatirDugum* head;
	int size;
	SatirDugum* FindPrevByPosition(int);
public:
	double ortalama;
	SatirListesi();
	SatirDugum* start();
	bool isEmpty() const;
	int Count() const;
	const int& first();
	const int& last();
	void add(const int&);
	void insert(int, const int&);
	void remove(const int&);
	void removeAt(int);
	bool find(const int&) const;
	int indexOf(const int&);
	friend ostream& operator<<(ostream&, SatirListesi&);
	void clear();
	~SatirListesi();
};

#endif