// DiscreteMathematicsExcrise.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DiscreteChapter1.h"
using namespace std;

int main()
{
	auto *cp1 = new  DiscreteChapter1();
	if (cp1) {
		cp1->logicalEquivalence();
	}

}