#pragma once
/*
	数组工具类
	用于数组的各种操作定义
*/

class ArrayUtils
{
public:
	static ArrayUtils& getInstance() {
		static ArrayUtils instance;
		return instance;
	}

	/*
	数组插入排序
	set		目标数组
	n		数组元素数量
*/
	void insertionSort(int set[], int n);

	/*
		数组冒泡排序
		set		目标数组
		n		数组元素数量
	*/
	void bubbleSort(int set[], int n);

private:
	ArrayUtils();
	~ArrayUtils();
	ArrayUtils(const ArrayUtils&);
	ArrayUtils& operator=(const ArrayUtils&);
};

