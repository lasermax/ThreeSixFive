#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

class RandomTextGenerator
{
public:
	enum LetterRange{
		alpha,
		numeric,
		alphanumeric,
		specialchar
	};

	RandomTextGenerator();
	RandomTextGenerator(const std::string& filename);

	void randomFile(int letterCount, LetterRange lr);
	std::string randomString(int letterCount, LetterRange lr);

	void setFilename(const std::string& filename);
private:
	std::string m_filename;
};