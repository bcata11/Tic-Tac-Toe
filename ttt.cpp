#include <iostream>
#include "ttt.hpp"

using namespace std;

int main() {
    bool gameOn = true;
    int turn = 0;
    string grid = reset();

    introduction();

    while (gameOn) {
        turn++;
        grid = playerInput(turn, grid);
        drawGrid(grid);
        gameOn = !checkWin(grid);
    }

    endGame(turn);
}