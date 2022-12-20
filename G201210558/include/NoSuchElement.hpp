/**
* @file NoSuchElement.hpp
* @description Yönetici listesinde hata tesbiti için kullanilan exception sinifindan kalitim almis çocuk sinif
* @course 2A
* @assignment Ödev 1
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