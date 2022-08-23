#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include "Car.h"
using namespace std;
namespace sdds
{
	//constructor
	Car::Car(std::istream& is) {
		string tag;
		string speed;
		string substr;
		getline(is, substr, '\n');
		is.seekg(0);
		//tag
		tag = trim(extract(substr, ","));
		substr.erase(0, substr.find(",") + 1);
		//condition of the car
		_condition = trim(extract(substr, ","));
		substr.erase(0, substr.find(',') + 1);
		if (_condition == "n" || _condition == "")
		{
			_condition = "new";
		}
		else if (_condition == "u")
		{
			_condition = "used";
		}
		else if (_condition == "b")
		{
			_condition = "broken";
		}
		else
		{
			throw "Invalid Record";
		}

		try
		{
			speed = trim(extract(substr, ","));
			substr.erase(0, substr.find(',') + 1);
			for (char const& c : speed)
			{
				if (std::isdigit(c) == 0) {
					throw "Invalid Record";
				}
			}
			stringstream ss(speed);
			ss >> _topSpeeed;
		}
		catch (const std::exception&)
		{
			throw "Invalid Records!";
		}
	}

	//destructor
	Car::~Car() {

	}

	//getter
	std::string Car::condition()const {
		return _condition;
	}
	double Car::topSpeed() const {
		return _topSpeeed;
	}

	//print
	void Car::display(std::ostream& out) const {
		out << " | ";
		out << std::right;
		out.width(10);
		out << _maker;
		out << " | ";

		out.width(6);
		out << std::left;
		out << condition();
		out << " | ";

		out.width(6);
		out << std::right;
		out << std::fixed;
		out << std::setprecision(2);
		out << topSpeed();
		out << " |";
	}


	//helpers
	string extract(string str, string delimeter) {
		string str_extract;
		str_extract = str.substr(0, str.find(delimeter));
		return str_extract;
	}
	string trim(string str) {
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
		return str;
	}
}