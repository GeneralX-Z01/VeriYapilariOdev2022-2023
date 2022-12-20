/**
* @file Main.cpp
* @description Programin baslatildigi ana dosya
* @course 2A
* @assignment Ödev 1
* @date 25.11.2022
* @author Fuad Garibli
*/

#include"Program.hpp"
#include<time.h>

int main()
{
	srand(time(NULL));
	Program* program = new Program();
	program->StartProgram();
	delete program;
}