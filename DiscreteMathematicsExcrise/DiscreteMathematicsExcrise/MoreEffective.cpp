#include <string>
#include <iostream>
#include <new>
#include "MoreEffective.h"

void MoreEffective::chapter1() {
	//灾难性的引用示例
	//char *pc = nullptr;
	//char &rc = *pc;

	/*
		引用在声明的时候要赋值
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
	//分配足够内存	调用构造函数设置对象初值
	std::string* str = new std::string("new operator");
	//分配一个足够容纳string对象的内存	不调用构造函数
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
			buffer	用来指向创建的内存
			size	内存的大小
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