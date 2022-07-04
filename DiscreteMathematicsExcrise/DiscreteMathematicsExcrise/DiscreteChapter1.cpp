#include <iostream>
#include "DiscreteChapter1.h"

void DiscreteChapter1::notSymbol() {

}

/*
	谜题：
	第一个和第二个箱子上写着  这个箱子是空的
	第三个箱子写着宝藏在第二个箱子
	从不说谎的皇后告诉你只有一个提示是真的

	命题定义
	!p1 !p2  p2(因为第三个箱子写着宝藏在第二个箱子)
*/
void DiscreteChapter1::threeBoxQuestion(bool p1, bool p2) {
	if ((!!p1 & !p2 & !p2)) {//简化  (p1 && !p2)
		std::cout << "In box 1";
	}

	if ((!p1 & !!p1 & !p2)) {//表达式值永为 false  (!p1 && !!p1)
		std::cout << "In box 2";
	}

	if ((!!p1 & !!p2 & p2)) {//简化  (p1 && p2)
		std::cout << "In box 3";
	}
}


void DiscreteChapter1::foreverTrueOrFalse() {
	bool p1 = false, p2 = true;
	//永真式
	std::cout << "forever true:" << (p1 | !p1) << std::endl;
	//矛盾式  永false
	std::cout << "forever false:" << (p2 & !p2) << std::endl;
}


void DiscreteChapter1::logicalEquivalence() {
	bool p = true,q = true,r = true;
	std::cout << "bool p == " << p << " bool q == " << q << " bool r == " << r << std::endl;
	std::cout << std::endl;

	//恒等式
	//p & true == p
	//p | false == p
	std::cout << "恒等式 p & true == " << (p & true) << std::endl;
	std::cout << "恒等式 p | false == " << (p | false) << std::endl;

	//支配律
	//p | true == true
	//p & false == false
	std::cout << "支配律 p | true == " << (p | true) << std::endl;
	std::cout << "支配律 p & false == " << (p & false) << std::endl;

	//幂等律
	//p | p == p
	//p & p == p
	std::cout << "幂等律 p | p == " << (p | p) << std::endl;
	std::cout << "幂等律 p & p == " << (p & p) << std::endl;

	//双重否定律
	//!(!p)
	std::cout << "双重否定律 !(!p) == " << !(!p) << std::endl;

	std::cout << std::endl;

	//交换律
	//p | q == q | p
	//p & q == q & p
	std::cout << "交换律 p | q == " << (p | q) << " 等价 " << " q | p == " << (q | p) << std::endl;
	std::cout << "交换律 p & q == " << (p & q) << " 等价 " << " q & p == " << (q & p) << std::endl;

	//结合律
	//(p | q) | r == p | (q | r)
	//(p & q) & r == p & (q & r)
	std::cout << "结合律 (p | q) | r == " << ((p | q) | r) << " 等价 " << " p | (q | r) == " << (p | (q | r)) << std::endl;
	std::cout << "结合律 (p & q) & r == " << ((p & q) & r) << " 等价 " << " p & (q & r) == " << (p & (q & r)) << std::endl;

	//分配律
	//p | (q & r) == (p | q) & (p | r)
	//p & (q | r) == (p & q) | (p & r)
	std::cout << "分配律 p | (q & r) == " << (p | (q & r)) << " 等价 " << " (p | q) & (p | r) == " << ((p | q) & (p | r)) << std::endl;
	std::cout << "分配律 p & (q | r) == " << (p & (q | r)) << " 等价 " << " (p & q) | (p & r) == " << ((p & q) | (p & r)) << std::endl;


	//德·摩根律
	/*
		!(p & q) == !p | !q
		p q相同，为true或者false	为true  !(p & q) == false   为false !(p & q) == true
		!p | !q 同理

		p q不同， (p & q)必为false	!(p & q) == true
		(!p | !q)同理   (!p | !q)必为true
	*/
	/*
		!(p | q) == !p & !q
	*/
	std::cout << "德·摩根律 !(p & q) == " << !(p & q) << " 等价 " << " !p | !q == " << (!p | !q) << std::endl;
	std::cout << "德·摩根律 !(p | q) == " << !(p | q) << " 等价 " << " !p & !q == " << (!p & !q) << std::endl;


	//吸收律
	/*
		p | (p & q) == p
		p q相同的情况	(p & q) == true或者flase		(p | true == true) 或者 (p | true == p)  p也为true		p | false == p
		p q不同的情况	(p & q) == false 结果永为false	p | (p & q) == p
	*/
	/*
		p & (p | q) == p
		p q相同的情况	(p | q) == true或者flase		p & (p | q) == p
		p q不同的情况	(p | q) == true 结果永为true	p & (p | q) == p
	*/
	std::cout << "吸收律 p | (p & q) == " << (p | (p & q)) << " 等价 " << " p & (p | q) == " << (p & (p | q)) << std::endl;


	//条件命题的逻辑等价式

	//p-->q  == !p | q
	bool r1 = true,r2 = true;
	r1 = conditionResult(p, q);
	std::cout << " p-->q == " << r1 << " 等价 " << " !p | q == " << (!p | q) << std::endl;

	//p-->q == !q-->!p
	r1 = conditionResult(p, q);
	r2 = conditionResult(!q,!p);

	std::cout << " p-->q == " << r1 << " 等价 " << " !q-->!p == " << r2 << std::endl;

	/*
		p | q == !p-->q
	*/
	r1 = conditionResult(!p, q);
	std::cout << " !p-->q == " << r1 << " 等价 " << " p | q == " << (p | q) << std::endl;

	/*
		p & q == !(p-->!q)
	*/
	r1 = !(conditionResult(p, !q));
	std::cout << " !(p-->!q) == " << r1 << " 等价 " << " p & q == " << (p & q) << std::endl;

	/*
		!(p-->q) == p & !q
	*/
	r1 = !(conditionResult(p,q));
	std::cout << " !(p-->q) == " << r1 << " 等价 " << " p & !q == " << (p & !q) << std::endl;


	/*
		(p-->q) & (p-->r) == p-->(q & r)
	*/
	r1 = (conditionResult(p, q)) & (conditionResult(p,r));
	r2 = conditionResult(p, (q & r));

	std::cout << " (p-->q) & (p-->r) == " << r1 << " 等价 " << " p-->(q & r) == " << r2 << std::endl;


	/*
		(p-->r) & (q-->r) == (q | p)-->r
	*/

	r1 = conditionResult(p, r) & conditionResult(q,r);
	r2 = conditionResult((q | p), r);

	std::cout << " (p-->r) & (q-->r) == " << r1 << " 等价 " << " (q | p)-->r == " << r2 << std::endl;


	/*
		(p-->q) | (p-->r) == p-->(q | r)
	*/
	r1 = conditionResult(p, q) | conditionResult(p,r);
	r2 = conditionResult(p, (q | r));

	std::cout << " (p-->q) | (p-->r) == " << r1 << " 等价 " << " p-->(q | r) == " << r2 << std::endl;


	/*
		(p-->r) | (q-->r) == (p & q)-->r
	*/
	r1 = conditionResult(p, r) | conditionResult(q, r);
	r2 = conditionResult((p&q), r);
	std::cout << " (p-->r) | (q-->r) == " << r1 << " 等价 " << " (p & q)-->r == " << r2 << std::endl;

	
	
	//双条件命题逻辑等价式




}

/*
	p1	命题1
	p2	命题2
*/
inline bool DiscreteChapter1::conditionResult(bool p1,bool p2) {
	if (p1 && (p2 == false)) {
		return false;
	}
	return true;
}