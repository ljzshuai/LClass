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

�ӱ��ʽ�л�ȡֵ�ĺ����������ҵ� �Ժ���Լ�дһ��
���û�зǷ��ַ������ж�һ�����ʽ�Ƿ���ȷ