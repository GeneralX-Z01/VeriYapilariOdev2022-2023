/**
* @file YoneticiDugum.hpp
* @description Yonetici Listesinde kullanilmak �zere tasarlanmis, i�erisinde SatirListesi* t�r�nde data barindiran d�g�m sinifi
* @course 2A
* @assignment �dev 1
* @date 26.11.2022
* @author Fuad Garibli
*/

#ifndef YONETICIDUGUM_HPP
#define YONETICIDUGUM_HPP

#include"SatirListesi.hpp"

class YoneticiDugum {
public:
	SatirListesi* data;
	YoneticiDugum* next;
	YoneticiDugum* prev;

	YoneticiDugum(SatirListesi* = NULL, YoneticiDugum* = NULL, YoneticiDugum* = NULL);
};


#endif