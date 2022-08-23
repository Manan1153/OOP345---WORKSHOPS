#ifndef SDDS_MOVIES_H
#define SDDS_MOVIES_H

#include <string>

namespace sdds
{
	class Movie
	{
		std::string m_title{};
		int m_release{};
		std::string m_desc{};
		std::string trim(std::string& str);

	public:
		Movie() {};
		const std::string& title() {};
		Movie(const std::string& strMovie);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);
			spellChecker(m_title);
		}

		friend std::ostream& operator<<(std::ostream&, const Movie&);
	};
}

#endif // !SDDS_MOVIES_H
