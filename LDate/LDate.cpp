#include "LDate.h"
#include <thread>

namespace LJZ
{

LDate::LDate()
{
}

void LDate::sleep(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

LDate::~LDate()
{
}

}