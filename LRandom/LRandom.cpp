#include "LRandom.h"

namespace LJZ{
LRandom::LRandom()
{
	std::random_device e;
	e_crandom.discard(e()%1000);
}


LRandom::~LRandom()
{
}

}