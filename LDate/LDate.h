/**************************************************************************

Copyright:liujiazhi

Author: liujiazhi

Date:2017-7-6

Description:计时
			获取1970.1.1到现在的时长
			获取std::string日期字符串
**************************************************************************/
#ifndef LDATE_H
#define LDATE_H
#include <chrono>
#include <string>
namespace LJZ
{
	using days_type = std::chrono::duration<int, std::ratio<60 * 60 * 24>>;
	using hours_type = std::chrono::hours;
	using minutes_type = std::chrono::minutes;
	using seconds_type = std::chrono::seconds;
	using milliseconds_type = std::chrono::milliseconds;
	using microseconds_type = std::chrono::microseconds;
	using namespace std::chrono;
	using std::string;

class LDate
{
public:
	LDate();
	~LDate();

	static void sleep(int milliseconds);

	static long long getDayCountSinceEpoch();
	static long long getHourCountSinceEpoch();
	static long long getMinuteCountSinceEpoch();
	static long long getSecondCountSinceEpoch();
	static long long getMilliSecondCountSinceEpoch();
	static long long getMicrosecondCountSinceEpoch();

	static time_t getNowTime_t();

	//std::time_t now_c = std::chrono::system_clock::to_time_t(point);
	//time_point point = std::chrono::system_clock::from_time_t( now_c)
	static string getStrTime(time_t);

	static void timerStart();
	static long long timerEnd();

private:
	static steady_clock::time_point start_;
};

} //namespace LJZ
#endif // LDATE_H
