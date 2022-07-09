#include <iostream>
#include <string>
#include "CommomUtils.h"
#include "ArrayUtils.h"
#include "DiscreteChapter2.h"


bool DiscreteChapter2::twoSetsEqual(int set1[], int set2[], int n, int m) {
	if (n != m) {
		return false;
	}

	ArrayUtils::getInstance().insertionSort(set1,n);
	ArrayUtils::getInstance().insertionSort(set2,m);
	for (int i = 0; i < n;i++) {
		if (set1[i] != set2[i]) {
			return false;
		}
	}
	return true;
}

/*
	利用二进制的排列来求集合的幂集
*/
void DiscreteChapter2::powerSet(int set[], int n) {
	std::string result;

	//子集的总数量  包含空集和自身
	const int powerCounts = (int)(pow(2, n));
	//创建一个数组  用于计算子集的下标
	int *psets = new int[n]();

	//{O} 表示空集
	result += "{ {O} ";

	//实际有多少个1  为了让打印数据更完美
	int hasCounts = 0;
	int tmpSymbol = 0;

	for (int i = 1; i < powerCounts;i++) {
		CommomUtils::getInstance().generateBinaryBits(psets, i);
		tmpSymbol = 0;
		hasCounts = 0;
		for (int k = 0; k < n;k++) {
			if (psets[k] > 0) {
				hasCounts++;
			}
		}
		result += "{";
		for (int j = 0; j < n;j++) {
			if (psets[j] > 0) {
				result += std::to_string(set[j]);
				tmpSymbol++;
				if (tmpSymbol < hasCounts) {
					result += ",";
				}	
			}
		}

		result += "}";
	}

	result += " }";

	std::cout << result << std::endl;
	
	delete []psets;

}


void DiscreteChapter2::cartesianProduct(int setA[], int setB[],int n, int m) {
	std::string result;
	int tmp;
	result += "{ ";
	for (int i = 0; i < n; i++) {
		tmp = setA[i];
		for (int j = 0; j < m; j++) {
			result += "(";
			result += std::to_string(tmp);
			result += ",";
			result += std::to_string(setB[j]);
			result += ")";
			result += " ";
		}
	}
	result += " }";
	std::cout << result << std::endl;
}

void DiscreteChapter2::cartesianProduct(char *setA, char *setB, int n, int m){
	std::string result;
	char tmp;
	result += "{ ";
	for (int i = 0; i < n; i++) {
		tmp = setA[i];
		for (int j = 0; j < m; j++) {
			result += "(";
			result += tmp;
			result += ",";
			result += setB[j];
			result += ")";
			result += " ";
		}
	}
	result += " }";
	std::cout << result << std::endl;
}

void DiscreteChapter2::cartesianProduct(int *setA, char *setB, int n, int m){
	std::string result;
	int tmp;
	result += "{ ";
	for (int i = 0; i < n; i++) {
		tmp = setA[i];
		for (int j = 0; j < m; j++) {
			result += "(";
			result += std::to_string(tmp);
			result += ",";
			result += setB[j];
			result += ")";
			result += " ";
		}
	}
	result += " }";
	std::cout << result << std::endl;
}

void DiscreteChapter2::cartesianProduct(char *setA, int *setB, int n, int m) {
	std::string result;
	char tmp;
	result += "{ ";
	for (int i = 0; i < n; i++) {
		tmp = setA[i];
		for (int j = 0; j < m; j++) {
			result += "(";
			result += tmp;
			result += ",";
			result += std::to_string(setB[j]);
			result += ")";
			result += " ";
		}
	}
	result += " }";
	std::cout << result << std::endl;
}


void DiscreteChapter2::aggregate(int setA[], int setB[], int n, int m) {

	std::string result;
	result += "{ ";
	int i, j = 0;

	int *tmp = new int[n + m]();

	for (i = 0; i < n;i++) {
		tmp[j++] = setA[i];
	}
	for (i = 0; i < m;i++) {
		tmp[j++] = setB[i];
	}

	ArrayUtils::getInstance().insertionSort(tmp,n + m);

	j = 0;
	int *tmp2 = new int[n + m]();
	for (i = 0; i < (n + m - 1);i++) {
		if (tmp[i] != tmp[i + 1]) {
			tmp2[j++] = tmp[i];
		}
	}

	tmp2[j++] = tmp[n + m - 1];


	for (i = 0; i < j;i++) {
		result += std::to_string(tmp2[i]);
		result += ",";
	}

	result += " }";

	std::cout << result << std::endl;

	delete []tmp;
	delete []tmp2;

}



void DiscreteChapter2::jointSet(int setA[], int setB[], int n, int m) {
	int *tmp = new int[n + m]();
	int i;
	int j;
	int index = 0;

	for (i = 0; i < n;i++) {
		for (j = 0; j < m; j++) {
			if (setA[i] == setB[j]) {
				tmp[index++] = setA[i];
				break;
			}
		}
	}

	//去重
	ArrayUtils::getInstance().insertionSort(tmp,index);

	int *tmp2 = new int[index]();
	j = 0;
	for (i = 0; i < index; i++) {
		if (tmp[i] != tmp[i + 1]) {
			tmp2[j++] = tmp[i];
		}
	}

	if (j <= 0) {
		std::cout << "{o/}" << std::endl;
	}
	else {
		CommomUtils::getInstance().printArrayValues(tmp2, j);
	}



	delete[]tmp;
	delete[]tmp2;
}


void DiscreteChapter2::differenceSet(int setA[], int setB[], int n, int m) {
	int *tmp = new int[n + m]();
	int index = 0;
	bool exists = false;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			if (setA[i] == setB[j]) {
				exists = true;
				break;
			}
		}
		if (!exists) {
			tmp[index++] = setA[i];
		}
		exists = false;
	}
	CommomUtils::getInstance().printArrayValues(tmp, index);
}


void DiscreteChapter2::identitySets() {
	int U[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int A[5] = {1,2,5,7,8};
	int B[5] = {2,4,6,8,10};
	//空集
	int *N = {};

	/*
		恒等律
	*/
	std::cout << "恒等律 集合A与全集U的交集 == 集合A" << std::endl;
	jointSet(A, U, 5, 12);
	std::cout << "恒等律 集合A与空集的并集 == 集合A" << std::endl;
	aggregate(A, N, 5, 0);


	/*
		支配律
	*/
	std::cout << "支配律 集合A与全集U的并集 == 全集U" << std::endl;
	aggregate(A, U, 5, 12);
	std::cout << "支配律 集合A与空集的交集 == 空集" << std::endl;
	jointSet(A, N, 5, 0);

	/*
		幂等律
	*/
	std::cout << "幂等律 集合A与集合A的并集 == 集合A" << std::endl;
	aggregate(A, A, 5, 5);
	std::cout << "幂等律 集合A与集合A的交集 == 集合A" << std::endl;
	jointSet(A, A, 5, 5);


}