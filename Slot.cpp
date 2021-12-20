#include "./Slot.h"

std::string Slot::getBonus() {
    return this->bonus;
}

char Slot::getLetter() {
    return this->letter; 
}

bool Slot::get_isReserved() {
    return this->isReserved;
}

void Slot::setBonus(std::string newBonus) {
    this->bonus = newBonus;
}

void Slot::setLetter(char newLetter) {
    this->letter = newLetter;
    isReserved = true;
}

void Slot::set_isReserved(bool new_isReserved) {
    this->isReserved = isReserved;
}

std::string Slot::toString() {
    std::string string = " ";
        if (isReserved) {
            string.push_back(letter);
            string.push_back(' ');
        }
        else if (bonus != "")
            string = string + bonus;
        else
            string = "_";
        return string;
    }
