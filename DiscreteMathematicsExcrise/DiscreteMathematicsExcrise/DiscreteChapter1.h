#pragma once
/*
	离散数学及其应用	原书第八版
	第一章	逻辑和证明
*/
class DiscreteChapter1
{
public:
	//三个宝箱逻辑问题  判断宝物在哪个宝箱
	void threeBoxQuestion(bool p1,bool p2);
	//永真式和矛盾式
	void foreverTrueOrFalse();
	//逻辑等价式
	void logicalEquivalence();
	//推理规则
	void inferenceRules();
private:
	inline bool conditionResult(bool p1, bool p2);
};

