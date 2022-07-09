#include <iostream>
#include "CommomUtils.h"


CommomUtils::CommomUtils() {

}

CommomUtils::~CommomUtils() {

}

CommomUtils::CommomUtils(const CommomUtils&) {

}

CommomUtils& CommomUtils::operator=(const CommomUtils&) {
	return  *this;
}

void CommomUtils::printBinaryBits(int target) {
	//Ä¬ÈÏÊä³ö16Î»
	unsigned char binary[M_N_BINARY_BITS_COUNT] = {
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0
	};

	int index = 0;
	while (target != 0) {
		binary[index++] = (unsigned char)(target % 2);
		target = target / 2;
	}

	for (int i = M_N_BINARY_BITS_COUNT - 1; i >= 0; i--) {
		std::cout << (unsigned short)binary[i] << " ";
	}
	std::cout << std::endl;

}


void CommomUtils::memsetArrayValues(int *ary, int n) {
	for (int i = 0; i < n;i++) {
		ary[i] = 0;
	}
}

void CommomUtils::generateBinaryBits(int *ary, int target) {
	int index = 0;
	while (target != 0) {
		ary[index++] = (target % 2);
		target = target / 2;
	}
}


void CommomUtils::printArrayValues(int *ary, int n) {
	for (int i = 0; i < n;i++) {
		std::cout << ary[i] << " ";
	}
	std::cout << std::endl;
}

