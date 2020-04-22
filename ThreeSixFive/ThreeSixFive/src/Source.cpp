#pragma once
#include "RandomTextGenerator.h"

int main(int argc, char* argv[]) {
	RandomTextGenerator rtm("Test.txt");

	rtm.randomFile(500, RandomTextGenerator::LetterRange::alpha);
}