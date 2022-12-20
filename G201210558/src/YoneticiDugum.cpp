/**
* @file YoneticiDugum.cpp
* @description Yonetici Listesinde kullanilmak �zere tasarlanmis, i�erisinde SatirListesi* t�r�nde veri barindiran d�g�m sinifi
* @course 2A
* @assignment �dev 1
* @date 26.11.2022
* @author Fuad Garibli
*/

#include"YoneticiDugum.hpp"

YoneticiDugum::YoneticiDugum(SatirListesi* data, YoneticiDugum* next, YoneticiDugum* prev) {
	this->data = data;
	this->next = next;
	this->prev = prev;
}