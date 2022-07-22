#include <iostream>
#include "DSChapter3.h"

namespace ds {


	unsigned int DSChapter3::gcd(unsigned int m, unsigned int n) {
		unsigned int rem;

		while (n > 0) {
			rem = m % n;
			m = n;
			n = rem;
		}

		return m;
	}

	int DSChapter3::maxSubsequenceSum(const int a[], int n) {
		int sum, max, j;
		sum = max = 0;
		for (j = 0; j < n;j++) {
			sum += a[j];
			if (sum > max) {
				max = sum;
			}
			else if (sum < 0) {
				sum = 0;
			}
		}

		return max;
	}

	long long int DSChapter3::pow(long int x, unsigned int n) {
		if (n == 0) {
			return 1;
		}
		if(n == 1) {
			return x;
		}
		if (n % 2 == 0) {
			return pow(x * x, n / 2);
		}
		else {
			return pow(x * x,n / 2) * x;
		}
	}


	void DSChapter3::listLink() {
		Node *head = new Node();
		head->val = 0;
		head->next = nullptr;

		Node* tmp = head;
		//����10��Ԫ��
		for (int i = 1; i <= 10; i++) {
			Node* ele = new Node();
			ele->val = i;

			tmp->next = ele;
			ele->next = nullptr;

			tmp = ele;
		}



		//�򵥵�����ɾ���ġ������

		//��	�ڱ�ͷ����һ��Ԫ��
		Node* addNode = new Node();
		addNode->val = 11;
		addNode->next = head->next;
		head->next = addNode;


		tmp = head;

		std::cout << "Add a new element:" << " ";
		while (tmp != nullptr) {
			std::cout << tmp->val << " ";
			tmp = tmp->next;
		}
		std::cout << std::endl;

		//ɾ	ɾ���ղ�������Ԫ��
		Node* tmpNode = head->next;
		head->next = tmpNode->next;
		delete tmpNode;

		tmp = head;
		std::cout << "Delete a element:" << " ";
		while (tmp != nullptr) {
			std::cout << tmp->val << " ";
			tmp = tmp->next;
		}
		std::cout << std::endl;


		tmp = head;
		//��	��һ��ֵΪ4��  ��Ϊ88
		while (tmp != nullptr) {
			if (tmp->val == 4) {
				tmp->val = 88;
				break;
			}
			tmp = tmp->next;
		}

		tmp = head;
		std::cout << "Edit a element change val 4 to 88:" << " ";
		while (tmp != nullptr) {
			std::cout << tmp->val << " ";
			tmp = tmp->next;
		}
		std::cout << std::endl;

		//��	����ֵΪ8��Ԫ��
		tmp = head;
		while (tmp != nullptr) {
			if (tmp->val == 8) {
				std::cout << "Find element val is:" << tmp->val << std::endl;
				break;
			}
			tmp = tmp->next;
		}


		tmp = head;
		//�ͷ��ڴ�
		while (tmp != nullptr) {
			if (tmp->next) {
				Node* t = tmp->next;
				tmp = t->next;
				delete t;
				t = nullptr;
			}
			else {
				break;
			}
		}

		delete head;

	}


}