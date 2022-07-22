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


void DiscreteChapter3::multipleRule() {
	int person[2] = {101,202};
	int rooms[12] = {1,2,3,4,5,6,7,8,9,10,11,12};

	int i, k;
	int count = 0;
	for (i = 0; i < 12;i++) {
		for (k = 0; k < 12;k++) {
			if (k != i) {
				//std::cout << person[0] << " room:" << rooms[i] << std::endl;
				std::cout << person[1] << " romm:" << rooms[k] << " ";
				count++;
			}
		}
		std::cout << std::endl;
	}
	std::cout << count << std::endl;



}