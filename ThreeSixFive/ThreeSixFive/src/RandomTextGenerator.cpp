#include "RandomTextGenerator.h"

#include "Instrumenter.h"

RandomTextGenerator::RandomTextGenerator(const std::string& filename)
	: m_filename(filename)
{
	BEGIN_PROFILING("RandomTextGenerator");
}

RandomTextGenerator::~RandomTextGenerator() 
{
	END_PROFILING;
}

void RandomTextGenerator::randomFile(int letterCount, const LetterRange &lr) const
{	
	PROFILE_FUNCTION;
	std::string* randText = randomString(letterCount, lr);

	std::ofstream file;
	file.open(m_filename, std::ofstream::out | std::ofstream::trunc);

	if (file.is_open()) {
		file << *randText;
		file.close();
	}
}

std::string* RandomTextGenerator::randomString(int& letterCount, const LetterRange& lr) const
{
	PROFILE_FUNCTION;

	std::vector<char>* characterPool = getCharacterPool(lr);
	srand(time(NULL));

	std::string* randString = new std::string;

	for (; letterCount > 0; letterCount--) {
		unsigned int r = rand();
		r %= characterPool->size();
		char test = (*characterPool)[r];
		*randString += test;
	}

	return randString;
}

void RandomTextGenerator::setFilename(const std::string& filename)
{
	PROFILE_FUNCTION;
	m_filename = filename;
}

std::vector<char>* RandomTextGenerator::getCharacterPool(const LetterRange& lr) const
{
	PROFILE_FUNCTION;

	std::vector<char> *characterPool = new std::vector<char>;
	
	switch (lr) {
		case LetterRange::alpha:
			characterPool->reserve(52);
			for (char c = 'A'; c <= 'Z'; c++) {
				characterPool->push_back(c);
				characterPool->push_back(c + 32);
			}
			break;
		case LetterRange::numeric:
			characterPool->reserve(10);
			for (char c = '0'; c <= '9'; c++)
				characterPool->push_back(c);
			break;
		case LetterRange::alphanumeric:
			characterPool->reserve(62);
			for (char c = '0'; c <= '9'; c++)
				characterPool->push_back(c);
			for (char c = 'A'; c <= 'Z'; c++) {
				characterPool->push_back(c);
				characterPool->push_back(c + 32);
			}
			break;
		case LetterRange::specialchar:
			characterPool->reserve(256);
			for (char c = -127; c < 127; c++) {
				characterPool->push_back(c);
			}
			break;
	}
	return characterPool;
}

