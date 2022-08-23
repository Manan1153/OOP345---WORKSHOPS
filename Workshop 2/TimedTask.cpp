#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include <iostream>
#include "TimedTask.h"

using namespace std;

namespace sdds
{
	void TimedTask::startClock()
	{
		start_time = chrono::steady_clock::now();
	}

	void TimedTask::stopClock()
	{
		end_time = chrono::steady_clock::now();
	}

	void TimedTask::addTask(std::string name) {
		m_task[m_recornNum].task_name = name;
		m_task[m_recornNum].unit_name = "nanoseconds";
		m_task[m_recornNum].task_duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

		m_recornNum += 1;
	}

	ostream& operator<<(std::ostream& ostr, const TimedTask& t_tasks) 
	{
		ostr << "--------------------------\n" << "Execution Times:\n--------------------------\n";

		for (int i = 0; i < t_tasks.m_recornNum; i++)
		{
			ostr << std::setw(21) << std::left << t_tasks.m_task[i].task_name << " ";
			ostr << std::setw(13) << std::right << t_tasks.m_task[i].task_duration.count() << " " << t_tasks.m_task[i].unit_name << "\n";
		}

		return ostr << "--------------------------\n";
	}
}