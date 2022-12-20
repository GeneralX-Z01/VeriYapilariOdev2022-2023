/**
* @file SatirDugum.cpp
* @description SatirListesinde kullanilmak üzere hazirlanmis, içerisinde int türünde data barindiran dügüm dosyasi
* @course 2A
* @assignment Ödev 1
* @date 26.11.2022
* @author Fuad Garibli
*/

#include"SatirDugum.hpp"

SatirDugum::SatirDugum(const int& data, SatirDugum* next)
{
	this->data = data;
	this->next = next;
}