#include <iostream>
#include "DiscreteChapter1.h"


#define FORMULA_ROW		8
#define FORMULA_COL		3

/*
	����������8�����
	֤�������߼��ȼ�ʽ
*/
bool m_formulaData[FORMULA_ROW][FORMULA_COL] = {
	{true,true,true},
	{true,true,false},
	{true,false,true},
	{true,false,false},
	{false,true,true},
	{false,true,false},
	{false,false,true},
	{false,false,false},
};

/*
	���⣺
	��һ���͵ڶ���������д��  ��������ǿյ�
	����������д�ű����ڵڶ�������
	�Ӳ�˵�ѵĻʺ������ֻ��һ����ʾ�����

	���ⶨ��
	!p1 !p2  p2(��Ϊ����������д�ű����ڵڶ�������)
*/
void DiscreteChapter1::threeBoxQuestion(bool p1, bool p2) {
	if ((!!p1 & !p2 & !p2)) {//��  (p1 && !p2)
		std::cout << "In box 1";
	}

	if ((!p1 & !!p1 & !p2)) {//���ʽֵ��Ϊ false  (!p1 && !!p1)
		std::cout << "In box 2";
	}

	if ((!!p1 & !!p2 & p2)) {//��  (p1 && p2)
		std::cout << "In box 3";
	}
}


void DiscreteChapter1::foreverTrueOrFalse() {
	bool p1 = false, p2 = true;
	//����ʽ
	std::cout << "forever true:" << (p1 | !p1) << std::endl;
	//ì��ʽ  ��false
	std::cout << "forever false:" << (p2 & !p2) << std::endl;
}


/*
	ͨ��ѭ����������� p q r ����ֵ��ֵ
	֤������ʽ��
*/
void DiscreteChapter1::logicalEquivalence() {
	bool p = true,q = true,r = true;
	short i = 0, j = 0;
	for (i = 0; i < FORMULA_ROW; i++) {
		p = m_formulaData[i][0];
		q = m_formulaData[i][1];
		r = m_formulaData[i][2];

		std::cout << "bool p == " << p << " bool q == " << q << " bool r == " << r << std::endl;
		std::cout << std::endl;


		//���ʽ
		//p & true == p
		//p | false == p
		std::cout << "���ʽ p & true == " << (p & true) << std::endl;
		std::cout << "���ʽ p | false == " << (p | false) << std::endl;

		//֧����
		//p | true == true
		//p & false == false
		std::cout << "֧���� p | true == " << (p | true) << std::endl;
		std::cout << "֧���� p & false == " << (p & false) << std::endl;

		//�ݵ���
		//p | p == p
		//p & p == p
		std::cout << "�ݵ��� p | p == " << (p | p) << std::endl;
		std::cout << "�ݵ��� p & p == " << (p & p) << std::endl;

		//˫�ط���
		//!(!p)
		std::cout << "˫�ط��� !(!p) == " << !(!p) << std::endl;

		std::cout << std::endl;

		//������
		//p | q == q | p
		//p & q == q & p
		std::cout << "������ p | q == " << (p | q) << " �ȼ� " << " q | p == " << (q | p) << std::endl;
		std::cout << "������ p & q == " << (p & q) << " �ȼ� " << " q & p == " << (q & p) << std::endl;

		//�����
		//(p | q) | r == p | (q | r)
		//(p & q) & r == p & (q & r)
		std::cout << "����� (p | q) | r == " << ((p | q) | r) << " �ȼ� " << " p | (q | r) == " << (p | (q | r)) << std::endl;
		std::cout << "����� (p & q) & r == " << ((p & q) & r) << " �ȼ� " << " p & (q & r) == " << (p & (q & r)) << std::endl;

		//������
		//p | (q & r) == (p | q) & (p | r)
		//p & (q | r) == (p & q) | (p & r)
		std::cout << "������ p | (q & r) == " << (p | (q & r)) << " �ȼ� " << " (p | q) & (p | r) == " << ((p | q) & (p | r)) << std::endl;
		std::cout << "������ p & (q | r) == " << (p & (q | r)) << " �ȼ� " << " (p & q) | (p & r) == " << ((p & q) | (p & r)) << std::endl;


		//�¡�Ħ����
		/*
			!(p & q) == !p | !q
			p q��ͬ��Ϊtrue����false	Ϊtrue  !(p & q) == false   Ϊfalse !(p & q) == true
			!p | !q ͬ��

			p q��ͬ�� (p & q)��Ϊfalse	!(p & q) == true
			(!p | !q)ͬ��   (!p | !q)��Ϊtrue
		*/
		/*
			!(p | q) == !p & !q
		*/
		std::cout << "�¡�Ħ���� !(p & q) == " << !(p & q) << " �ȼ� " << " !p | !q == " << (!p | !q) << std::endl;
		std::cout << "�¡�Ħ���� !(p | q) == " << !(p | q) << " �ȼ� " << " !p & !q == " << (!p & !q) << std::endl;


		//������
		/*
			p | (p & q) == p
			p q��ͬ�����	(p & q) == true����flase		(p | true == true) ���� (p | true == p)  pҲΪtrue		p | false == p
			p q��ͬ�����	(p & q) == false �����Ϊfalse	p | (p & q) == p
		*/
		/*
			p & (p | q) == p
			p q��ͬ�����	(p | q) == true����flase		p & (p | q) == p
			p q��ͬ�����	(p | q) == true �����Ϊtrue	p & (p | q) == p
		*/
		std::cout << "������ p | (p & q) == " << (p | (p & q)) << " �ȼ� " << " p & (p | q) == " << (p & (p | q)) << std::endl;


		//����������߼��ȼ�ʽ

		//p-->q  == !p | q
		bool r1 = true, r2 = true;
		r1 = conditionResult(p, q);
		std::cout << " p-->q == " << r1 << " �ȼ� " << " !p | q == " << (!p | q) << std::endl;

		//p-->q == !q-->!p
		r1 = conditionResult(p, q);
		r2 = conditionResult(!q, !p);

		std::cout << " p-->q == " << r1 << " �ȼ� " << " !q-->!p == " << r2 << std::endl;

		/*
			p | q == !p-->q
		*/
		r1 = conditionResult(!p, q);
		std::cout << " !p-->q == " << r1 << " �ȼ� " << " p | q == " << (p | q) << std::endl;

		/*
			p & q == !(p-->!q)
		*/
		r1 = !(conditionResult(p, !q));
		std::cout << " !(p-->!q) == " << r1 << " �ȼ� " << " p & q == " << (p & q) << std::endl;

		/*
			!(p-->q) == p & !q
		*/
		r1 = !(conditionResult(p, q));
		std::cout << " !(p-->q) == " << r1 << " �ȼ� " << " p & !q == " << (p & !q) << std::endl;


		/*
			(p-->q) & (p-->r) == p-->(q & r)
		*/
		r1 = (conditionResult(p, q)) & (conditionResult(p, r));
		r2 = conditionResult(p, (q & r));

		std::cout << " (p-->q) & (p-->r) == " << r1 << " �ȼ� " << " p-->(q & r) == " << r2 << std::endl;


		/*
			(p-->r) & (q-->r) == (q | p)-->r
		*/

		r1 = conditionResult(p, r) & conditionResult(q, r);
		r2 = conditionResult((q | p), r);

		std::cout << " (p-->r) & (q-->r) == " << r1 << " �ȼ� " << " (q | p)-->r == " << r2 << std::endl;


		/*
			(p-->q) | (p-->r) == p-->(q | r)
		*/
		r1 = conditionResult(p, q) | conditionResult(p, r);
		r2 = conditionResult(p, (q | r));

		std::cout << " (p-->q) | (p-->r) == " << r1 << " �ȼ� " << " p-->(q | r) == " << r2 << std::endl;


		/*
			(p-->r) | (q-->r) == (p & q)-->r
		*/
		r1 = conditionResult(p, r) | conditionResult(q, r);
		r2 = conditionResult((p&q), r);
		std::cout << " (p-->r) | (q-->r) == " << r1 << " �ȼ� " << " (p & q)-->r == " << r2 << std::endl;


		std::cout << std::endl;
		//˫���������߼��ȼ�ʽ
		/*
			p<-->q == (p-->q) & (q-->p)
		*/
		r1 = (p == q);
		r2 = conditionResult(p, q) & conditionResult(q, p);

		std::cout << " p<-->q == " << r1 << " �ȼ� " << " (p-->q) & (q-->p) == " << r2 << std::endl;


		/*
			p<-->q == !p<-->!q
		*/
		r1 = (p == q);
		r2 = ((!p) == (!q));

		std::cout << " p<-->q == " << r1 << " �ȼ� " << " !p<-->!q == " << r2 << std::endl;


		/*
			p<-->q == (p & q) | (!p & !q)
		*/
		r1 = (p == q);
		r2 = (p & q) | (!p & !q);

		std::cout << " p<-->q == " << r1 << " �ȼ� " << " (p & q) | (!p & !q) == " << r2 << std::endl;


		/*
			!(p<-->q) == p<-->!q
		*/
		r1 = !(p == q);
		r2 = (p == (!q));

		std::cout << " !(p<-->q) == " << r1 << " �ȼ� " << " p<-->!q == " << r2 << std::endl;

	}


}

/*
	p1	����1
	p2	����2
	p1-->p2
	�����̺�ʽ��ֵ
*/
inline bool DiscreteChapter1::conditionResult(bool p1,bool p2) {
	if (p1 && (p2 == false)) {
		return false;
	}
	return true;
}


void DiscreteChapter1::inferenceRules() {
	bool p = true, q = true, r = true;
	bool r1;

	int i;

	
	/*
		��������
		(p & (p-->q))-->q
	*/
	std::cout << " ======== ��������֤�� ======== " <<std::endl;
	for (i = 0; i < FORMULA_ROW; i++) {
		p = m_formulaData[i][0];
		q = m_formulaData[i][1];
		r = m_formulaData[i][2];

		std::cout << "bool p == " << p << " bool q == " << q << " bool r == " << r << std::endl;

		r1 = conditionResult((p & conditionResult(p, q)), q);
		std::cout << " (p & (p-->q))-->q == " << r1 << std::endl;
		std::cout << std::endl;
	}


	/*
		ȡ��ʽ
		(!q & (p-->q))-->!p
	*/
	std::cout << " ======== ȡ��ʽ֤�� ======== " << std::endl;
	for (i = 0; i < FORMULA_ROW; i++) {
		p = m_formulaData[i][0];
		q = m_formulaData[i][1];
		r = m_formulaData[i][2];

		std::cout << "bool p == " << p << " bool q == " << q << " bool r == " << r << std::endl;

		r1 = conditionResult((!q & conditionResult(p, q)), !p);
		std::cout << " (!q & (p-->q))-->!p == " << r1 << std::endl;
		std::cout << std::endl;
	}


	/*
		����������
		(p-->q) & (q-->r) & (p-->r)
	*/
	std::cout << " ======== ����������֤�� ======== " << std::endl;
	for (i = 0; i < FORMULA_ROW; i++) {
		p = m_formulaData[i][0];
		q = m_formulaData[i][1];
		r = m_formulaData[i][2];

		std::cout << "bool p == " << p << " bool q == " << q << " bool r == " << r << std::endl;

		r1 = conditionResult((conditionResult(p, q) & conditionResult(q, r)), conditionResult(p, r));
		std::cout << " (p-->q) & (q-->r) & (p-->r) == " << r1 << std::endl;
		std::cout << std::endl;
	}

	/*
		��ȡ������
		((p | q) & !p)-->q
	*/
	std::cout << " ======== ��ȡ������֤�� ======== " << std::endl;
	for (i = 0; i < FORMULA_ROW; i++) {
		p = m_formulaData[i][0];
		q = m_formulaData[i][1];
		r = m_formulaData[i][2];

		std::cout << "bool p == " << p << " bool q == " << q << " bool r == " << r << std::endl;

		r1 = conditionResult(((p | q) & !p),q);
		std::cout << " ((p | q) & !p)-->q == " << r1 << std::endl;
		std::cout << std::endl;
	}


	/*
		������
		p-->(p | q)
	*/
	std::cout << " ======== ������֤�� ======== " << std::endl;
	for (i = 0; i < FORMULA_ROW; i++) {
		p = m_formulaData[i][0];
		q = m_formulaData[i][1];
		r = m_formulaData[i][2];

		std::cout << "bool p == " << p << " bool q == " << q << " bool r == " << r << std::endl;

		r1 = conditionResult(p, (p | q));
		std::cout << " p-->(p | q) == " << r1 << std::endl;
		std::cout << std::endl;
	}

	/*
		������
		(p & q)-->p
	*/
	std::cout << " ======== ������֤�� ======== " << std::endl;
	for (i = 0; i < FORMULA_ROW; i++) {
		p = m_formulaData[i][0];
		q = m_formulaData[i][1];
		r = m_formulaData[i][2];

		std::cout << "bool p == " << p << " bool q == " << q << " bool r == " << r << std::endl;

		r1 = conditionResult(p, (p | q));
		std::cout << " (p & q)-->p == " << r1 << std::endl;
		std::cout << std::endl;
	}

	/*
		��ȡ��
		((p) & (q))-->(p & q)
	*/
	std::cout << " ======== ��ȡ��֤�� ======== " << std::endl;
	for (i = 0; i < FORMULA_ROW; i++) {
		p = m_formulaData[i][0];
		q = m_formulaData[i][1];
		r = m_formulaData[i][2];

		std::cout << "bool p == " << p << " bool q == " << q << " bool r == " << r << std::endl;

		r1 = conditionResult(((p) & (q)), (p & q));
		std::cout << " ((p) & (q))-->(p & q) == " << r1 << std::endl;
		std::cout << std::endl;
	}


	/*
		������
		((p | q) & (!p | r))-->(q | r)
	*/
	std::cout << " ======== ������֤�� ======== " << std::endl;
	for (i = 0; i < FORMULA_ROW; i++) {
		p = m_formulaData[i][0];
		q = m_formulaData[i][1];
		r = m_formulaData[i][2];

		std::cout << "bool p == " << p << " bool q == " << q << " bool r == " << r << std::endl;

		r1 = conditionResult(((p | q) & (!p | r)), (q | r));
		std::cout << " ((p | q) & (!p | r))-->(q | r) == " << r1 << std::endl;
		std::cout << std::endl;
	}






}