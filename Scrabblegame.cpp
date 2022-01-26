#include "./Scrabblegame.h"

ScrabbleGame::ScrabbleGame() {
    this->setDoubleLetters();
    this->setDoubleWords();
    this->setTripleLetters();
    this->setTripleWords();
}

void ScrabbleGame::setDoubleLetters() {
    board[0][3].setBonus("2L");
    board[0][11].setBonus("2L");
    board[2][6].setBonus("2L");
    board[2][8].setBonus("2L");
    board[3][0].setBonus("2L");
    board[3][7].setBonus("2L");
    board[3][14].setBonus("2L");
    board[6][2].setBonus("2L");
    board[6][6].setBonus("2L");
    board[6][8].setBonus("2L");
    board[6][12].setBonus("2L");
    board[7][3].setBonus("2L");
    board[7][11].setBonus("2L");
    board[8][2].setBonus("2L");
    board[8][6].setBonus("2L");
    board[8][8].setBonus("2L");
    board[8][12].setBonus("2L");
    board[11][0].setBonus("2L");
    board[11][7].setBonus("2L");
    board[11][14].setBonus("2L");
    board[12][6].setBonus("2L");
    board[12][8].setBonus("2L");
    board[14][3].setBonus("2L");
    board[14][11].setBonus("2L");
}

void ScrabbleGame::setTripleLetters() {
    board[1][5].setBonus("3L");
    board[1][9].setBonus("3L");
    board[5][1].setBonus("3L");
    board[5][5].setBonus("3L");
    board[5][9].setBonus("3L");
    board[5][13].setBonus("3L");
    board[9][1].setBonus("3L");
    board[9][5].setBonus("3L");
    board[9][9].setBonus("3L");
    board[9][13].setBonus("3L");
    board[13][5].setBonus("3L");
    board[13][9].setBonus("3L");
}

void ScrabbleGame::setDoubleWords() {
    for (int i = 1; i < 5; i++) {
        board[i][i].setBonus("2W");
        board[14 - i][i].setBonus("2W");
    }

    for (int j = 10; j < 14; j++) {
        board[j][j].setBonus("2W");
        board[14 - j][j].setBonus("2W");
    }
    board[7][7].setBonus("*");
}

void ScrabbleGame::setTripleWords() {
    for (int i = 0; i < 15; i += 7)
        for (int j = 0; j < 15; j += 7)
            board[i][j].setBonus("3W");
}

int ScrabbleGame::returnBonus(Slot slot) {
    std::string typeBonus = slot.getBonus();
    if (typeBonus == "2L")
        return 2;
    if (typeBonus == "3L")
        return 3;
    if (typeBonus == "*" || typeBonus == "2W")
        multiplier *= 2;
    if (typeBonus == "3W")
        multiplier *= 3;
}

int ScrabbleGame::letterScore(char letter) {
    if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'L' || letter == 'N' || letter == 'O' || letter == 'R'
        || letter == 'S' || letter == 'T' || letter == 'U')
        return 1;
    if (letter == 'D' || letter == 'G')
        return 2;
    if (letter == 'B' || letter == 'C' || letter == 'M' || letter == 'P')
        return 3;
    if (letter == 'F' || letter == 'H' || letter == 'V' || letter == 'W' || letter == 'Y')
        return 4;
    if (letter == 'K')
        return 5;
    if (letter == 'J' || letter == 'X')
        return 8;
    if (letter == 'Q' || letter == 'Z')
        return 10;
}

int ScrabbleGame::WordValue(std::string word) {
    int points = 0;
    int value = 0;

    for (char character : word) {
        value = letterScore(character - 32);
        if (value == 0)
            return 0;
        points += value;
    }
    return points;
}

std::vector<std::string> ScrabbleGame::getDictionary() {
    std::ifstream file("words.txt");
    std::string line;
    std::vector<std::string> dictionary;
    int i = 0;
    while (getline(file, line)) {
        dictionary.push_back(line);
    }
    return dictionary;
}

bool ScrabbleGame::isWord(std::string& word) {
    std::vector<std::string> dictionar = getDictionary();
    for (std::string& dic : dictionar) {
        if (word.compare(dic) == 0)
            return true;
    }
    return false;
}

void ScrabbleGame::setChecked(std::vector<std::string> words) {
    for (int i = 0; i < words.size(); i++) {
        this->isChecked.push_back(false);
    }
}

int ScrabbleGame::findScore(char board[15][15]) {
    this->score = 0;
    std::vector<std::string> words = getDictionary();
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            //std::cout << board[i][j] << " "; //Board verification for manual check
            for (int k = 0; k < words.size(); k++)
            {
                if (board[i][j] == words[k][0])
                {
                    for (int l = 1; l <= words[k].size(); l++)
                    {
                        if (board[i - l][j] != words[k][l] && board[i + l][j] != words[k][l] && board[i][j + l] != words[k][l] &&
                            board[i][j - l] != words[k][l] && board[i + l][j + l] != words[k][l] && board[i - l][j - l] != words[k][l] &&
                            board[i + l][j - l] != words[k][l] && board[i - l][j + l] != words[k][l])
                        {
                            break;
                        }
                        else if (l == words[k].size() - 1)
                        {
                            int counter2 = 0;
                            for (int counter = 0; counter < wordsFound.size(); counter++) {
                                if (words[k] == wordsFound[counter]) { //duplicate checker
                                    counter2++;
                                    break;
                                }
                            }
                            if (counter2 == 0) {
                                this->score += this->WordValue(words[k]);
                                std::vector<int> location;
                                location.push_back(i);
                                location.push_back(j);
                                locations.push_back(location);
                                wordsFound.push_back(words[k]); //Remember the found wordsS
                            }
                        }
                    }
                }
            }
        }
    }
    return score;
}

int ScrabbleGame::checkBoard(char data[15][15]) {
    setChecked(getDictionary());
    return findScore(data);
}