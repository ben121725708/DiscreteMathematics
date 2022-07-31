/*
	数据结构与算法分析	C语言描述
	第三章	表、栈和队列
*/
#pragma once
#ifndef __DS_CHAPTER_3_GG_HD__
#define __DS_CHAPTER_3_GG_HD__

namespace ds {
	struct Node {
		int val;
		Node* next;
	};

	class DSChapter3
	{
	public:
		/*
			求解最大子序列和		目前比较优质的算法
			@param	a	目标数组
			@param  n	数组长度
		*/
		int maxSubsequenceSum(const int a[],int n);

		/*
			欧几里得算法	求2个整数的最大公因数
			@param	m	整数1
			@param	n	整数2
		*/
		unsigned int gcd(unsigned int m,unsigned int n);

		/*
			高效率取幂运算
			递归的优质应用
			@param	x	底数
			@param	n	指数
			win10上运行指数极限 31  函数栈不够用吧
		*/
		long long int pow(long int x,unsigned int n);


		/*
			带表头的单向链表
			简单的实现了一些功能
		*/
		void listLink();

		/*
			栈ADT
			模拟一个简单的栈模型
		*/
		void stack();



	private:

	};
}

#endif//__DS_CHAPTER_3_GG_HD__