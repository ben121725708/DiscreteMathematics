#include <iostream>
#include "CommomUtils.h"

static CommomUtils* m_pInstance = new CommomUtils();

CommomUtils* CommomUtils::getInstance() {
	return m_pInstance;
}

void CommomUtils::printBinaryBits(int target) {
	//Ä¬ÈÏÊä³ö16Î»
	unsigned char binary[M_N_BINARY_BITS_COUNT] = {
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0
	};

	short index = 0;
	while (target != 0) {
		binary[index++] = (unsigned char)(target % 2);
		target = target / 2;
	}

	for (short i = M_N_BINARY_BITS_COUNT - 1; i >= 0; i--) {
		std::cout << (unsigned short)binary[i] << " ";
	}
	std::cout << std::endl;

}