#include "LTimer.h"
namespace LJZ{
	LTimer::LTimer()
		:can_start_(true), be_stoped_(false)
	{

	}

	bool LTimer::start_once(unsigned long long MilliSecond, std::function<void()> func)
	{

	}

	bool LTimer::start_continue(unsigned long long MilliSecond, std::function<void()> func)
	{
		if (can_start_ == false){
			return false;
		}
		can_start_ = false;
		std::thread([this, MilliSecond, func](){
			while (!be_stoped_){
				std::this_thread::sleep_for(std::chrono::milliseconds(MilliSecond));
				func();
			}

			{
				std::lock_guard<std::mutex> locker(mutex_);
				can_start_ = true;
				expired_cond_.notify_one();
			}

		}).detach();
	}

	bool LTimer::stop()
	{
		if (can_start_)
			return;		

		if (be_stoped_)
			return;		

		be_stoped_ = true;
		{
			std::unique_lock<std::mutex> locker(mutex_);
			expired_cond_.wait(locker, [this](){return can_start_ == true; });
			if (can_start_ == true)
				be_stoped_ = false;
		}
	}

	LTimer::~LTimer()
	{
		stop();
	}
}