#ifndef __SCRABBLEGAME_H__
#define __SCRABBLEGAME_H__

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "./Slot.h"
#include "./Player.h"

class ScrabbleGame {
private:
    int words = 0;
    int score = 0;
    int multiplier = 1;
    std::vector<std::string> dictionary[40];
    Slot board[15][15];
    std::string lettersOnBoard();

    Player player;
public:
    char calculateBoard[15][15];
    std::vector<bool> isChecked;
    std::vector<std::string> wordsFound;
    std::vector<std::vector<int>> locations;

    void setDoubleLetters();
    void setTripleLetters();
    void setDoubleWords();
    void setTripleWords();

    int returnBonus(Slot slot);
    int letterScore(char character);
    int WordValue(std::string word);

    std::vector<std::string> getDictionary();

    bool isWord(std::string& word);

    void setChecked(std::vector<std::string> words);
    int findScore(char board[15][15]);

    int checkBoard(char data[15][15]);

    ScrabbleGame();
};
#endif // __SCRABBLEGAME_H__