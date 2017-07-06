主要功能
        1 获取当前时间字符串
        2 计时
        3 获取从1970.1.1到现在的时间

#include <iostream>
#include "LDate.h"
int main()
{
	LJZ::LDate::timerStart();
	std::cout << LJZ::LDate::getStrTime(LJZ::LDate::getNowTime_t()) << std::endl;
	std::cout << LJZ::LDate::getDayCountSinceEpoch()<<"   天" << std::endl;
	std::cout << LJZ::LDate::timerEnd() << "  毫秒" << std::endl;

	std::cin.get();
	return 0;
}