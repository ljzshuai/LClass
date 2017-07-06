#ifndef LDATE_H
#define LDATE_H
#include <chrono>
namespace LJZ
{
	using day_type = std::chrono::duration<int, std::ratio<60 * 60 * 24>>;
	using hour_type = std::chrono::hours;
	using minute_type = std::chrono::minutes;
	using second_type = std::chrono::seconds;
	using millisecond_type = std::chrono::milliseconds;
	using microsecond_type = std::chrono::microseconds;
	using namespace std::chrono;

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

	//template<class type1 ,class type2>
	//static long long getTypeCountSinceEpoch(std::chrono::duration<type1, type2> time_type);

private:
};

} //namespace LJZ
#endif // LDATE_H
