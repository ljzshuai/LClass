��Ҫ����
        1 ��ȡ��ǰʱ���ַ���
        2 ��ʱ
        3 ��ȡ��1970.1.1�����ڵ�ʱ��

#include <iostream>
#include "LDate.h"
int main()
{
	LJZ::LDate::timerStart();
	std::cout << LJZ::LDate::getStrTime(LJZ::LDate::getNowTime_t()) << std::endl;
	std::cout << LJZ::LDate::getDayCountSinceEpoch()<<"   ��" << std::endl;
	std::cout << LJZ::LDate::timerEnd() << "  ����" << std::endl;

	std::cin.get();
	return 0;
}