#include <string>
#include <iostream>
#include "MoreEffective.h"

void MoreEffective::chapter1() {
	//�����Ե�����ʾ��
	//char *pc = nullptr;
	//char &rc = *pc;

	/*
		������������ʱ��Ҫ��ֵ
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