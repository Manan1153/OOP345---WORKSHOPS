#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>

const int noOfWords = 6;

namespace sdds
{
	class SpellChecker
	{
		std::string m_badWords[noOfWords]{};
		std::string m_goodWords[noOfWords]{};
		int m_replaceCount[noOfWords]{};
		
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStastics(std::ostream& out) const;
	};
}
#endif // !SDDS_SPELLCHECKER_H
