#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>
namespace sdds
{
	class Book
	{

		std::string b_author{};
		std::string b_title{};
		std::string b_country{};
		size_t b_year{};
		double b_price{};
		std::string b_desc{};
		std::string trim(std::string& str);

	public:
		Book() {};
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		friend std::ostream& operator<<(std::ostream&, const Book&);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(b_desc);
		}
	};
}
#endif // !SDDS_BOOK_H
