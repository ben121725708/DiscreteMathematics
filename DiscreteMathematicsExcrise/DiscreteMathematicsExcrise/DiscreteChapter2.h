#pragma once
/*
	��ɢ��ѧ����Ӧ��	ԭ��ڰ˰�
	�ڶ���	�����ṹ�����ϡ����������С���������
*/
class DiscreteChapter2
{
public:
	/*
		���������Ƿ����
		set1	����1
		set2	����2
		n		����1Ԫ������
		m		����2Ԫ������
	*/
	bool twoSetsEqual(int set1[], int set2[], int n, int m);


	/*
		�󼯺ϵ��ݼ�	�����Ӽ��ļ���
		set		Ŀ�꼯��
		n		����Ԫ������
	*/
	void powerSet(int set[],int n);

	/*
		��A��BΪ���ϣ�A��B�ĵѿ������� A x B��ʾ
		��������ż(a,b)�ļ��ϣ�����a����A��b����B
		A x B = {(a,b) | a����A & b����B}
		����������ϵĵѿ�����
		setA	����A
		setB	����B
		n		����AԪ������
		m		����BԪ������
	*/
	void cartesianProduct(int setA[], int setB[],int n,int m);
	void cartesianProduct(char *setA, char *setB,int n,int m);
	void cartesianProduct(int *setA, char *setB,int n,int m);
	void cartesianProduct(char *setA, int *setB,int n,int m);


	/*
		���ϵĲ�������
		A U B = {x | x <- A V x <- B}
		setA	����A
		setB	����B
		n		����AԪ������
		m		����BԪ������
	*/
	void aggregate(int setA[],int setB[],int n,int m);


	/*
		��������
		setA	����A
		setB	����B
		n		����AԪ������
		m		����BԪ������
	*/
	void jointSet(int setA[], int setB[], int n, int m);


	/*
		�����
		Ҳ�������ڲ�������
		setA	����A
		setB	����B
		n		����AԪ������
		m		����BԪ������
	*/
	void differenceSet(int setA[], int setB[], int n, int m);


	/*
		���Ϻ��ʽ
	*/
	void identitySets();


	/*
		���
	*/
	void summation();

	/*
		��������
	*/
	void matrix();


private:

};
