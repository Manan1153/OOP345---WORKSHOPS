
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include<string>

#include "ProteinDatabase.h"

using namespace std;

namespace sdds
{
	ProteinDatabase::ProteinDatabase() {}

	ProteinDatabase::~ProteinDatabase()
	{
		delete[] records;
	}

	ProteinDatabase::ProteinDatabase(char* f_name)
	{
		string line, name;

		ifstream fname(f_name);

		count = 0;
		records = nullptr;

		if (!fname)
		{
			return;
		}


		while (std::getline(fname, line).good())
		{
			if (line[0] == '>')
			{
				count++;
			}
		}

		fname.clear();
		fname.seekg(ios::beg);

		records = new string[count];

		line.clear();

		int i = -1;

		while (getline(fname, line).good())
		{
			if (line[0] == '>')
			{
				++i;
				name = line.substr(1);
			}

			else if (!name.empty())
			{
				records[i] = records[i] + line;
			}
		}
	}

	size_t ProteinDatabase::size()
	{
		return count;
	}

	std::string ProteinDatabase::operator[](size_t i)
	{
		if (i < count)
		{
			return records[i];
		}

		return "";
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& previous)
	{
		*this = move(previous);
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& previous)
	{
		*this = previous;
	}

	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& scr)
	{
		if (this != &scr)
		{
			delete[] records;
			records = nullptr;

			records = scr.records;
			scr.records = nullptr;

			count = scr.count;
			scr.count = 0;
		}

		return *this;
	}
	//move assignment operator
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& scr)
	{
		if (this != &scr)
		{
			delete[] records;
			count = scr.count;

			records = new string[count]{};

			for (long unsigned int i = 0; i < count; i++)
			{
				records[i] = scr.records[i];
			}
		}

		return *this;
	}
}