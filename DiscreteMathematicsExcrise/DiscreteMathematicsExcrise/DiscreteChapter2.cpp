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
	���ö����Ƶ��������󼯺ϵ��ݼ�
*/
void DiscreteChapter2::powerSet(int set[], int n) {
	std::string result;

	//�Ӽ���������  �����ռ�������
	const int powerCounts = (int)(pow(2, n));
	//����һ������  ���ڼ����Ӽ����±�
	int *psets = new int[n]();

	//{O} ��ʾ�ռ�
	result += "{ {O} ";

	//ʵ���ж��ٸ�1  Ϊ���ô�ӡ���ݸ�����
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

	//ȥ��
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
	//�ռ�
	int *N = {};

	/*
		�����
	*/
	std::cout << "����� ����A��ȫ��U�Ľ��� == ����A" << std::endl;
	jointSet(A, U, 5, 12);
	std::cout << "����� ����A��ռ��Ĳ��� == ����A" << std::endl;
	aggregate(A, N, 5, 0);


	/*
		֧����
	*/
	std::cout << "֧���� ����A��ȫ��U�Ĳ��� == ȫ��U" << std::endl;
	aggregate(A, U, 5, 12);
	std::cout << "֧���� ����A��ռ��Ľ��� == �ռ�" << std::endl;
	jointSet(A, N, 5, 0);

	/*
		�ݵ���
	*/
	std::cout << "�ݵ��� ����A�뼯��A�Ĳ��� == ����A" << std::endl;
	aggregate(A, A, 5, 5);
	std::cout << "�ݵ��� ����A�뼯��A�Ľ��� == ����A" << std::endl;
	jointSet(A, A, 5, 5);


}


void DiscreteChapter2::summation() {

	double sum = 0;
	for (double v = 1; v <= 100;v++) {
		sum += (1 / v);
	}
	std::cout << "��͹�ʽ j = 1  ����100  ֵ:" << sum << std::endl;


	double a = 1.8, r = 0.99;

	//��͹�ʽ
	/*
		k = 0  �� n
		ar^k	r != 0
		ar^n + 1 - a / r - 1	r != 1
	*/
	sum = (a * pow(r,100 + 1) - a) / (r - 1);
	
	std::cout << "��͹�ʽһ ��" <<sum << std::endl;

	/*
		k = 1  �� n
		n(n + 1) / 2
	*/
	sum = (100 * (100 + 1)) / 2;
	std::cout << "��͹�ʽ�� ��" << sum << std::endl;


	/*
		k = 1  �� n
		k^2
		n(n + 1)(2n + 1) / 6
	*/
	sum = (50 * (50 + 1) * (2 * 50 + 1)) / 6;
	std::cout << "��͹�ʽ�� ��" << sum << std::endl;



	/*
		k = 1  �� n
		k^3
		n^2(n + 1)^2 / 4
	*/
	sum = (20 * 20 * (20 + 1)*(20 + 1)) / 4;
	std::cout << "��͹�ʽ�� ��" << sum << std::endl;

}


void DiscreteChapter2::matrix() {
	int i, j, k;
	/*
		����ӷ�
		��С��ͬ�ľ��������
	*/
	int matrix1[3][3] = {
		{1,0,1},
		{2,2,3},
		{3,4,0}
	};

	int matrix2[3][3] = {
		{3,4,-1},
		{1,-2,8},
		{-1,1,3}
	};

	int matrixTmp[3][3] = {};


	for (i = 0; i < 3;i++) {
		for (j = 0; j < 3;j++) {
			matrixTmp[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << matrixTmp[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	/*
		����˻�
	*/
	int matrix3[4][3] = { {1,0,4},{2,1,1},{3,1,0},{0,2,2} };
	int matrix4[3][2] = { {2,4},{1,1},{3,0} };
	int matrixTmp2[4][2] = {};

	int sum = 0;
	for (i = 0; i < 4;i++) {
		for (k = 0; k < 2;k++) {
			for (j = 0; j < 3;j++) {
				sum += (matrix3[i][j] * matrix4[j][k]);
			}
			matrixTmp2[i][k] = sum;
			sum = 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << matrixTmp2[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;


	/*
		n�׵�λ����
		�����ڿ˻�
		���i = j ��(i,j) = 1
			i != j ��(i,j) = 0
	*/
	int identityMatrix[20][20] = {};
	for (i = 0; i < 20;i++) {
		for (j = 0; j < 20;j++) {
			identityMatrix[i][j] = (i == j ? 1 : 0);
		}
	}

	/*for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			std::cout << identityMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;*/


	/*
		����ת��
	*/
	int transMatrix[2][3] = { {1,2,3},{4,5,6} };
	int transMatrix1[3][2] = {};

	for (i = 0; i < 2;i++) {
		for (j = 0; j < 3;j++) {
			transMatrix1[j][i] = transMatrix[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			std::cout << transMatrix1[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	/*
		�ԳƵķ���
		����A��ת�����������

		�����ǶԳƵģ����ҽ������Ƿ�������������Խ����ǶԳƵ�
	*/
	//�ԳƵķ���
	int symmetricMatrix[3][3] = { 
		{1,1,0},
		{1,0,1},
		{0,1,0}
	};
	int symmetricTmp[3][3] = {};
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			symmetricTmp[j][i] = symmetricMatrix[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << symmetricTmp[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;


	/*
		0-1����
		����Ԫ�ط�0��1
		����������ʾ������ɢ�ṹ
	*/
	int ozMatrix1[2][3] = {
		{1,0,1},
		{0,1,0}
	};
	int ozMatrix2[2][3] = {
		{0,1,0},
		{1,1,0}
	};

	int ozMatrixTmp[2][3] = {};

	//0-1����Ĳ�
	for (i = 0; i < 2;i++) {
		for (j = 0; j < 3;j++) {
			ozMatrixTmp[i][j] = (ozMatrix1[i][j] | ozMatrix2[i][j]);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << ozMatrixTmp[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	//0-1����Ľ�
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			ozMatrixTmp[i][j] = (ozMatrix1[i][j] & ozMatrix2[i][j]);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << ozMatrixTmp[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	/*
		0-1���󲼶���
		A O B
		������ͨ����ĳ˻�
		�� | ����ӷ�
		�� & ����˷�
	*/
	int boolMatrix1[3][2] = {
		{1,0},
		{0,1},
		{1,0}
	};
	int boolMatrix2[2][3] = {
		{1,1,0},
		{0,1,1}
	};

	sum = 0;
	int boolMatrixTmp[3][3] = {};
	for (i = 0; i < 3;i++) {
		for (j = 0; j < 3;j++) {
			for (k = 0; k < 2;k++) {
				sum |= boolMatrix1[i][k] & boolMatrix2[k][j];
			}
			boolMatrixTmp[i][j] = sum;
			sum = 0;
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << boolMatrixTmp[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;


}