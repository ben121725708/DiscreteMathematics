#pragma once
class CommomUtils
{
public:
	static CommomUtils* getInstance();

	//输出一个数字的二进制格式
	void printBinaryBits(int target);
private:
	const static short M_N_BINARY_BITS_COUNT = 16;
};

