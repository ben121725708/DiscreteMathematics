#pragma once
class CommomUtils
{
public:
	static CommomUtils* getInstance();

	//���һ�����ֵĶ����Ƹ�ʽ
	void printBinaryBits(int target);
private:
	const static short M_N_BINARY_BITS_COUNT = 16;
};

