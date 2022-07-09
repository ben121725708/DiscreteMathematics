#pragma once
/*
	���鹤����
	��������ĸ��ֲ�������
*/

class ArrayUtils
{
public:
	static ArrayUtils& getInstance() {
		static ArrayUtils instance;
		return instance;
	}

	/*
	�����������
	set		Ŀ������
	n		����Ԫ������
*/
	void insertionSort(int set[], int n);

	/*
		����ð������
		set		Ŀ������
		n		����Ԫ������
	*/
	void bubbleSort(int set[], int n);

private:
	ArrayUtils();
	~ArrayUtils();
	ArrayUtils(const ArrayUtils&);
	ArrayUtils& operator=(const ArrayUtils&);
};

