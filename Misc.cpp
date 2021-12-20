#include <iostream>
#include <string>

#include "Misc.h"

// TODO support pentru cifre
std::string Misc::keyCodeToString (int key) {
	switch (key) {
	case 0:
		return "a";
	case 1:
		return "b";
	case 2:
		return "c";
	case 3:
		return "d";
	case 4:
		return "e";
	case 5:
		return "f";
	case 6:
		return "g";
	case 7:
		return "h";
	case 8:
		return "i";
	case 9:
		return "j";
	case 10:
		return "k";
	case 11:
		return "l";
	case 12:
		return "m";
	case 13:
		return "n";
	case 14:
		return "o";
	case 15:
		return "p";
	case 16:
		return "q";
	case 17:
		return "r";
	case 18:
		return "s";
	case 19:
		return "t";
	case 20:
		return "u";
	case 21:
		return "v";
	case 22:
		return "w";
	case 23:
		return "x";
	case 24:
		return "y";
	case 25:
		return "z";
	default:
		return "";
	}
}

std::string Misc::toUpperCase (int key) {
	switch (key) {
	case 0:
		return "A";
	case 1:
		return "B";
	case 2:
		return "C";
	case 3:
		return "D";
	case 4:
		return "E";
	case 5:
		return "F";
	case 6:
		return "G";
	case 7:
		return "H";
	case 8:
		return "I";
	case 9:
		return "J";
	case 10:
		return "K";
	case 11:
		return "L";
	case 12:
		return "M";
	case 13:
		return "N";
	case 14:
		return "O";
	case 15:
		return "P";
	case 16:
		return "Q";
	case 17:
		return "R";
	case 18:
		return "S";
	case 19:
		return "T";
	case 20:
		return "U";
	case 21:
		return "V";
	case 22:
		return "W";
	case 23:
		return "X";
	case 24:
		return "Y";
	case 25:
		return "Z";
	default:
		return "";
	}
}

std::string Misc::removeLastCharacter(std::string str) {
	return str.substr(0, str.size() - 1);
}

std::vector<std::string> Misc::randomCharList() {
	std::vector<std::string> list;
	srand(time(NULL));
	int randNumber = rand() % 21;
	int randNumber2 = rand() % 5;
	std::string l = this->keyCodeToString(randNumber);
	list.push_back(l);

	while (list.size() < 4) {
		srand(randNumber);
		randNumber = consonants[rand() % 21];
		std::string l = this->keyCodeToString(randNumber);
		list.push_back(l);
	}

	while (list.size() < 7) {
		srand(randNumber2);
		randNumber2 = vowels[rand() % 5];
		std::string l = this->keyCodeToString(vowels[rand() % 5]);
		list.push_back(l);
	}

	return list;
}
