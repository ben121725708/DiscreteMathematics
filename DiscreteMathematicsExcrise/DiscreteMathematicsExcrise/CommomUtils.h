#pragma once
class CommomUtils
{
public:
	static CommomUtils &getInstance() {
		static CommomUtils instance;
		return instance;
	}

	//输出一个数字的二进制格式
	void printBinaryBits(int target);

	//分解一个数字的二进制到数组中
	void generateBinaryBits(int *ary,int target);

	//输出一个数组的所有值
	void printArrayValues(int *ary,int n);

	//置空一个数组的所有值
	void memsetArrayValues(int *ary,int n);


private:
	CommomUtils();
	~CommomUtils();
	CommomUtils(const CommomUtils&);
	CommomUtils& operator=(const CommomUtils&);
	const static short M_N_BINARY_BITS_COUNT = 16;
};