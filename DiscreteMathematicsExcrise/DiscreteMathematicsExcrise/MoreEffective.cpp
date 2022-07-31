#include <string>
#include <iostream>
#include <new>
#include "MoreEffective.h"

void MoreEffective::chapter1() {
	//�����Ե�����ʾ��
	//char *pc = nullptr;
	//char &rc = *pc;

	/*
		������������ʱ��Ҫ��ֵ
	*/
	std::string str;
	std::string &rs = str;
}


void MoreEffective::referenceDouble(const double& rd) {
	std::cout << "Reference param:" << rd << std::endl;
}

void MoreEffective::pointerDouble(const double *pd) {
	if (pd) {
		std::cout << "Pointer param:" << *pd << std::endl;
	}
}


void* MoreEffective::operator new(size_t size){
	return std::malloc(size);
}

void MoreEffective::operator delete(void* ptr) {
	if (ptr) {
		std::free(ptr);
		std::cout << "free ptr" << std::endl;
	}
	
}

void MoreEffective::newDelete() {
	//�����㹻�ڴ�	���ù��캯�����ö����ֵ
	std::string* str = new std::string("new operator");
	//����һ���㹻����string������ڴ�	�����ù��캯��
	void* rawMemory = operator new(sizeof(std::string));
	
	//Placement new
	class Widget {
	public:
		Widget() {
			std::cout << "construct no param" << std::endl;
		}

		Widget(int size) {
			
		}
		/*
			buffer	����ָ�򴴽����ڴ�
			size	�ڴ�Ĵ�С
		*/
		Widget* constructWidgetInBuffer(void* buffer, int size) {
			return new (buffer) Widget(size);
		}

		void good() {
			std::cout << "good" << std::endl;
		}

	};

	void* on = operator new(sizeof(Widget));
	std::cout << on << std::endl;

	void* t = std::malloc(sizeof(Widget));
	operator delete(t);
	operator delete(on);
	t = nullptr;
	on = nullptr;
	

	std::string* list = new std::string[10];
	list[0] = std::string("str 0");
	delete[] list;

}