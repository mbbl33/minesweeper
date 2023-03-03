//
// Created by biebl on 29.03.2022.
//

#include "LogicCore.h"

/**
 * legt das LogicCore fuer Minesweeper an
 * @param height hoehe des feld
 * @param width breite des feld
 * @param mines anzahl der minen
 */
LogicCore::LogicCore(int height = 10, int width = 10, int mines = 10) {
    this->width = width;
    setupBoards(height, width);
    setupMines(mines);
}

/**
 * generiert Spielfeld
 * @param height hoehe des feld
 * @param width breite des feld
 */
void LogicCore::setupBoards(int height, int width) {
    int size = height * width;
    for (int i = 0; i < size; ++i) {
        board.push_back(0);
    }
}

void LogicCore::setupMines(int mineNumber) {
    srand(time(NULL));
    int r;
    //if (board.size() / 2 < mineNumber) mineNumber = board.size() / 2;
    do {
        r = rand() % board.size();
        board[r] = -1;
    } while (countAllMines() < mineNumber);
    setMineCounts();
}

void LogicCore::setMineCounts() {
    for (int i = 0; i < board.size(); ++i) {
        if (board.at(i) == -1) {

        }
    }
}

enum Direction {
    N, NE, E, SE, S, SW, W, NW
};

int getNeighbour(int pos, Direction d) {
    int neighbour;
    switch (d) {
        case N:
            neighbour = pos - widh;
            break;
        case NE:
            neighbour = pos - width + 1;
            break;
        case E:
            neighbour = pos + 1:
            break;
        case SE:
            neighbour = pos + width + 1;
            break;
        case S:
            neighbour = pos + width;
            break;
        case SW:
            neighbour = pos + width - 1;
            break;
        case W:
            neighbour = pos - 1:
            break;
        case NW:
            neighbour = pos - width - 1;
    }
    return 0 <= neighbour && neighbour < board.size ? neighbour : -1;
}

int LogicCore::countAllMines() {
    int count = 0;
    for (auto &item: board) {
        if (item == -1) ++count;
    }
    return count;
}


ostream &operator<<(ostream &s, const LogicCore &lc) {
    for (int i = 0; i < lc.board.size(); i++) {
        if (i % lc.width == 0 && 0 < i) {
            s << "|" << endl;
        }
        s << "|\t" << lc.board.at(i) << "\t";

    }
    return s << "|";
}

