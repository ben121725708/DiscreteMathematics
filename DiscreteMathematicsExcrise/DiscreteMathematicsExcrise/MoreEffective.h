#pragma once
class MoreEffective
{
public:
	void chapter1();
	//引用参数
	void referenceDouble(const double& rd);
	//指针参数
	void pointerDouble(const double *pd);
	//new和delete
	void newDelete();
	//重载new运算符
	void* operator new(size_t size);
	//重载delete运算符
	void operator delete(void* ptr);
private:

};

