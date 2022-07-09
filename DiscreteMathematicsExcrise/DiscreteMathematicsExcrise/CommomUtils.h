#pragma once
class CommomUtils
{
public:
	static CommomUtils &getInstance() {
		static CommomUtils instance;
		return instance;
	}

	//���һ�����ֵĶ����Ƹ�ʽ
	void printBinaryBits(int target);

	//�ֽ�һ�����ֵĶ����Ƶ�������
	void generateBinaryBits(int *ary,int target);

	//���һ�����������ֵ
	void printArrayValues(int *ary,int n);

	//�ÿ�һ�����������ֵ
	void memsetArrayValues(int *ary,int n);


private:
	CommomUtils();
	~CommomUtils();
	CommomUtils(const CommomUtils&);
	CommomUtils& operator=(const CommomUtils&);
	const static short M_N_BINARY_BITS_COUNT = 16;
};