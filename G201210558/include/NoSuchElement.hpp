/**
* @file NoSuchElement.hpp
* @description Y�netici listesinde hata tesbiti i�in kullanilan exception sinifindan kalitim almis �ocuk sinif
* @course 2A
* @assignment �dev 1
* @date 26.11.2022
* @author Fuad Garibli
*/

#ifndef NOSUCHELEMENT_HPP
#define NOSUCHELEMENT_HPP

#include"Exception.hpp"

class NoSuchElement : public Exception {
public:
	NoSuchElement(const string& msg) :Exception(msg) { }
};

#endif