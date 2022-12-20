/**
* @file YoneticiListesi.hpp
* @description "Veriler.txt"deki her bir satiri ortalamasina göre siralayarak saklayan çift yönlü bagli liste
* @course 2A
* @assignment Ödev 1
* @date 26.11.2022
* @author Fuad Garibli
*/

#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP

#include"YoneticiDugum.hpp"
#include"NoSuchElement.hpp"

class YoneticiListesi
{
private:
	YoneticiDugum* head;
	int size;

	YoneticiDugum* FindPreviousByPosition(int)throw(NoSuchElement);
public:
	YoneticiListesi();
	YoneticiDugum* start();
	int Count()const;
	bool isEmpty()const;
	void add(SatirListesi*);
	void insert(int, SatirListesi*);
	SatirListesi* first()throw(NoSuchElement);
	SatirListesi* last()throw(NoSuchElement);
	int indexOf(SatirListesi*)throw(NoSuchElement);
	void remove(SatirListesi*);
	void removeAt(int);
	bool find(SatirListesi*);
	void reverse();
	SatirListesi* elementAt(int)throw(NoSuchElement);
	void clear();
	friend ostream& operator<<(ostream&, YoneticiListesi&);
	void printNodesFromPositionInReverseOrder(int)throw(NoSuchElement);
	void printReverseOrder();
	int UpdateNodePosition(YoneticiDugum*, double, int);
	~YoneticiListesi();
};

#endif