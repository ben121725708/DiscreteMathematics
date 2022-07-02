#include <iostream>
#include "DiscreteChapter3.h"

void  DiscreteChapter3::count7BitCombo() {
	unsigned char binary[M_N_BIT_COUNTS] = {};

	short tmp = -1;
	short index = 0;
	for (short i = 0; i < 128; i++) {
		memset(binary, 0, M_N_BIT_COUNTS);
		index = 0;
		tmp = i;
		while (tmp != 0) {
			binary[index++] = (unsigned char)(tmp % 2);
			tmp = tmp / 2;
		}

		for (short i = M_N_BIT_COUNTS - 1; i >= 0; i--) {
			std::cout << (unsigned short)binary[i] << " ";
		}
		std::cout << std::endl;
	}
}