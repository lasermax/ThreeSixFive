#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

class RandomTextGenerator
{
public:
	enum class LetterRange{
		alpha,
		numeric,
		alphanumeric,
		specialchar
	};

	RandomTextGenerator(const std::string& filename = "RandomCharacters.txt");

	~RandomTextGenerator();

	void randomFile(int letterCount, const LetterRange &lr) const;
	std::string* randomString(int& letterCount, const LetterRange& lr) const;

	void setFilename(const std::string& filename);
private:
	std::string m_filename;

	std::vector<char>* getCharacterPool(const LetterRange& lr) const;
};