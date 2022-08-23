#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Utilities.h"
#include "Racecar.h"


using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in) {
		std::string strCar;
		Vehicle* v = nullptr;

		std::getline(in, strCar, '\n');
		strCar = trim(strCar);

		if (in)
		{
			if (strCar[0] == 'c' || strCar[0] == 'C') {
				stringstream aCar(strCar);
				v = new Car(aCar);
			}
			else if (strCar[0] == 'r' || strCar[0] == 'R')
			{
				stringstream aRacecar(strCar);
				v = new Racecar(aRacecar);
			}
			else
			{
				throw strCar[0];
			}
		}
		return v;
	}
}