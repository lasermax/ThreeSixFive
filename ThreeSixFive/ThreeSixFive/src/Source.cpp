#pragma once
#include "RandomTextGenerator.h"
#include <iostream>

int main(int argc, char* argv[]) {
	RandomTextGenerator rtm;
	std::cout << std::endl;
	rtm.randomFile(5, RandomTextGenerator::LetterRange::alpha);
}