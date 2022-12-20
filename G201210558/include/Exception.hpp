/**
* @file Exception.hpp
* @description Yönetici listesinde hata tesbiti için gerekli sinif(class)
* @course 2A
* @assignment Ödev 1
* @date 25.11.2022
* @author Fuad Garibli
*/

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include<iostream>
using namespace std;

class Exception {
private:
	string message;
public:
	Exception(const string& msg) :message(msg) { }
	string Message()const;
};

#endif