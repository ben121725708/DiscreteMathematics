#pragma once
class MoreEffective
{
public:
	void chapter1();
	//���ò���
	void referenceDouble(const double& rd);
	//ָ�����
	void pointerDouble(const double *pd);
	//new��delete
	void newDelete();
	//����new�����
	void* operator new(size_t size);
	//����delete�����
	void operator delete(void* ptr);
private:

};

