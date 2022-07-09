#include "ArrayUtils.h"



ArrayUtils::ArrayUtils() {

}

ArrayUtils::~ArrayUtils() {

}

ArrayUtils::ArrayUtils(const ArrayUtils&) {

}

ArrayUtils& ArrayUtils::operator=(const ArrayUtils&) {
	return *this;
}


void ArrayUtils::insertionSort(int set[], int n) {
	int j, p;
	int tmp;
	for (p = 1; p < n; p++) {
		tmp = set[p];
		for (j = p; j > 0 && set[j - 1] > tmp; j--) {
			set[j] = set[j - 1];
		}
		set[j] = tmp;
	}
}


void ArrayUtils::bubbleSort(int set[], int n) {
	int i, j, tmp;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (set[j] > set[j + 1]) {
				tmp = set[j];
				set[j] = set[j + 1];
				set[j + 1] = tmp;
			}
		}
	}
}