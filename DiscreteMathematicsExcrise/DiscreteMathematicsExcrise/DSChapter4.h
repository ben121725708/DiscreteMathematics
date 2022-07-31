/*
	数据结构与算法分析	C语言描述
	第四章	树
*/
#pragma once
#ifndef __DS_CHAPTER_4_GG_HD__
#define __DS_CHAPTER_4_GG_HD__

namespace ds {
	/*
		二叉树遍历

				1			//根节点

			  /   \

			 2      3

		   /  \    /  \

		  4    5   6   7	//叶子节点

		前序遍历	root -left child -right child	
		先遍历根节点，然后左边节点  最后右边节点
		上面二叉树输出：1 2 4 5 3 6 7

		中序遍历	left child -root  -right child
		首先遍历左边节点	然后是根节点	最后右边节点
		上面二叉树输出：4 2 5 1 6 3 7


		后序遍历	left child -right child -root
		先遍历左边节点	然后右边节点	最后是根节点
		上面二叉树输出：4 5 2 6 7 3 1
	*/

	/*
		二叉树基本属性
		二叉树n层级最大节点数
		如根节点只有一个 n = 0	2^n = 1
		下一层级最大节点数为：2 * 2^n		n表示层级  根节点层级默认为 0

		高度为h的二叉树中最大节点数为  2^h - 1	这里的h起始值为 1

		在具有n个节点的二叉树中		最小可能高度或最小层数为log2 (n + 1)
		最多节点数为 2^h - 1
		n <= 2^h - 1
		2^h >= (n + 1)
		log2 (2^h) >= log2 (n + 1)	上式两边取log2
		hlog2 2 >= log2 (n + 1)		h是整数
		h >= log2 (n + 1)

		
		一颗有n个叶子节点的二叉树至少有	(log2 n) + 1 层级
		n <= 2^n - 1
		n = log2 n + 1

		在每个节点有0或2个子节点的二叉树中，叶子节点的数量总是比有2个子节点的节点多一个
		设 L 为叶子节点	T 为有2个子节点的内部节点数

		在一颗非空二叉树中，如果n是节点总数，e是边总数  那么 e = n - 1
		简单理解， 根是没有边的  所以减1就是把根减掉

	*/

	/*
		二叉树的类型
		完整的二叉树

		如果每个节点都有0或2个子节点，则二叉树是完整的二叉树
		完整二叉树示例
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

		
		完全二叉树，
		每个级别都必须完全填满
		所有叶子元素都必须向左倾斜
		但是最后一个叶子节点可能没有右节点
		完全二叉树示例
						18
					/        \
				   1		  2
				  / \
				 3   4
				/ \  /
			   5   6 7


		完美二叉树
		所有内部节点都有2个子节点，并且所有叶子节点都在同一级别
		示例
					    18
					 /      \
					 5       3
				    / \     / \
				   4   5   1   2


		

		平衡二叉树

	*/

	/*
		二叉树的枚举

	*/


	/*
		二叉树
		数据结构
	*/
	struct TreeNode {
		int val;				//存储的值
		TreeNode* left;	//第一个子节点
		TreeNode* right;	//下一个兄弟节点
	};

	/*
		字符节点
	*/
	struct CharNode {
		char data;
		CharNode* next;
	};

	/*
		二叉树	表达式树节点
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

		//遍历简单二叉树的	前序、中序、后序遍历
		void traverseBinaryTree();
		//创建一个二叉树节点	data是该节点值
		TreeNode* newTreeNode(int data);
		//前序遍历	node二叉树节点
		void printPreorder(TreeNode* node);
		//中序遍历	node二叉树节点
		void printInorder(TreeNode* node);
		//后序遍历	node二叉树节点
		void printPostorder(TreeNode* node);


		/*=========================================================================*/
		//二叉树	表达式树
		void expressionBinaryTree();
		//创建新节点
		ExpNode* newExpNode(char data);
		//压入栈中
		void expNodePush(ExpNode* node);
		//弹出节点
		ExpNode* expNodePop();
		void printExpNodeInorder(ExpNode* node);
		/*=========================================================================*/


		/*=========================================================================*/
		//用堆栈判断三种括号是否匹配	([{}])
		void stringStackCheck();
		//放入字符栈中	top栈顶部节点地址	data新节点数据
		void pushCharStack(CharNode** top,char data);
		//弹出字符串栈	top栈顶部节点地址
		char popCharStack(CharNode** top);
		//判断括号是否匹配
		bool isMathingPair(char c1,char c2);
		/*=========================================================================*/

		/*=========================================================================*/
		//
		//找到第一个为空左子节点	然后创建一个新节点作为该节点
		/*
			按顺序插入二叉树
			按层级从上往下顺序遍历，找到第一个为空的左节点或者右节点，然后创建一个新节点作为该节点
			使用一个队列来存储所有非空节点
		*/
		void insertBinaryTree();
		/*=========================================================================*/


		/*=========================================================================*/
		/*
			二叉树	删除节点
		*/
		void deleteBinaryTree();
		/*=========================================================================*/

		//非递归遍历二叉树
		void printWithoutRecursion(TreeNode* root);

	private:
		//表达式树根节点
		ExpNode* m_pHead;
	};

}

#endif//__DS_CHAPTER_4_GG_HD__
