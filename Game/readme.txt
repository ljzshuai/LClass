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
		std::cout << "��" << std::endl;
	else
		std::cout << "��" << std::endl;

	std::cin.get();
}


�ӱ��ʽ�л�ȡֵ�ĺ����������ҵ� �Ժ���Լ�дһ��


