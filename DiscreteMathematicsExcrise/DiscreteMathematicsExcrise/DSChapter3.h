/*
	���ݽṹ���㷨����	C��������
	������	��ջ�Ͷ���
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
			�����������к�		Ŀǰ�Ƚ����ʵ��㷨
			@param	a	Ŀ������
			@param  n	���鳤��
		*/
		int maxSubsequenceSum(const int a[],int n);

		/*
			ŷ������㷨	��2���������������
			@param	m	����1
			@param	n	����2
		*/
		unsigned int gcd(unsigned int m,unsigned int n);

		/*
			��Ч��ȡ������
			�ݹ������Ӧ��
			@param	x	����
			@param	n	ָ��
			win10������ָ������ 31  ����ջ�����ð�
		*/
		long long int pow(long int x,unsigned int n);


		/*
			����ͷ�ĵ�������
			�򵥵�ʵ����һЩ����
		*/
		void listLink();

		/*
			ջADT
			ģ��һ���򵥵�ջģ��
		*/
		void stack();



	private:

	};
}

#endif//__DS_CHAPTER_3_GG_HD__