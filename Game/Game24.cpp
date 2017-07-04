#include "Game24.h"
#include <stack>

Game24::Game24()
{
	 num_.swap(vector<int>(4,0));
	 num_tmp_.swap(vector<int>(4, 0));
	 num_tmp_used_.swap(vector<int>(4, 0));
}

bool Game24::isHadResult(const int& a, const int& b, const int& c, const int& d)
{
	num_[0] = a;
	num_[1] = b;
	num_[2] = c;
	num_[3] = d;
	startCalc(0);

	if (result_.empty())
		return false;

	return true;
}

void Game24::startCalc(int num)
{
	if (num == 4)
	{
		model1();
		model2();
		model3();
		model4();
		model5();
		return;
	}

	for (int i = 0; i != num_.size(); ++i)
	{
		if (num_tmp_used_[i] != 1)
		{
			num_tmp_[num] = num_[i];
			num_tmp_used_[i] = 1;
			startCalc(num + 1);
			num_tmp_used_[i] = 0;
		}
	}
}

char getOperator(int num)
{
	switch (num)
	{
	case 0:
		return '+';
	case 1:
		return '-';
	case 2:
		return '*';
	case 3:
		return '/';
	default:
		return 0;
	}
}

void Game24::model1()//((A   @   B)  @   C)  @   D
{
	char tmp[1024];
	for (int ope1 = 0; ope1 != 4; ++ope1){
		for (int ope2 = 0; ope2 != 4; ++ope2){
			for (int ope3 = 0; ope3 != 4; ++ope3){
				sprintf_s(tmp, 1024, "((%d%c%d)%c%d)%c%d", num_tmp_[0], getOperator(ope1)
					, num_tmp_[1], getOperator(ope2)
					, num_tmp_[2], getOperator(ope3), num_tmp_[3]);
				getresult(tmp);
			}
		}
	}
}
void Game24::model2()//(A   @   B)  @  (C   @   D)
{
	char tmp[1024];
	for (int ope1 = 0; ope1 != 4; ++ope1){
		for (int ope2 = 0; ope2 != 4; ++ope2){
			for (int ope3 = 0; ope3 != 4; ++ope3){
				sprintf_s(tmp, 1024, "(%d%c%d)%c(%d%c%d)", num_tmp_[0], getOperator(ope1)
					, num_tmp_[1], getOperator(ope2)
					, num_tmp_[2], getOperator(ope3), num_tmp_[3]);
				getresult(tmp);
			}
		}
	}
}
void Game24::model3()//(A   @  (B   @   C)) @   D
{
	char tmp[1024];
	for (int ope1 = 0; ope1 != 4; ++ope1){
		for (int ope2 = 0; ope2 != 4; ++ope2){
			for (int ope3 = 0; ope3 != 4; ++ope3){
				sprintf_s(tmp, 1024, "(%d%c(%d%c%d))%c%d", num_tmp_[0], getOperator(ope1)
					, num_tmp_[1], getOperator(ope2)
					, num_tmp_[2], getOperator(ope3), num_tmp_[3]);
				getresult(tmp);
			}
		}
	}
}
void Game24::model4()//A   @ ((B   @   C)  @   D)
{
	char tmp[1024];
	for (int ope1 = 0; ope1 != 4; ++ope1){
		for (int ope2 = 0; ope2 != 4; ++ope2){
			for (int ope3 = 0; ope3 != 4; ++ope3){
				sprintf_s(tmp, 1024, "%d%c((%d%c%d)%c%d)", num_tmp_[0], getOperator(ope1)
					, num_tmp_[1], getOperator(ope2)
					, num_tmp_[2], getOperator(ope3), num_tmp_[3]);
				getresult(tmp);
			}
		}
	}
}
void Game24::model5()// A   @  (B   @  (C   @   D))
{
	char tmp[1024];
	for (int ope1 = 0; ope1 != 4; ++ope1){
		for (int ope2 = 0; ope2 != 4; ++ope2){
			for (int ope3 = 0; ope3 != 4; ++ope3){
				sprintf_s(tmp, 1024, "%d%c(%d%c(%d%c%d))", num_tmp_[0], getOperator(ope1)
					, num_tmp_[1], getOperator(ope2)
					, num_tmp_[2], getOperator(ope3), num_tmp_[3]);
				getresult(tmp);
			}
		}
	}
}

int Game24::getresult(const string s)  
{
	std::stack<char> operation;//存放操作符的栈
	std::stack<double> operand;//存放操作数的栈
	operation.push('#');//先将‘#’压栈
	string num;//存放操作数
	for (int i = 0; i < s.length(); i++){
		if (isdigit(s[i])){//出现数字
			while (isdigit(s[i]) || s[i] == '.'){//将操作数提取完全
				num.push_back(s[i]);
				i++;
			}
			double a = atof(num.c_str());//string->double
			operand.push(a);//操作数入栈
			num.clear();//num清空以备下次使用
			i--;//位置还原
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '('){//出现运算符
			if (priority(0, s[i]) > priority(1, operation.top()))//优先级比较
				operation.push(s[i]);//>,直接入栈
			else{
				while (priority(0, s[i]) <= priority(1, operation.top())){//<,出栈并进行计算直至>
					char temp = operation.top();
					operation.pop();
					double op2 = operand.top();
					operand.pop();
					double op1 = operand.top();
					operand.pop();
					operand.push(calculate(temp, op1, op2));
				}
				operation.push(s[i]);//不要忘了最后操作符入栈
			}
		}
		else if (s[i] == ')'){//扫描到‘）’
			while (operation.top() != '('){//出栈直至‘（’
				char temp = operation.top();
				operation.pop();
				double op2 = operand.top();
				operand.pop();
				double op1 = operand.top();
				operand.pop();
				operand.push(calculate(temp, op1, op2));
			}
			operation.pop();//‘（’出栈
		}
		else{//非法字符的处理
			return -1;
		}
	}

	while (operation.top() != '#'){//扫尾工作
		char temp = operation.top();
		operation.pop();
		double op2 = operand.top();
		operand.pop();
		double op1 = operand.top();
		operand.pop();
		operand.push(calculate(temp, op1, op2));
	}

	if (operand.top() == 24)
	{
		result_.push_back(s);
		return 1;
	}
	return 0;
}
int Game24::priority(int state, char a)
{//计算操作符优先级的函数，注意state表示运算符状态：
	//state=1表示还未进栈，state=0表示栈内优先级，注意
	//这只对‘（’起作用
	int result;
	switch (a){
	case '+':
	case '-':
		result = 1;
		break;
	case '*':
	case '/':
		result = 2;
		break;
	case '(':
		if (state == 0)
			result = 3;
		else
			result = 0;
		break;
	case '#':
		result = 0;
		break;
	default:
		break;
	}
	return result;
}
double Game24::calculate(char op, double op1, double op2)
{
	double result;
	switch (op){
	case '+':
		result = op1 + op2;
		break;
	case '-':
		result = op1 - op2;
		break;
	case '*':
		result = op1*op2;
		break;
	case '/':
		result = op1 / op2;
		break;
	default:
		break;
	}
	return result;
}

Game24::~Game24()
{
}
