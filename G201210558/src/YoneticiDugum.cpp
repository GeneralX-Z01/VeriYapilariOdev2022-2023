/**
* @file YoneticiDugum.cpp
* @description Yonetici Listesinde kullanilmak üzere tasarlanmis, içerisinde SatirListesi* türünde veri barindiran dügüm sinifi
* @course 2A
* @assignment Ödev 1
* @date 26.11.2022
* @author Fuad Garibli
*/

#include"YoneticiDugum.hpp"

YoneticiDugum::YoneticiDugum(SatirListesi* data, YoneticiDugum* next, YoneticiDugum* prev) {
	this->data = data;
	this->next = next;
	this->prev = prev;
}