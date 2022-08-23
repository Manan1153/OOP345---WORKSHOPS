#ifndef _TIMEDTASK_H
#define _TIMEDTASK_H

#include <iostream>
#include <chrono>

using namespace std;

namespace sdds
{
	const int Max_event = 10;

	class TimedTask
	{

		int m_recornNum = 0;

		std::chrono::steady_clock::time_point start_time;
		std::chrono::steady_clock::time_point end_time;

		struct Task
		{
			std::string task_name;
			std::string unit_name;
			std::chrono::steady_clock::duration task_duration;
		};

		Task m_task[Max_event];

		void startClock();
		void stopClock();
		void addTask(std::string name);
		friend std::ostream& operator<<(std::ostream& ostr, const TimedTask& tasks);
	};
}

#endif // !_TIMEDTASK_H
