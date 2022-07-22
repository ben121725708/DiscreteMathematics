#pragma once
/*
	离散数学及其应用	原书第八版
	第二章	基本结构：集合、函数、序列、求和与矩阵
*/
class DiscreteChapter2
{
public:
	/*
		两个集合是否相等
		set1	集合1
		set2	集合2
		n		集合1元素数量
		m		集合2元素数量
	*/
	bool twoSetsEqual(int set1[], int set2[], int n, int m);


	/*
		求集合的幂集	所有子集的集合
		set		目标集合
		n		集合元素数量
	*/
	void powerSet(int set[],int n);

	/*
		令A和B为集合，A和B的笛卡尔积用 A x B表示
		是所有序偶(a,b)的集合，其中a属于A且b属于B
		A x B = {(a,b) | a属于A & b属于B}
		求解两个集合的笛卡尔积
		setA	集合A
		setB	集合B
		n		集合A元素数量
		m		集合B元素数量
	*/
	void cartesianProduct(int setA[], int setB[],int n,int m);
	void cartesianProduct(char *setA, char *setB,int n,int m);
	void cartesianProduct(int *setA, char *setB,int n,int m);
	void cartesianProduct(char *setA, int *setB,int n,int m);


	/*
		集合的并集运算
		A U B = {x | x <- A V x <- B}
		setA	集合A
		setB	集合B
		n		集合A元素数量
		m		集合B元素数量
	*/
	void aggregate(int setA[],int setB[],int n,int m);


	/*
		并集运算
		setA	集合A
		setB	集合B
		n		集合A元素数量
		m		集合B元素数量
	*/
	void jointSet(int setA[], int setB[], int n, int m);


	/*
		差集运算
		也可以用于补集运算
		setA	集合A
		setB	集合B
		n		集合A元素数量
		m		集合B元素数量
	*/
	void differenceSet(int setA[], int setB[], int n, int m);


	/*
		集合恒等式
	*/
	void identitySets();


	/*
		求和
	*/
	void summation();

	/*
		矩阵运算
	*/
	void matrix();


private:

};
