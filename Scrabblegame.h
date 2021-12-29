#ifndef __SCRABBLEGAME_H__
#define __SCRABBLEGAME_H__

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "./Slot.h"
#include "./Player.h"

class ScrabbleGame{
    private:
    int words = 0;
    int score = 0;
    int multiplier = 1;
    std::vector<std::string> dictionary[40];
    Slot board[15][15];
    std::string lettersOnBoard();

    Player player;
    public:
    void setDoubleLetters();
    void setTripleLetters();
    void setDoubleWords();
    void setTripleWords();

    int returnBonus(Slot slot);
    int letterScore(char character);
    int WordValue(std::string word);
    
    ScrabbleGame();
};
#endif // __SCRABBLEGAME_H__