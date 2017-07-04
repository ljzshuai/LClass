/**************************************************************************

Copyright:liujiazhi

Author: liujiazhi

Date:2017-7-4

Description:Çî¾ÙËã24

**************************************************************************/
#ifndef Game24_H
#define Game24_H
#include <string>
#include <vector>
using std::string;
using std::vector;
class Game24
{
public:
	Game24();
	~Game24();


	bool isHadResult(const int& a,const int& b,const int& c,const int& d); //0·Ç·¨×Ö·û
	int getresult(const string);
	vector<string>getAnswer(){ return result_; }
	bool isRightFormula(string str);
private:
	void init();

	void model1();//((A   @   B)  @   C)  @   D
	void model2();//(A   @   B)  @  (C   @   D)
	void model3();//(A   @  (B   @   C)) @   D
	void model4();//A   @ ((B   @   C)  @   D)
	void model5();// A   @  (B   @  (C   @   D))

	void startCalc(int);
	int priority(int state, char a);
	double calculate(char op, double op1, double op2);
	bool isRightChar(char c);
	char getOperator(int num);

	vector<int> num_;
	vector<int> num_tmp_;
	vector<int> num_tmp_used_;
	vector<string> result_;
};

#endif//Game24_H

