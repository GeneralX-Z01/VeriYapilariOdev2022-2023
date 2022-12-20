/**
* @file SatirDugum.hpp
* @description SatirListesinde kullanilmak �zere hazirlanmis, i�erisinde int t�r�nde data barindiran d�g�m dosyasi
* @course 2A
* @assignment �dev 1
* @date 26.11.2022
* @author Fuad Garibli
*/

#ifndef SATIRDUGUM_HPP
#define SATIRDUGUM_HPP

#include<iostream>
using namespace std;

class SatirDugum
{
public:
	int data;
	SatirDugum* next;
	SatirDugum(const int& = 0, SatirDugum* = NULL);
};

#endif