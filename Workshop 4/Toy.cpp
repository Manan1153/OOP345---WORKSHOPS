#define  _CRT_SECURE_NO_WARNINGS
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstring>
#include <functional>
#include <iomanip>
#include "Toy.h"
using namespace std;

namespace sdds
{
	Toy::Toy() {};

	Toy::Toy(const string& toy) {

		//get info from toy and store to members
		//local temporary variables to help extract data

		size_t start_pos{};
		size_t end_pos{};
		std::string s = toy;

		//set order id
		m_orderID = stoi(s);

		//set name
		start_pos = s.find(':');
		s = s.substr(start_pos + 1);
		start_pos = 0;
		end_pos = s.find(':');
		m_name = s.substr(start_pos, end_pos);

		//delete leading and trailing spaces, taken from StackOverFlow
		m_name.erase(m_name.begin(), find_if(m_name.begin(), m_name.end(), bind1st(not_equal_to<char>(), ' ')));

		m_name.erase(std::find_if(m_name.rbegin(), m_name.rend(), bind1st(not_equal_to<char>(), ' ')).base(), m_name.end());

		//set items Num
		start_pos = s.find(':');
		s = s.substr(start_pos + 1);
		s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
		m_itemsNum = stoi(s);

		//set price
		start_pos = s.find(':');
		s = s.substr(start_pos + 1);
		m_price = stod(s);
	}

	void Toy::update(int numItems) {
		m_itemsNum = numItems;
	}

	ostream& Toy::write(ostream& ostr)const {
		double subtotal = m_price * m_itemsNum;
		double tax = subtotal * HST / 100;
		double total = subtotal + tax;
		
		ostr << "Toy" << m_orderID << ":";
		ostr.setf(ios::right);
		ostr.width(18);
		ostr << m_name;

		ostr.width(3);
		ostr << m_itemsNum;
		ostr << "items";

		ostr.width(8);
		ostr << fixed << std::setprecision(2) << m_price;
		ostr << "/items subtotal: ";

		ostr.width(6);
		ostr << subtotal;
		ostr << " tax: ";

		ostr.width(5);
		ostr << subtotal * HST / 100;
		ostr<< " total: ";
		ostr.width(6);
		ostr << total << endl;
		ostr.unsetf(ios::right);
		return ostr;
	}

	ostream& operator<<(ostream& ostr, const Toy& rightOperand) {
		rightOperand.write(ostr);
		return ostr;
	}
}