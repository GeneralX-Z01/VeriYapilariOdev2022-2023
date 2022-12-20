/**
* @file Exception.hpp
* @description Y�netici listesinde hata tesbiti i�in gerekli sinif(class)
* @course 2A
* @assignment �dev 1
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