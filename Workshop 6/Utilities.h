#ifndef _SDDS_UTILITIES_H
#define _SDDS_UTILITIES_H
#include <iostream>
#include "Vehicle.h"
#include "Car.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}
#endif // !_SDDS_UTILITIES_H