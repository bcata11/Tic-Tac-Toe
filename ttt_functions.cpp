#include <iostream>
#include <vector>

using namespace std;

void drawGrid(string grid)
{
    for (int i = 0; i < 9; i += 3)
    {
        cout << grid[i] << " | " << grid[i + 1] << " | " << grid[i + 2] << "\n";
    }
    cout << "\n";
}

string reset()
{
    string reset = "_________";
    return reset;
}

void introduction()
{
    cout << "*****************\n";
    cout << "***Tic Tac Toe***\n";
    cout << "*****************\n\n";

    string sample = "123456789";
    drawGrid(sample);

    cout << "\n\n";
}

string playerInput(int turn, string grid)
{
    int input;
    char choice;
    int player = 1;

    if (turn % 2 == 0)
    {
        choice = 'X';
        player = 2;
    }
    else
    {
        choice = 'O';
    }

    cout << "player " << player << " turn, enter a number between 1 and 9: ";
error:
    cin >> input;
    if (input > 9 || input < 1 || grid[input - 1] != '_')
    {
        cout << "Wrong input";
        goto error;
    }
    grid[input - 1] = choice;
    return grid;
}

bool checkWin(string grid)
{
    for (int i = 0; i <= 9; i += 3)
    {
        if (grid[i] == grid[i + 1] && grid[i + 1] == grid[i + 2] && grid[i] != '_')return true;
        if (grid[i] == grid[i + 3] && grid[i + 3] == grid[i + 6] && grid[i] != '_')return true;
    }
    if (grid[0] == grid[4] && grid[4] == grid[8] && grid[0] != '_')return true;
    if (grid[2] == grid[4] && grid[4] == grid[6] && grid[2] != '_')return true;
        

    cout<< "no winner\n";
    return false;
}

void endGame(int turn){
    int player = 1;
    if(turn%2==0) player = 2;
    cout << "End of the game, player " << player << " is the winner\n";
}
