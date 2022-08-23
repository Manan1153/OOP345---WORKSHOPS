#include <iostream>
#ifndef _PROTEINDATABASE_H
#define _PROTEINDATABASE_H

using namespace std;

namespace sdds
{
	class ProteinDatabase
	{
	public:
		string* records = nullptr;

		long unsigned int count = 0;
		long unsigned int i = 0;

		ProteinDatabase();
		~ProteinDatabase();

		ProteinDatabase(char* f_name);

		size_t size();
		std::string operator[](size_t);

		ProteinDatabase(const ProteinDatabase& src);

		ProteinDatabase(ProteinDatabase&& src);

		ProteinDatabase& operator=(const ProteinDatabase&);
		ProteinDatabase& operator=(ProteinDatabase&&);
	};
}

#endif // !_PROTEINDATABASE_H
