/**
* @file SatirDugum.cpp
* @description SatirListesinde kullanilmak �zere hazirlanmis, i�erisinde int t�r�nde data barindiran d�g�m dosyasi
* @course 2A
* @assignment �dev 1
* @date 26.11.2022
* @author Fuad Garibli
*/

#include"SatirDugum.hpp"

SatirDugum::SatirDugum(const int& data, SatirDugum* next)
{
	this->data = data;
	this->next = next;
}