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

	/*
		乘积法则
	*/
	void multipleRule();

	/*
		排列公式
		P(n,r) = n!/(n - r)!
	*/
	unsigned int arrangement(int n,int r);

	/*
		二项式定理
		设x和y是变量，n是非负整数
		(x + y)^n = E(求和符号) [j = 0  n]	x^n - j * y^j
	*/
	void binomial();

	/*
		生成组合
	*/
	void combo();

private:
	//bit数
	const static unsigned short M_N_BIT_COUNTS = 7;
};

