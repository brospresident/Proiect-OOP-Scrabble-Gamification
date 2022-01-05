#ifndef __SLOT_H__
#define __SLOT_H__
#include <iostream>
#include <stdbool.h>
#include <string.h>

//The Slot class checks if a slot is ocuppied by a letter and encounters if we find a bonus letter/word on it
class Slot {
private:
    char letter;
    bool isReserved;
    std::string bonus;
public:
    std::string getBonus();
    void setBonus(std::string bonus);

    char getLetter();
    void setLetter(char letter);

    bool get_isReserved();
    void set_isReserved(bool isReserved);

    std::string toString();
    //Getters and setters
};
#endif // __SLOT_H__