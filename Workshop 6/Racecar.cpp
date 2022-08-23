#include <iostream>
#include <string>
#include <sstream>
#include "Racecar.h"

using namespace std;
namespace sdds
{
	//constructor
	Racecar::Racecar(istream& in) : Car(in) {
		string ss;
		getline(in, ss);
		string booster = ss.substr(ss.find_last_of(",") + 1);		//extract booster end of string
		stringstream str(booster);
		str >> m_booster;		//string to double through stringstream
	}

	//destructor
	Racecar::~Racecar() {}

	//print
	void Racecar::display(ostream& out) const {
		Car::display(out);
		out << "*";
	}

	//getter
	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}