/*
    A program that imitates a game where you have a ball and 3 thimbles.
    Each of the three types of moves affect to thimbles and change their positions with each other.
    The input file has a string of moves (e.g. ABCBCACBBC), the output has the number of the thimble with the ball.
    By default the ball is under the first thimble.
*/

#include <iostream>
#include <string>

int ballPosition(int a, int b) { // Function that takes a number of move and current position of the ball.
    bool Pucs[3] = { 0, 0, 0 };
    bool temp;
    int retCup;
    Pucs[b] = 1;
    switch (a) {
    case 1:
        temp = Pucs[0];
        Pucs[0] = Pucs[1];
        Pucs[1] = temp;
        break;
    case 2:
        temp = Pucs[1];
        Pucs[1] = Pucs[2];
        Pucs[2] = temp;
        break;
    case 3:
        temp = Pucs[0];
        Pucs[0] = Pucs[2];
        Pucs[2] = temp;
        break;
    }
    for (int j = 0; j < 3; j++) {
        if (Pucs[j] == 1) retCup = j;
    }
    return retCup; // Returning the position of the ball.
}

int main()
{
    int numOfMove, currentCup{ 0 };
    std::string Moves; // string of A, B, C - chars from 65 to 67.
    bool Cups[3] = { 1, 0, 0 }; // an array of 3 elements (3 cups), e.g. if the ball is under 1st cup, the 1st element is TRUE.
    std::cin >> Moves;

    for (int i = 0; i < Moves.size(); i++) {
        numOfMove = Moves.at(i) - '@'; // Subtracting '@' (64) from our letter to get 1, 2 or 3.
        currentCup = ballPosition(numOfMove, currentCup);
    }

    std::cout << currentCup + 1 << "\n";

    return 0;



}
