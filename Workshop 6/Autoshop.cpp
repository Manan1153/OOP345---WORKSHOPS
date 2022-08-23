#include <iostream>
#include <vector>
#include "Autoshop.h"
using namespace std;
namespace sdds
{
	//operator overload
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	//destruct
	Autoshop::~Autoshop() {
		for (auto ptr=m_vehicles.begin(); ptr<m_vehicles.end();ptr++)
		{
			delete* ptr;
		}
	}

	//print
	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;

		for (auto ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++)
		{
			(*ptr)->display(out);
			out << endl;
		}
		out << "--------------------------------" << endl;

	}
}