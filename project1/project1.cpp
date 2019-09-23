/*
 * Project Title:
 * - (Not) Minesweeper
 * Description:
 * A minesweeper-like game where the player chooses a space on a board and has to avoids bombs.
 *
 * Developers:
 * - Scott Hunt - hunts5@mail.uc.edu
 * - Joe Monahan - monahanjc@mail.uc.edu
 *
 * Help Received:
 * N/A
 *
 * Developer comments: // Not optional
 *
 *
 */

#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <iomanip>


using namespace std;


int board1[10][10] = {{9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9}};
int board2[15][15] = {{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}};
int board3[25][25] = {{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
                      {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}};
int userChoice = 0;
int Rows = 0;
int Cols = 0;
int userX = 0;
int userY = 0;
int y = 1;


/* Function Name: InputBoardSize
 *
 * Function Description:
 * This function gets user input of which board they want; 1, 2, or 3 and sets the Rows and Columns of the board accordingly
 *
 * Parameters:
 * None
 *
 * return value:
 * None (void)
 *
 */
void InputBoardSize(){
    cout << "Choose Board Size (Type either 1 - 10x10, 2 - 15x15, or 3 - 25x25): ";
    cin >> userChoice;
    switch(userChoice){
        case 1:
            Rows = 10;
            Cols = 10;
            break;
         case 2:
            Rows = 15;
            Cols = 15;
            break;
         case 3:
            Rows = 25;
            Cols = 25;
            break;
         default:
            Rows = 0;
            Cols = 0;
            break;
    }
    system("cls");
}


/* Function Name: InitBombPosition
 *
 * Function Description:
 * This function randomly places a certain amount of bombs onto the board based off of board size
 *
 * Parameters:
 * None
 *
 * return value:
 * None (void)
 *
 */

int AdjacentBombCount() {
    int x = userX-1, y = userY-1;
    int adjBombCount = 0;
    switch(userChoice){
        case 1:
            if(board1[x-1][y] == -1) {
                ++adjBombCount;
            }
            if(board1[x][y-1] == -1) {
                ++adjBombCount;
            }
            if(board1[x-1][y-1] == -1) {
                ++adjBombCount;
            }
            if(board1[x+1][y] == -1) {
                ++adjBombCount;
            }
            if(board1[x][y+1] == -1) {
                ++adjBombCount;
            }
            if(board1[x+1][y+1] == -1) {
                ++adjBombCount;
            }
            if(board1[x+1][y-1] == -1) {
                ++adjBombCount;
            }
            if(board1[x-1][y+1] == -1) {
                ++adjBombCount;
            }
            break;
        case 2:
            if(board2[x-1][y] == -1) {
                ++adjBombCount;
            }
            if(board2[x][y-1] ==-1) {
                ++adjBombCount;
            }
            if(board2[x-1][y-1] == -1) {
                ++adjBombCount;
            }
            if(board2[x+1][y] == -1) {
                ++adjBombCount;
            }
            if(board2[x][y+1] == -1) {
                ++adjBombCount;
            }
            if(board2[x+1][y+1] == -1) {
                ++adjBombCount;
            }
            if(board2[x+1][y-1] == -1) {
                ++adjBombCount;
            }
            if(board2[x-1][y+1] == -1) {
                ++adjBombCount;
            }
            break;
        case 3:
            if(board3[x-1][y] == -1) {
                ++adjBombCount;
            }
            if(board3[x][y-1] == -1) {
                ++adjBombCount;
            }
            if(board3[x-1][y-1] == -1) {
                ++adjBombCount;
            }
            if(board3[x+1][y] == -1) {
                ++adjBombCount;
            }
            if(board3[x][y+1] == -1) {
                ++adjBombCount;
            }
            if(board3[x+1][y+1] == -1) {
                ++adjBombCount;
            }
            if(board3[x+1][y-1] == -1) {
                ++adjBombCount;
            }
            if(board3[x-1][y+1] == -1) {
                ++adjBombCount;
            }
            break;
      }
      return adjBombCount;

}

void InitBombPosition(){
    int posX, posY;
    int numBombs;
        switch(userChoice){
            case 1:
                numBombs = rand() % 25 + 10; // bombs take up about 1/4 of the area of board, at least 10 total
                for(int i = 0; i < numBombs; i++){
                    posX = rand() % 10;
                    posY = rand() % 10;
                    board1[posX][posY] = -1;
                }
                break;
            case 2:
                numBombs = rand() % 55 + 20; // bombs take up about 1/4 of the area of board, at least 20 total
                for(int i = 0; i < numBombs; i++){
                    posX = rand() % 15;
                    posY = rand() % 15;
                    board2[posX][posY] = -1;
                }
                break;

            case 3:
                numBombs = rand() % 155 + 60; // bombs take up about 1/4 of the area of board, at least 60 total
                for(int i = 0; i < numBombs; i++){
                    posX = rand() % 25;
                    posY = rand() % 25;
                    board3[posX][posY] = -1;
                }
                break;
            default:
                board1[0][0] = 9;
                board2[0][0] = 9;
                board3[0][0] = 9;
                break;
        }
}


/* Function Name: ResetBoard
 *
 * Function Description:
 * This function resets all the board cells to be empty
 *
 * Parameters:
 * None
 *
 * return value:
 * None (void)
 *
 */
void ResetBoard(){
    switch(userChoice){
        case 1:
            for(int i = 0; i < Rows; i++){
                for(int j = 0; j < Cols; j++){
                    board1[i][j] = 9; //reset all cells to [ ]
                }
            }
            break;
        case 2:
            for(int i = 0; i < Rows; i++){
                for(int j = 0; j < Cols; j++){
                    board2[i][j] = 9; //reset all cells to [ ]
                }
            }
            break;
        case 3:
            for(int i = 0; i < Rows; i++){
                for(int j = 0; j < Cols; j++){
                    board3[i][j] = 9; //reset all cells to [ ]
                }
            }
            break;
        default:
            for(int i = 0; i < Rows; i++){
                for(int j = 0; j < Cols; j++){
                    board1[i][j] = 9; //reset all cells to [ ]
                }
            }

    }

}



void CheckGameState(){
    bool gameState = true;
     for(int i = 0; i < Rows; i++){
        for(int j = 0; j < Cols; j++){
            if(board1[i][j] == 9){
                gameState = false;
            }
        }
     }
     if(gameState == false){
         y = 0;
         system("color 40");
         cout << "\n*GAME OVER*" << endl;
     }

}

void ShowSelectedSpace(){
    int x = userX-1, y = userY-1;
    switch(userChoice){
        case 1:
            for(int i = 0; i < Rows; i++){
                for(int j = 0; j < Cols; j++){      //check the board for the value
                    if(board1[x][y] != -1){
                        board1[x][y] = AdjacentBombCount(); //display how many bombs there are
                    }
                }
            }
            break;
        case 2:
            for(int i = 0; i < Rows; i++){
                for(int j = 0; j < Cols; j++){      //check the board for the value
                    if(board2[x][y] != -1){
                        board2[x][y] = AdjacentBombCount(); //display how many bombs there are
                    }
                }
            }
            break;
        case 3:
            for(int i = 0; i < Rows; i++){
                for(int j = 0; j < Cols; j++){      //check the board for the value
                    if(board3[x][y] != -1){
                        board3[x][y] = AdjacentBombCount();
                    }
                }
            }
            break;
    }
}

/* Function Name: PrintBoard
 *
 * Function Description:
 * This function calls the InitBombPosition function and prints out the board according to user input and bombs placed
 *
 * Parameters:
 * None
 *
 * return value:
 * None (void)
 *
 */
void PrintBoard(){
    system("color 80");//Background gray, text black
    switch(userChoice){
        case 1:
            for(int i = 0; i < Rows; i++){
                for(int j = 0; j < Cols; j++){
                    //cout << board1[i][j];
                    if(board1[userX-1][userY-1] == -1 && board1[i][j] == -1){ //GAME OVER
                        y = 0;
                        cout << "[***]"; //Prints out a bomb cell
                    }
                    else if(board1[i][j] == 1){
                        cout << "[ 1 ]";
                    }
                    else if(board1[i][j] == 2){
                        cout << "[ 2 ]";
                    }
                    else if(board1[i][j] == 3){
                        cout << "[ 3 ]";
                    }
                    else if(board1[i][j] == 4){
                        cout << "[ 4 ]";
                    }
                    else if(board1[i][j] == 5){
                        cout << "[ 5 ]";
                    }
                    else if(board1[i][j] == 6){
                        cout << "[ 6 ]";
                    }
                    else if(board1[i][j] == 7){
                        cout << "[ 7 ]";
                    }
                    else if(board1[i][j] == 8){
                        cout << "[ 8 ]";
                    }
                    else if(board1[i][j] == 0){
                        cout << "[   ]";
                    }
                    else {
                        cout << "[///]";
                    }

                }
                cout << endl;
            }
            break;
        case 2:
            for(int i = 0; i < Rows; i++){
                for(int j = 0; j < Cols; j++){
                    //cout << board1[i][j];
                    if(board2[userX-1][userY-1] == -1 && board2[i][j] == -1){ //GAME OVER
                        y = 0;
                        cout << "[***]"; //Prints out a bomb cell
                    }
                    else if(board2[i][j] == 1){
                        cout << "[ 1 ]";
                    }
                    else if(board2[i][j] == 2){
                        cout << "[ 2 ]";
                    }
                    else if(board2[i][j] == 3){
                        cout << "[ 3 ]";
                    }
                    else if(board2[i][j] == 4){
                        cout << "[ 4 ]";
                    }
                    else if(board2[i][j] == 5){
                        cout << "[ 5 ]";
                    }
                    else if(board2[i][j] == 6){
                        cout << "[ 6 ]";
                    }
                    else if(board2[i][j] == 7){
                        cout << "[ 7 ]";
                    }
                    else if(board2[i][j] == 8){
                        cout << "[ 8 ]";
                    }
                    else if(board2[i][j] == 0){
                        cout << "[   ]";
                    }
                    else {
                        cout << "[///]";
                    }

                }
                cout << endl;
            }
            break;
        case 3:
        for(int i = 0; i < Rows; i++){
            for(int j = 0; j < Cols; j++){
                //cout << board3[i][j];
                if(board3[userX-1][userY-1] == -1 && board3[i][j] == -1){ //GAME OVER
                    y = 0;
                    cout << "[***]"; //Prints out a bomb cell
                }
                else if(board3[i][j] == 1){
                    cout << "[ 1 ]";
                }
                else if(board3[i][j] == 2){
                    cout << "[ 2 ]";
                }
                else if(board3[i][j] == 3){
                    cout << "[ 3 ]";
                }
                else if(board3[i][j] == 4){
                    cout << "[ 4 ]";
                }
                else if(board3[i][j] == 5){
                    cout << "[ 5 ]";
                }
                else if(board3[i][j] == 6){
                    cout << "[ 6 ]";
                }
                else if(board3[i][j] == 7){
                    cout << "[ 7 ]";
                }
                else if(board3[i][j] == 8){
                    cout << "[ 8 ]";
                }
                else if(board3[i][j] == 0){
                    cout << "[   ]";
                }
                else {
                    cout << "[///]";
                }

            }
            cout << endl;
        }
        break;
    }
}

/* Function Name: InitializeBoard
 *
 * Function Description:
 * This function calls all necessary previous functions to set the board up before the player starts playing
 *
 * Parameters:
 * None
 *
 * return value:
 * None (void)
 *
 */
void InitializeBoard(){
    InputBoardSize();
    InitBombPosition(); //Give the bombs a random position on a given board
    PrintBoard();
}

int main(){
    srand(time(NULL));
    ResetBoard();
    InitializeBoard(); //Sets up board, ready for play
    while(y != 0){
        cout << "________________________________________________________" << endl;
        cout << "Enter row to select: "; cin >> userX;
        cout << "Enter column to select: "; cin >> userY;

        ShowSelectedSpace();
        PrintBoard();
    }
    CheckGameState();

    return 0;
}
