/**
* @file SatirListesi.cpp
* @description "Veriler.txt" deki bir satirin içerisindeki sayilari saklayan tek yönlü bagli liste
* @course 2A
* @assignment Ödev 1
* @date 26.11.2022
* @author Fuad Garibli
*/

#include"SatirListesi.hpp"

SatirDugum* SatirListesi::FindPrevByPosition(int position) {
	if (position < 0 || position > size) throw "Index out of range";
	int index = 1;

	for (SatirDugum* itr = head; itr != NULL; itr = itr->next, index++) {
		if (position == index) return itr;
	}
	return NULL;
}
SatirListesi::SatirListesi() {
	head = NULL;
	size = 0;
	ortalama = 0;
}
SatirDugum* SatirListesi::start()
{
	return head;
}
bool SatirListesi::isEmpty() const {
	return head == NULL;
}
int SatirListesi::Count() const {
	return size;
}
const int& SatirListesi::first() {
	if (isEmpty()) throw "Empty list";
	return head->data;
}
const int& SatirListesi::last() {
	if (isEmpty()) throw "Empty list";
	return FindPrevByPosition(size)->data;
}
void SatirListesi::add(const int& data) {
	insert(size, data);
	ortalama = ((ortalama * (size - 1)) + data) / size;
}
void SatirListesi::insert(int index, const int& data) {
	if (index == 0) head = new SatirDugum(data, head);
	else {
		SatirDugum* prev = FindPrevByPosition(index);
		prev->next = new SatirDugum(data, prev->next);
	}
	size++;
}
void SatirListesi::remove(const int& data) {
	int position = indexOf(data);
	removeAt(position);
}
void SatirListesi::removeAt(int index) {
	if (size == 0) throw "Empty list";
	SatirDugum* del;
	if (index == 0) {
		del = head;
		head = head->next;
	}
	else {
		SatirDugum* prev = FindPrevByPosition(index);
		del = prev->next;
		prev->next = prev->next->next;
	}
	delete del;
	size--;
}
bool SatirListesi::find(const int& data) const {
	for (SatirDugum* itr = head; itr != NULL; itr = itr->next) {
		if (itr->data == data) return true;
	}
	return false;
}
int SatirListesi::indexOf(const int& data) {
	int index = 0;
	for (SatirDugum* itr = head; itr != NULL; itr = itr->next, index++) {
		if (itr->data == data) return index;
	}
	throw "Index out of range";
}
ostream& operator<<(ostream& screen, SatirListesi& right) {
	if (right.isEmpty()) screen << "Empty list";
	else {
		for (SatirDugum* itr = right.head; itr != NULL; itr = itr->next) {
			screen << itr->data << " ";
		}
	}
	return screen;
}
void SatirListesi::clear() {
	while (!isEmpty())
		removeAt(0);
}
SatirListesi::~SatirListesi() {
	clear();
}