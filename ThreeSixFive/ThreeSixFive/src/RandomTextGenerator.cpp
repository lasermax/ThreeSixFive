#include "RandomTextGenerator.h"
#include <iostream>

RandomTextGenerator::RandomTextGenerator() 
{

}

RandomTextGenerator::RandomTextGenerator(const std::string& filename) 
	: m_filename(filename)
{

}

void RandomTextGenerator::randomFile(int letterCount, LetterRange lr) 
{	
	std::ofstream file;
	
	if (m_filename.empty()) {
		m_filename = "RandomCharacters.txt";
	}

	std::string randText = randomString(letterCount, lr);

	file.open(m_filename, std::ofstream::out | std::ofstream::trunc);

	if (file.is_open()) {
		file << randText << std::endl;
		file.close();
	}
}

std::vector<char> getCharacterPool(RandomTextGenerator::LetterRange lr);

std::string RandomTextGenerator::randomString(int letterCount, LetterRange lr) 
{
	std::vector<char> characterPool = getCharacterPool(lr);
	srand(time(NULL));

	std::string randString;

	for (; letterCount > 0; letterCount--) {
		unsigned int r = rand();
		r %= characterPool.size();
		char test = characterPool[r];
		randString.append(1u, test);
	}

	return randString;
}

std::vector<char> getCharacterPool(RandomTextGenerator::LetterRange lr)
{
	std::vector<char> characterPool;
	switch (lr) {
	case RandomTextGenerator::alpha:
		for (char c = 'A'; c <= 'Z'; c++) {
			characterPool.push_back(c);
			characterPool.push_back(c + 32);
		}
		break;
	case RandomTextGenerator:: numeric:
		for (char c = '0'; c <= '9'; c++)
			characterPool.push_back(c);
		break;
	case RandomTextGenerator::alphanumeric:
		for (char c = '0'; c <= '9'; c++)
			characterPool.push_back(c);
		for (char c = 'A'; c <= 'Z'; c++) {
			characterPool.push_back(c);
			characterPool.push_back(c + 32);
		}
		break;
	case RandomTextGenerator::specialchar:
		for (char c = -127; c < 127; c++) {
			characterPool.push_back(c);
		}
		break;
	}
	for (char c : characterPool) {
	}
	return characterPool;
}

void RandomTextGenerator::setFilename(const std::string& filename) 
{
	m_filename = filename;
}
