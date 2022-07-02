#include <iostream>
#include "DiscreteChapter1.h"

void DiscreteChapter1::notSymbol() {

}

/*
	谜题：
	第一个和第二个箱子上写着  这个箱子是空的
	第三个箱子写着宝藏在第二个箱子
	从不说谎的皇后告诉你只有一个提示是真的

	命题定义
	!p1 !p2  p2(因为第三个箱子写着宝藏在第二个箱子)
*/
void DiscreteChapter1::threeBoxQuestion(bool p1, bool p2) {
	if ((!!p1 & !p2 & !p2)) {//简化  (p1 && !p2)
		std::cout << "In box 1";
	}

	if ((!p1 & !!p1 & !p2)) {//表达式值永为 false  (!p1 && !!p1)
		std::cout << "In box 2";
	}

	if ((!!p1 & !!p2 & p2)) {//简化  (p1 && p2)
		std::cout << "In box 3";
	}
}


void DiscreteChapter1::foreverTrueOrFalse() {
	bool p1 = false, p2 = true;
	//永真式
	std::cout << "forever true:" << (p1 | !p1) << std::endl;
	//矛盾式  永false
	std::cout << "forever false:" << (p2 & !p2) << std::endl;
}