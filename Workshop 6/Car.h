#ifndef _SDDS_CAR_H
#define _SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string _maker = "";
		std::string _condition = "";
		double _topSpeeed = 0;

	public:
		//constructor
		Car(std::istream& in);
		//destructor
		~Car();
		//getters
		std::string condition() const;
		double topSpeed() const;
		//print
		void display(std::ostream& out) const;
	};
	//helpers
	std::string extract(std::string str, std::string delimeter);
	std::string trim(std::string str);
}
#endif // !_SDDS_CAR_H
