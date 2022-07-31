#include <new>
#include <iostream>
#include <queue>
#include <stack>
#include "DSChapter4.h"


namespace ds {

	DSChapter4::DSChapter4() {
		m_pHead = nullptr;
	}

	DSChapter4::~DSChapter4() {

	}


	void DSChapter4::traverseBinaryTree() {
		TreeNode* root = newTreeNode(1);
		root->left = newTreeNode(2);
		root->right = newTreeNode(3);
		root->left->left = newTreeNode(4);
		root->left->right = newTreeNode(5);

		std::cout << "前序遍历:";
		printPreorder(root);
		std::cout << std::endl;

		std::cout << "中序遍历:";
		printInorder(root);
		std::cout << std::endl;

		std::cout << "后序遍历:";
		printPostorder(root);
		std::cout << std::endl;
	}

	TreeNode* DSChapter4::newTreeNode(int data) {
		TreeNode* node = new(std::nothrow) TreeNode();
		node->val = data;
		node->left = nullptr;
		node->right = nullptr;
		return node;
	}

	void DSChapter4::printPreorder(TreeNode* node) {
		if (node == nullptr) {
			return;
		}
		std::cout << node->val << " ";
		printPreorder(node->left);
		printPreorder(node->right);
	}
	void DSChapter4::printInorder(TreeNode* node) {
		if (node == nullptr) {
			return;
		}
		printInorder(node->left);
		std::cout << node->val << " ";
		printInorder(node->right);
	}
	void DSChapter4::printPostorder(TreeNode* node) {
		if (node == nullptr) {
			return;
		}
		printInorder(node->left);
		printInorder(node->right);
		std::cout << node->val << " ";
	}


	void DSChapter4::printWithoutRecursion(TreeNode* root) {
		std::queue<TreeNode*> q;
		q.push(root);

		TreeNode* tmp = nullptr;
		while (!q.empty()) {
			tmp = q.front();
			q.pop();

			if (tmp) {
				std::cout << tmp->val << " ";
			}
			if (tmp->left) {
				q.push(tmp->left);
			}
			if (tmp->right) {
				q.push(tmp->right);
			}
		}
	}



	void DSChapter4::stringStackCheck() {
		char datas[8] = { '{','(','[','(',')',']',')','}' };
		int i = 0;
		CharNode* top = new CharNode();
		top->next = nullptr;
		while (datas[i]) {
			if (datas[i] == '(' || datas[i] == '[' || datas[i] == '{') {
				pushCharStack(&top, datas[i]);
			}

			if (datas[i] == ')' || datas[i] == ']' || datas[i] == '}') {
				if (!isMathingPair(popCharStack(&top), datas[i])) {
					std::cout << "Exp is not matching!";
					return;
				}
			}

			i++;
		}

	}

	void DSChapter4::pushCharStack(CharNode** top, char data) {
		CharNode* newTop = new CharNode();
		if (newTop == nullptr) {
			std::cout << "CharNode is nullptr!" << std::endl;
			return;
		}
		newTop->data = data;
		newTop->next = (*top);
		(*top) = newTop;
	}

	char DSChapter4::popCharStack(CharNode** top) {
		if (*top == nullptr) {
			return 0;
		}
		CharNode* tmp = (*top);
		char data = tmp->data;
		*top = tmp->next;
		delete tmp;
		tmp = nullptr;
		return data;
	}


	bool DSChapter4::isMathingPair(char c1, char c2) {
		if (c1 == '(' && c2 == ')') {
			return true;
		}
		else if (c1 == '[' && c2 == ']') {
			return true;
		}
		else if(c1 == '{' && c2 == '}'){
			return true;
		}
		else {
			return false;
		}
	}



	void DSChapter4::expressionBinaryTree() {
		char data[] = {'A','B','C','*','+','D','/'};
		ExpNode *x, *y, *z;
		for (int i = 0; i < 7;i++) {
			if (data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/' || data[i] == '^') {
				z = newExpNode(data[i]);
				x = expNodePop();
				y = expNodePop();
				z->left = y;
				z->right = x;
				expNodePush(z);
			}
			else {
				z = newExpNode(data[i]);
				expNodePush(z);
			}
		}

		printExpNodeInorder(z);

	}


	ExpNode* DSChapter4::newExpNode(char data) {
		ExpNode* node = new ExpNode();
		node->data = data;
		node->left = nullptr;
		node->right = nullptr;
		node->next = nullptr;
		return node;
	}

	void DSChapter4::expNodePush(ExpNode* node) {
		if (m_pHead == nullptr) {
			m_pHead = node;
		}
		else {
			node->next = m_pHead;
			m_pHead = node;
		}
	}

	ExpNode* DSChapter4::expNodePop() {
		ExpNode* node = m_pHead;
		m_pHead = m_pHead->next;
		return node;
	}


	void DSChapter4::printExpNodeInorder(ExpNode* node) {
		if (node == nullptr) {
			return;
		}
		
		printExpNodeInorder(node->left);
		std::cout << node->data << " ";
		printExpNodeInorder(node->right);
		
	}


	void DSChapter4::insertBinaryTree() {
		TreeNode* root = newTreeNode(1);
		root->left = newTreeNode(2);
		root->left->left = newTreeNode(3);
		root->right = newTreeNode(6);
		root->right->left = newTreeNode(5);
		root->right->right = newTreeNode(8);

		std::queue<TreeNode*> q;
		q.push(root);

		std::cout << "插入前 中序遍历:";
		printInorder(root);

		while (!q.empty()) {
			TreeNode* tmp = q.front();
			q.pop();
			if (tmp->left == nullptr) {
				tmp->left = newTreeNode(9);
				break;
			}
			else {
				q.push(tmp->left);
			}

			if (tmp->right == nullptr) {
				tmp->right = newTreeNode(9);
				break;
			}
			else {
				q.push(tmp->right);
			}

		}

		std::cout << std::endl;
		
		std::cout << "插入后 中序遍历:";
		printInorder(root);

	}


	void DSChapter4::deleteBinaryTree() {
		TreeNode* root = newTreeNode(1);
		root->left = newTreeNode(2);
		root->left->left = newTreeNode(3);
		root->left->right = newTreeNode(4);
		root->right = newTreeNode(6);
		root->right->left = newTreeNode(5);
		root->right->right = newTreeNode(8);

		std::cout << "删除前 中序遍历:";
		printInorder(root);

		std::queue<TreeNode*> q1;
		q1.push(root);

		TreeNode* tmp = nullptr;
		TreeNode* keyNode = nullptr;
		TreeNode* last = nullptr;		//记录最右边最深节点的父节点
		while (!q1.empty()) {
			tmp = q1.front();
			q1.pop();
			if (tmp->val == 4) {
				keyNode = tmp;//记录要删除的节点
			}
			if (tmp->left) {
				last = tmp;
				q1.push(tmp->left);
			}
			if (tmp->right) {
				last = tmp;
				q1.push(tmp->right);
			}
		}

		std::queue<TreeNode*> q2;
		q2.push(root);
		TreeNode* tmp2 = nullptr;
		if (keyNode != nullptr) {
			int val = tmp->val;
			if (last->left == tmp || last->right == tmp) {
				if (last->left == tmp) {
					last->left = nullptr;
				}
				if (last->right) {
					last->right = nullptr;
				}
				delete tmp;
			}
			else {
				while (!q2.empty()) {
					tmp2 = q2.front();
					q2.pop();
					if (tmp == tmp2) {
						tmp2 = nullptr;
						delete tmp;
						break;
					}
					if (tmp2->right) {
						if (tmp2->right == tmp) {
							tmp2->right = nullptr;
							delete tmp;
							break;
						}
						else {
							q2.push(tmp2->right);
						}
					}
					if (tmp2->left) {
						if (tmp2->left == tmp) {
							tmp2->left = nullptr;
							delete tmp;
							break;
						}
						else {
							q2.push(tmp2->left);
						}
					}
				}

				keyNode->val = val;
			}


		}

		std::cout << std::endl;

		std::cout << "删除后 中序遍历:";
		printInorder(root);


	}


}