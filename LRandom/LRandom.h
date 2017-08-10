/**************************************************************************

Copyright:liujiazhi

Author: liujiazhi

Date:2017-8-10

Description:���������
			��C��rand()�������
			һ����Χ�ڵ�����
			һ����Χ�ڵĸ���
**************************************************************************/
#ifndef LRANDOM_H
#define LRANDOM_H
#include <random>
namespace LJZ{
class LRandom
{
public:
	LRandom();
	~LRandom();
	//ÿ����������õ�������һ����
	unsigned int getCRandom(){ return e_crandom(); }

	template<class T>
	T getIntScopeRandom(T min, T max);

	template<class T>
	T getDoubleScopeRandom(T min, T max);

private:
	std::default_random_engine e_crandom;
};

template<class T>
T LRandom::getIntScopeRandom(T min, T max)
{
	std::uniform_int_distribution<T> u(min, max);
	return u(e_crandom);
}

template<class T>
T LRandom::getDoubleScopeRandom(T min, T max)
{
	std::uniform_real_distribution<T> u(min, max);
	return u(e_crandom);
}

}// namespace LJZ
#endif // LRANDOM_H
