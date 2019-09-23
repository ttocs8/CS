#include <iostream>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDie(){ //Returns a random integer from 1 - 6
    int dieNum;
    dieNum = (rand() % 6) + 1;
    return dieNum;
}

int WagerInput(int wage){ //get the user input for wager
    cin >> wage;
    return wage;
}

int PointInput(int p){ //get the user input for their point
    cin >> p;
    return p;
}

void GameStats(int money, int wins, int losses){ //outputs final stats from the game
    double numGames = wins + losses; //total # of games
    cout << "Your final account balance is $" << money << endl;                                     /* Make sure the % is fixed with no decimals*/
    cout << "You won " << wins << " time out of " << numGames << " for a winning percentage of " << fixed << setprecision(0) << (wins/numGames)*100 << "%" << endl;
}

bool playOneGame(){ /////////MAIN GAME LOGIC//////////
    int point = 0, guess = 0, money = 100, wagerAmount = 0, wage = 0;
    int wins = 0, losses = 0;
    bool validWager, validPoint;

    while(wagerAmount != '0'){ //Play game as long as wager is NOT 0,
        cout << "Account Balance: $" << money << endl;
        cout << "Enter wager (0 to exit): ";
        wage = WagerInput(wagerAmount);

        if(wage == 0){
            break;
        }
        else if(wage <= money && wage > 0){ //Check to see if wager amount is valid (line 30 - 40)
             cout << endl;
        }
        else{   //**Error checking for wager value*/
            validWager = false;
            while(!validWager){
                cout << "Error: You must wager between $1 and $100 (type 0 to exit): ";
                wage = WagerInput(wagerAmount);
                if(wage <= money && wage > 0){ //if wager is now valid, stop the while loop and continue
                    cout << endl;
                    validWager = true;
                }
            }
        }

        cout << "Enter your point value (1 - 6): ";
        guess = PointInput(point); //user input of number 1 - 6

        if(guess >= 1 && guess <= 6){ //if guess is valid, continue
            cout << endl;
        }
        else {  //**Error checking for point value*
            validPoint = false;
            while(!validPoint){
                cout << "Error: Enter your point value, must be between 1 and 6: ";
                guess = PointInput(point);
                if(guess >= 1 && guess <= 6){ //if guess is now valid, stop the while loop and continue
                    cout << endl;
                    validPoint = true;
                }
            }
        }

        int die1 = rollDie(); //rolls dice 3 times, assigning a variable to each value and output each
        int die2 = rollDie();
        int die3 = rollDie();
        cout << "Roll #1 is " << die1 << endl;
        cout << "Roll #2 is " << die2 << endl;
        cout << "Roll #3 is " << die3 << endl;


        if(die1 == guess || die2 == guess || die3 == guess){ //checking to see if dice match user input, if so, add wager to balance
            money = money + wage; //update balance
            wins++; //update wins
            cout << "** You win! **" << endl;
        }
        else{
            money = money - wage; //update balance
            losses++; //update losses
            cout << "** You lose **" << endl;
        }
        if(money <= 0){ //if user is out of money, stop the game
            cout << "Game over, you are out of money!" << endl;
            break;
        }

    }

    GameStats(money, wins, losses); // outputs game stats

    if(wins !=0){ //if user has won a game, return true
        return true;
    }
    else if(losses != 0){ //if user has lost a game, return false
        return false;
    }
    return false;
}

void executeGame(){
    playOneGame();
}

int main(){
    srand(time(NULL)); //sets seed for random numbers

    executeGame(); //execute the full game

    return 0;
}

