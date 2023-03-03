//
// Created by biebl on 29.03.2022.
//

#ifndef MINESWEEPER_LOGICCORE_H
#define MINESWEEPER_LOGICCORE_H


#include "LogicCore.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;


class LogicCore {
    friend ostream &operator<<(ostream &, const LogicCore &);

    int width;
    vector<int> board;
public:
    LogicCore(int, int, int);

    void setupBoards(int, int);

    void setupMines(int);

    int countAllMines();

    void setMineCount(int);

};


#endif //MINESWEEPER_LOGICCORE_H
