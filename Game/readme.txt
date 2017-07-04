#include <iostream>
#include "Game24.h"
int main()
{
	Game24 game;
	if (game.isHadResult(12, 2, 1, 5)){
		auto answer = game.getAnswer();
		for (auto i : answer)
			std::cout << i << std::endl;
	}
	std::cin.get();
}

从表达式中获取值的函数是网上找的 以后会自己写一份
如果没有非法字符不能判断一个表达式是否正确