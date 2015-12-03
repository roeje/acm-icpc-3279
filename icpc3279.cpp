//
// Created by Jesse on 12/3/2015.
//

#include <iostream>
#include <sstream>
#include <istream>

using namespace std;

/*Recursive function that calculates score for each roll*/
void read_data(istream& data) {

    string player1, player2, prediction;
    int playerOneScore = 0;
    int playerTwoScore = 0;
    int rolls, predictTemp, c;

    data >> player1 >> player2 >> prediction;

    /*Base case*/
    if (player1 == "#" && player2 == "#" && prediction == "#") {
        return;
    }

    /*Converts prediction into an integer used to compare during the roll evaluation*/
    if (prediction == "even")
        predictTemp = 0;
    else
        predictTemp = 1;

    data >> rolls;

    /*Handles each roll of the die*/
    while (rolls > 0) {
        data >> c;
        int temp;

        /*Calculates even or odd and converts to uniform integer value*/
        if (c % 2 == 0) {
            temp = 0;
        }
        else
        {
            temp = 1;
        }

        /*Increments player score for current roll*/
        if (temp == predictTemp) {
            playerTwoScore++;
        }
        else {
            playerOneScore++;
        }
        rolls--;
    }

    /*Output results for this round and enter next recursion*/
    cout << player1 << " " << to_string(playerOneScore) << " " << player2 << " " << to_string(playerTwoScore) << endl;
    read_data(data);
}

/*Handles data and calls solution function*/
int main() {
#ifndef ONLINE_JUDGE
    string testData = "Bill Susan even\n"
            "8\n"
            "1 6 5 3 4 2 5 5\n"
            "Sarah Tony odd\n"
            "15\n"
            "2 4 5 4 3 6 1 2 5 4 3 1 2 5 6\n"
            "# # #";

    istringstream data (testData);
#else
    istream& data = cin;
#endif
    read_data(data);
}

//Bill Susan even
//8
//1 6 5 3 4 2 5 5
//Sarah Tony odd
//15
//2 4 5 4 3 6 1 2 5 4 3 1 2 5 6
//# # #


