#include <iostream>
#include "Game24.h"

int main()
{
	Game24 game;
	if (game.isHadResult(12, 2, 1, 5))
	{
		auto answer = game.getAnswer();
		for (auto i : answer)
			std::cout << i << std::endl;
	}
	std::cout << "******************************************" << std::endl;
	if (game.isHadResult(7, 2, 1, 5))
	{
		auto answer = game.getAnswer();
		for (auto i : answer)
			std::cout << i << std::endl;
	}
	if (game.isRightFormula("23-6+(78*1+2*(2-1))"))
		std::cout << "是" << std::endl;
	else
		std::cout << "否" << std::endl;

	std::cin.get();
}


从表达式中获取值的函数是网上找的 以后会自己写一份


