#include "LDate.h"
#include <thread>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <sstream>

namespace LJZ
{
steady_clock::time_point LDate::start_;

LDate::LDate()
{
}

time_t LDate::getNowTime_t()
{
	return system_clock::to_time_t(std::chrono::system_clock::now());
}

string LDate::getStrTime(time_t time)
{
	std::ostringstream out;
	tm timeinfo;
	localtime_s(&timeinfo, &time);
	out << std::put_time(&timeinfo, "%Y-%m-%d %X") << std::endl;
	return out.str();
}

void LDate::timerStart()
{
	start_ =system_clock::now();
}

long long LDate::timerEnd()
{
	auto end = system_clock::now();
	return duration_cast<milliseconds_type>(end - start_).count();
}

void LDate::sleep(int milliseconds)
{
	std::this_thread::sleep_for(milliseconds_type(milliseconds));
}

long long LDate::getDayCountSinceEpoch()
{
	time_point<system_clock, days_type> today = time_point_cast<days_type>(system_clock::now());
	return today.time_since_epoch().count();
}

long long LDate::getHourCountSinceEpoch()
{
	time_point<system_clock, hours_type> today = time_point_cast<hours_type>(system_clock::now());
	return today.time_since_epoch().count();
}

long long getMinuteCountSinceEpoch()
{
	time_point<system_clock, minutes_type> today = time_point_cast<minutes_type>(system_clock::now());
	return today.time_since_epoch().count();
}

long long getSecondCountSinceEpoch()
{
	time_point<system_clock, seconds_type> today = time_point_cast<seconds_type>(system_clock::now());
	return today.time_since_epoch().count();
}

long long getMilliSecondCountSinceEpoch()
{
	time_point<system_clock, milliseconds_type> today = time_point_cast<milliseconds_type>(system_clock::now());
	return today.time_since_epoch().count();
}

long long getMicrosecondCountSinceEpoch()
{
	time_point<system_clock, microseconds_type> today = time_point_cast<microseconds_type>(system_clock::now());
	return today.time_since_epoch().count();
}

LDate::~LDate()
{
}

}