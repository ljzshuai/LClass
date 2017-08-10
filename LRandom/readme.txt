主要功能
	像C的rand()的随机数
	一定范围内的整形
	一定范围内的浮点

#include <iostream>
#include "LRandom"
int main()
{
  LJZ::LRandom random;
  std::cout << random.getCRandom() << std::endl;
  std::cout << random.getIntScopeRandom(1, 100) << std::endl;
  std::cout << random.getDoubleScopeRandom(1.0, 100.0) << std::endl;
}
