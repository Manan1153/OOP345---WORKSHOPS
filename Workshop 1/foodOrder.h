#ifndef SDDS_FOOD_ORDER_H
#define SDDS_FOOD_ORDER_H


extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds
{
	class FoodOrder
	{
		char m_customerName[10];
		char* m_foodDescription{};
		double m_price;
		bool m_Special;
	};
}

#endif // !SDDS_FOOD_ORDER_H
