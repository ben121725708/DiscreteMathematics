#include <iostream>
#include "DiscreteChapter1.h"

void DiscreteChapter1::notSymbol() {

}

/*
	���⣺
	��һ���͵ڶ���������д��  ��������ǿյ�
	����������д�ű����ڵڶ�������
	�Ӳ�˵�ѵĻʺ������ֻ��һ����ʾ�����

	���ⶨ��
	!p1 !p2  p2(��Ϊ����������д�ű����ڵڶ�������)
*/
void DiscreteChapter1::threeBoxQuestion(bool p1, bool p2) {
	if ((!!p1 & !p2 & !p2)) {//��  (p1 && !p2)
		std::cout << "In box 1";
	}

	if ((!p1 & !!p1 & !p2)) {//���ʽֵ��Ϊ false  (!p1 && !!p1)
		std::cout << "In box 2";
	}

	if ((!!p1 & !!p2 & p2)) {//��  (p1 && p2)
		std::cout << "In box 3";
	}
}


void DiscreteChapter1::foreverTrueOrFalse() {
	bool p1 = false, p2 = true;
	//����ʽ
	std::cout << "forever true:" << (p1 | !p1) << std::endl;
	//ì��ʽ  ��false
	std::cout << "forever false:" << (p2 & !p2) << std::endl;
}