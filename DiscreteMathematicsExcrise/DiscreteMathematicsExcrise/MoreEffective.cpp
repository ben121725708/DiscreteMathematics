#include <string>
#include <iostream>
#include "MoreEffective.h"

void MoreEffective::chapter1() {
	//灾难性的引用示例
	//char *pc = nullptr;
	//char &rc = *pc;

	/*
		引用在声明的时候要赋值
	*/
	std::string str;
	std::string &rs = str;
}


void MoreEffective::referenceDouble(const double& rd) {
	std::cout << "Reference param:" << rd << std::endl;
}

void MoreEffective::pointerDouble(const double *pd) {
	if (pd) {
		std::cout << "Pointer param:" << *pd << std::endl;
	}
}