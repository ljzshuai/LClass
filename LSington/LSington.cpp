#include "LSington.h"

namespace LJZ{

LSington* LSington::sington = nullptr;
LSington::LSafetuClear LSington::safetuClear;

LSington::LSington()
{

}

LSington * LSington::getLSington()
{
	if (sington)
		return sington;
	sington = new LSington();
	return sington;
}

LSington::~LSington()
{

}

}