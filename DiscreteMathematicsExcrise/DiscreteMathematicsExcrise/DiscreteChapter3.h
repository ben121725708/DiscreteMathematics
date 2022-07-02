#pragma once
/*
	离散数学及其应用	原书第八版
	第三章	计数
*/

class DiscreteChapter3
{
public:
	/*
	乘积法则练习
	7位bit有128个不同的组合方式
	分别是整数  0 -- 127  共128个不同组合
    */
	void count7BitCombo();
private:
	//bit数
	const static unsigned short M_N_BIT_COUNTS = 7;
};

