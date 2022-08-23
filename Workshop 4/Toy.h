#ifndef SDDS_TOY_H
#define SDDS_TOY_H

#include <iostream>
#include <string>

namespace sdds
{
	class Toy
	{
	private:
		unsigned int m_orderID{};
		std::string m_name{};
		int m_itemsNum{};
		double m_price{};
		const int HST = 13;

	public:
		Toy();
		void update(int numItems);
		Toy(const std::string& toy);

		std::ostream& write(std::ostream& ostr)const;
		friend std::ostream& operator<<(std::ostream& ostr, const Toy& rightOperand);
	};
}
#endif // !SDDS_TOY_H
