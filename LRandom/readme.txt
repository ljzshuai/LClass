��Ҫ����
	��C��rand()�������
	һ����Χ�ڵ�����
	һ����Χ�ڵĸ���

#include <iostream>
#include "LRandom"
int main()
{
  LJZ::LRandom random;
  std::cout << random.getCRandom() << std::endl;
  std::cout << random.getIntScopeRandom(1, 100) << std::endl;
  std::cout << random.getDoubleScopeRandom(1.0, 100.0) << std::endl;
}
