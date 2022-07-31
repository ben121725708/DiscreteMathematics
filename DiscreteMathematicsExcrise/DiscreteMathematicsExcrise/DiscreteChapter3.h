#pragma once
/*
	��ɢ��ѧ����Ӧ��	ԭ��ڰ˰�
	������	����
*/

class DiscreteChapter3
{
public:
	/*
	�˻�������ϰ
	7λbit��128����ͬ����Ϸ�ʽ
	�ֱ�������  0 -- 127  ��128����ͬ���
    */
	void count7BitCombo();

	/*
		�˻�����
	*/
	void multipleRule();

	/*
		���й�ʽ
		P(n,r) = n!/(n - r)!
	*/
	unsigned int arrangement(int n,int r);

	/*
		����ʽ����
		��x��y�Ǳ�����n�ǷǸ�����
		(x + y)^n = E(��ͷ���) [j = 0  n]	x^n - j * y^j
	*/
	void binomial();

	/*
		�������
	*/
	void combo();

private:
	//bit��
	const static unsigned short M_N_BIT_COUNTS = 7;
};

