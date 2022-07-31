/*
	���ݽṹ���㷨����	C��������
	������	��
*/
#pragma once
#ifndef __DS_CHAPTER_4_GG_HD__
#define __DS_CHAPTER_4_GG_HD__

namespace ds {
	/*
		����������

				1			//���ڵ�

			  /   \

			 2      3

		   /  \    /  \

		  4    5   6   7	//Ҷ�ӽڵ�

		ǰ�����	root -left child -right child	
		�ȱ������ڵ㣬Ȼ����߽ڵ�  ����ұ߽ڵ�
		��������������1 2 4 5 3 6 7

		�������	left child -root  -right child
		���ȱ�����߽ڵ�	Ȼ���Ǹ��ڵ�	����ұ߽ڵ�
		��������������4 2 5 1 6 3 7


		�������	left child -right child -root
		�ȱ�����߽ڵ�	Ȼ���ұ߽ڵ�	����Ǹ��ڵ�
		��������������4 5 2 6 7 3 1
	*/

	/*
		��������������
		������n�㼶���ڵ���
		����ڵ�ֻ��һ�� n = 0	2^n = 1
		��һ�㼶���ڵ���Ϊ��2 * 2^n		n��ʾ�㼶  ���ڵ�㼶Ĭ��Ϊ 0

		�߶�Ϊh�Ķ����������ڵ���Ϊ  2^h - 1	�����h��ʼֵΪ 1

		�ھ���n���ڵ�Ķ�������		��С���ܸ߶Ȼ���С����Ϊlog2 (n + 1)
		���ڵ���Ϊ 2^h - 1
		n <= 2^h - 1
		2^h >= (n + 1)
		log2 (2^h) >= log2 (n + 1)	��ʽ����ȡlog2
		hlog2 2 >= log2 (n + 1)		h������
		h >= log2 (n + 1)

		
		һ����n��Ҷ�ӽڵ�Ķ�����������	(log2 n) + 1 �㼶
		n <= 2^n - 1
		n = log2 n + 1

		��ÿ���ڵ���0��2���ӽڵ�Ķ������У�Ҷ�ӽڵ���������Ǳ���2���ӽڵ�Ľڵ��һ��
		�� L ΪҶ�ӽڵ�	T Ϊ��2���ӽڵ���ڲ��ڵ���

		��һ�ŷǿն������У����n�ǽڵ�������e�Ǳ�����  ��ô e = n - 1
		�����⣬ ����û�бߵ�  ���Լ�1���ǰѸ�����

	*/

	/*
		������������
		�����Ķ�����

		���ÿ���ڵ㶼��0��2���ӽڵ㣬��������������Ķ�����
		����������ʾ��
						18
					 /      \
					 5       3
				    / \     / \
				   4   5   1   2


						18
					/        \
				   1		  2
				  / \
				 3   4
				/ \
			   5   6

		
		��ȫ��������
		ÿ�����𶼱�����ȫ����
		����Ҷ��Ԫ�ض�����������б
		�������һ��Ҷ�ӽڵ����û���ҽڵ�
		��ȫ������ʾ��
						18
					/        \
				   1		  2
				  / \
				 3   4
				/ \  /
			   5   6 7


		����������
		�����ڲ��ڵ㶼��2���ӽڵ㣬��������Ҷ�ӽڵ㶼��ͬһ����
		ʾ��
					    18
					 /      \
					 5       3
				    / \     / \
				   4   5   1   2


		

		ƽ�������

	*/

	/*
		��������ö��

	*/


	/*
		������
		���ݽṹ
	*/
	struct TreeNode {
		int val;				//�洢��ֵ
		TreeNode* left;	//��һ���ӽڵ�
		TreeNode* right;	//��һ���ֵܽڵ�
	};

	/*
		�ַ��ڵ�
	*/
	struct CharNode {
		char data;
		CharNode* next;
	};

	/*
		������	����ʽ���ڵ�
	*/
	struct ExpNode {
		char data;
		ExpNode* left;
		ExpNode* right;
		ExpNode* next;
	};

	class DSChapter4
	{ 
	public:
		explicit DSChapter4();
		~DSChapter4();

		//�����򵥶�������	ǰ�����򡢺������
		void traverseBinaryTree();
		//����һ���������ڵ�	data�Ǹýڵ�ֵ
		TreeNode* newTreeNode(int data);
		//ǰ�����	node�������ڵ�
		void printPreorder(TreeNode* node);
		//�������	node�������ڵ�
		void printInorder(TreeNode* node);
		//�������	node�������ڵ�
		void printPostorder(TreeNode* node);


		/*=========================================================================*/
		//������	����ʽ��
		void expressionBinaryTree();
		//�����½ڵ�
		ExpNode* newExpNode(char data);
		//ѹ��ջ��
		void expNodePush(ExpNode* node);
		//�����ڵ�
		ExpNode* expNodePop();
		void printExpNodeInorder(ExpNode* node);
		/*=========================================================================*/


		/*=========================================================================*/
		//�ö�ջ�ж����������Ƿ�ƥ��	([{}])
		void stringStackCheck();
		//�����ַ�ջ��	topջ�����ڵ��ַ	data�½ڵ�����
		void pushCharStack(CharNode** top,char data);
		//�����ַ���ջ	topջ�����ڵ��ַ
		char popCharStack(CharNode** top);
		//�ж������Ƿ�ƥ��
		bool isMathingPair(char c1,char c2);
		/*=========================================================================*/

		/*=========================================================================*/
		//
		//�ҵ���һ��Ϊ�����ӽڵ�	Ȼ�󴴽�һ���½ڵ���Ϊ�ýڵ�
		/*
			��˳����������
			���㼶��������˳��������ҵ���һ��Ϊ�յ���ڵ�����ҽڵ㣬Ȼ�󴴽�һ���½ڵ���Ϊ�ýڵ�
			ʹ��һ���������洢���зǿսڵ�
		*/
		void insertBinaryTree();
		/*=========================================================================*/


		/*=========================================================================*/
		/*
			������	ɾ���ڵ�
		*/
		void deleteBinaryTree();
		/*=========================================================================*/

		//�ǵݹ����������
		void printWithoutRecursion(TreeNode* root);

	private:
		//����ʽ�����ڵ�
		ExpNode* m_pHead;
	};

}

#endif//__DS_CHAPTER_4_GG_HD__