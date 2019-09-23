/*
 * Project Title:
 * - Project 2 -Conways Game of Life
 * Description:
 * This program sets up a world for cells to live in according to certain parameters
 *
 * Developers:
 * - Scott Hunt - hunts5@mail.uc.edu
 * - Joe Monahan - monahajc@mail.uc.edu
 *
 * Help Received:
 * - Madhav Lolla
 *
 *
 * Developer comments: // Not optional
 * Developer 1:
 * I coded the project and learned about how to minimize amount of clutter in main() and use multiple classes within each other to make a game
 * Developer 2:
 * I established the different classes and functions that would be added to the code and learned how to pass classes and variables by reference effectively
 */

#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

const string file = "initial_params.txt";

/* Function Name: delay
 *
 * Function Description:
 * This function adds delay to the screen updating
 *
 * Parameters:
 * The len paramter is the length of the delay
 *
 * return value:
 * N/A
 */
void delay(int len){ //sets screen delay while updating world
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){

        }
    }
}

class Cell{ //Each individual cell on the screen
    private:
        char Alive;
        char Dead;

    public:
        Cell(){
            Alive = 206;
            Dead = ' ';
        }

        /* Function Name: showAliveCell, showDeadCell
         *
         * Function Description:
         * These functions print the alive cell and dead cell characters respectively
         *
         * Parameters:
         * N/A
         *
         * return value:
         * N/A
         */
        void showAliveCell(){
            cout << Alive;
        }

        void showDeadCell(){
            cout << Dead;
        }

};



class World{ //The entire environment
    private:
        Cell inhabitant;
        int amtAliveCells;
        int minNeighCells;
        int maxNeighCells;
        int amtRevived;
        int cellX, cellY;
        const int ROWS = 50, COLS = 100;
        int array[50][100];
    public:
        World(){}

        /* Function Name: initWorld
         *
         * Function Description:
         * This function makes whole world 0 (dead) and sets random locations to 1 (alive)
         *
         * Parameters:
         * N/A
         *
         * return value:
         * N/A
         */
        void initWorld(){

            int count = 0;

            for(int i = 0; i < ROWS; i++){
                for(int j = 0; j< COLS; j++){
                    array[i][j] = 0;
                }
             }

            while(count< amtAliveCells){
                cellX = rand()% ROWS;
                cellY = rand()% COLS;
                array[cellX][cellY]= 1;
                count++;
            }

            for(int i = 0; i< ROWS; i++){
                for(int j = 0; j < COLS; j++){
                if(array[i][j] != 1)
                    array[i][j] = 0;
                }
            }
        }

        /* Function Name: CountNeighbors
         * Function Description:
         * This function counts every cell in the 8 spots around a given cell
         *
         * Parameters:
         * The i paramter is the row number of the world
         * The j paramter is the column number of the world
         *
         * return value:
         * Returns number of alive/dead cells around a given cell
         */
        int CountNeighbors(int i, int j) {
            int adjCellCount = 0;

            if(i == 0 && j == 0){ //TOP LEFT
                adjCellCount = array[i][j+1]+array[i+1][j]+array[i+1][j+1];
            }
            else if(i == 0 && j == COLS-1){//TOP RIGHT
                adjCellCount = array[i][j-1]+array[i+1][j]+array[i+1][j-1];
            }
            else if(i == ROWS-1 && j ==0){//BOTTOM LEFT
                adjCellCount = array[i][j+1]+array[i-1][j]+array[i-1][j+1];
            }
            else if(i == ROWS-1 && j == COLS-1){//BOTTOM RIGHT
                adjCellCount = array[i][j-1]+array[i-1][j]+array[i-1][j-1];
            }
            else if(i == 0){
                adjCellCount = array[i][j-1]+array[i][j+1]+array[i+1][j]+array[i+1][j-1]+array[i+1][j+1];
            }
            else if(j == 0){
                adjCellCount = array[i][j+1]+array[i+1][j]+array[i+1][j+1]+array[i-1][j]+array[i-1][j+1];
            }
            else if(j == COLS-1){
                adjCellCount = array[i][j-1]+array[i-1][j]+array[i-1][j-1]+array[i+1][j]+array[i+1][j-1];
            }
            else if(i == ROWS-1){
                adjCellCount = array[i][j+1]+array[i][j-1]+array[i-1][j+1]+array[i-1][j]+array[i-1][j-1];
            }
            else{
                adjCellCount = array[i][j+1]+array[i][j-1]+array[i-1][j+1]+array[i-1][j]+array[i-1][j-1]+array[i+1][j+1]+array[i+1][j]+array[i+1][j-1];
            }
            return adjCellCount;
        }

        /* Function Name: UpdateWorld
         *
         * Function Description:
         * This function displays the populated world in the terminal
         *
         * Parameters:
         * N/A
         *
         * return value:
         * N/A
        */
        void UpdateWorld(){ //Based off of the rules and parameters of the game, update as necessary
            for(int i = 0; i < ROWS; i++){
                for(int j = 0; j < COLS; j++){
                    if((array[i][j] == 1 && CountNeighbors(i,j) > maxNeighCells) || (array[i][j] == 1 && CountNeighbors(i,j) < minNeighCells)){
                        array[i][j] = 0;
                    }
                    else if((array[i][j] == 1 && CountNeighbors(i,j) <= maxNeighCells) && (array[i][j] == 1 && CountNeighbors(i,j) >= maxNeighCells)){
                        array[i][j] = 1;
                    }
                    else if(array[i][j] == 0 && CountNeighbors(i,j) == amtRevived){
                        array[i][j] = 1;
                    }
                }
            }
        }

        /* Function Name: drawWorld
         *
         * Function Description:
         * This function displays the populated world in the terminal
         *
         * Parameters:
         * N/A
         *
         * return value:
         * N/A
         */
        void drawWorld(){
            system("CLS");
            for(int i = 0; i < ROWS; i++){
                for(int j = 0; j < COLS; j++){
                    if(array[i][j] == 1){
                        inhabitant.showAliveCell();
                        //cout << array[i][j];
                    }else{
                        inhabitant.showDeadCell();
                        //cout << array[i][j];
                    }
                }
                cout << endl;
            }

        }

        /* Function Name: setAmountCells, setMinNCells, setMaxNCells, setRevivedCells
         *
         * Function Description:
         * These functions set the amount of alive cells, minimum neighbors cells, maximum neighbor cells and revived cells respectively
         *
         * Parameters:
         * The n paramters for each are the numbers to set the variables to
         *
         * return value:
         * N/A
         */
        void setAmountCells(int n){ //ALL 4 OF THE BELOW ARE SELF EXPLANATORY BY NAME
            amtAliveCells = n;
        }

        void setMinNCells(int n){
            minNeighCells = n;
        }

        void setMaxNCells(int n){
            maxNeighCells = n;
        }

        void setRevivedCells(int n){
            amtRevived = n;
        }

};

/* Function Name: getFromFile
 *
 * Function Description:
 * This function reads in the values for all the settings (paramters)
 *
 * Parameters:
 * The ifile paramter is the object that takes in the values
 * The file_name parameter is the name of the file containing the initial paramters
 * The amountAliveCells parameter is the number of cells the world is initialized with
 * The minNeighborCells parameter is the minimum amount of adjacent alive cells for a cell to keep living
 * The maxNeighborCells parameter is the number of cells that can surround a cell that will kill it
 * The revivedCells parameter is the number of cells that must surround a dead cell to make it alive
 * The numGens parameter is the amount of times to update the world
 *
 * return value:
 * N/A
 */
void getFromFile(ifstream &ifile, string file_name,int &amountAliveCells, int &minNeighborCells, int &maxNeighborCells, int &revivedCells,int &numGens){ //Read from paramter text file
    ifile.open(file_name);

    if(!ifile.fail()){

        while(!ifile.eof()){
            ifile >> amountAliveCells >> minNeighborCells >> maxNeighborCells >> revivedCells >> numGens;
            if(ifile.eof()){
                break;
            }
        }

        ifile.close();
        }
    else{
        cout << "file not found"<< endl;
    }
}

/* Function Name: ShowEditRules
 *
 * Function Description:
 * This function displays the initial rules and lets the user edit them as necessary
 *
 * Parameters:
 * The amountAliveCells parameter is the number of cells the world is initialized with
 * The minNeighborCells parameter is the minimum amount of adjacent alive cells for a cell to keep living
 * The maxNeighborCells parameter is the number of cells that can surround a cell that will kill it
 * The revivedCells parameter is the number of cells that must surround a dead cell to make it alive
 * The numGens parameter is the amount of times to update the world
 *
 * return value:
 * N/A
 */
void ShowEditRules(int &amountAliveCells, int &minNeighborCells, int &maxNeighborCells, int &revivedCells,int &numGens){ //displays initial parameters, allows user to edit if need be
    int txt = -1;

    while(txt != 0){

        cout << "* * * * * * Initial Parameters and RULES * * * * * *"<< endl;
        cout << "|   1. Amount of starting alive cells is "<< amountAliveCells<< setw(8) <<"|" << endl;
        cout << "|   2. Min amount of cell neighbors to live is " << minNeighborCells << setw(4) << "|" <<endl;
        cout << "|   3. Max amount of cell neighbors to live is "<< maxNeighborCells << setw(4) << "|" <<endl;
        cout << "|   4. Amount of cell neighbors to revive is "<< revivedCells << setw(6) <<  "|" <<endl;
        cout << "|   5. Amount of updates to go through is "<< numGens << setw(7) << "|" <<endl;
        cout << "*--------------------------------------------------*"<< endl;
        cout << "Which of the above would you like to change ? (Type 0 for none of them)";
        cin >> txt;

        switch(txt){
            case 1: cout << "How many alive cells would you like to start with? "; cin >> amountAliveCells;
            break;

            case 2: cout << "What is the minimum amount of neighors a given cell needs to live? "; cin >> minNeighborCells;
            break;

            case 3: cout << "What is the maximum amount of neighors a given cell could live by before dying? "; cin >> maxNeighborCells;
            break;

            case 4: cout << "How many alive cells around a dead cell does it take to revive that dead cell? "; cin >> revivedCells;
            break;

            case 5: cout << "# of total updates? "; cin >> numGens;
            break;

            default:
                break;
        }
        system("CLS");

    }

}

/* Function Name: INITIALIZE
 *
 * Function Description:
 * This function takes the initial parameters and passes them into the World class, then initializes the world
 *
 * Parameters:
 * The E parameter is the world, passed by reference
 * The amountAliveCells parameter is the number of cells the world is initialized with
 * The minNeighborCells parameter is the minimum amount of adjacent alive cells for a cell to keep living
 * The maxNeighborCells parameter is the number of cells that can surround a cell that will kill it
 * The revivedCells parameter is the number of cells that must surround a dead cell to make it alive
 * The numGens parameter is the amount of times to update the world
 *
 * return value:
 * N/A
 */

void INITIALIZE(World &E, int &amountAliveCells, int &minNeighborCells, int &maxNeighborCells, int &revivedCells){ //Initialize settings
    E.setAmountCells(amountAliveCells);
    E.setMinNCells(minNeighborCells);
    E.setMaxNCells(maxNeighborCells);
    E.setRevivedCells(revivedCells);
    E.initWorld();
}

/* Function Name: PLAYGAME
 *
 * Function Description:
 * This function displays the world in the terminal and updates for however many generations specified, with a delay of 200
 *
 * Parameters:
 * The E parameter is the world, passed by reference
 * The numGens parameter is the amount of times to update the world
 *
 * return value:
 * N/A
*/
void PLAYGAME(World &E, int &numGens){ //Show and replace each generation in terminal
    for (int i = 0; i < numGens; i++){
        E.drawWorld();
        E.UpdateWorld();
        delay(200);
    }
}

int main(){
    srand(time(NULL));
    int amountAliveCells = 0, minNeighborCells = 0, maxNeighborCells = 0, revivedCells = 0, numGens = 0;

    World Earth;
    ifstream inpFile;

    getFromFile(inpFile, file, amountAliveCells, minNeighborCells, maxNeighborCells, revivedCells, numGens);
    ShowEditRules(amountAliveCells, minNeighborCells, maxNeighborCells, revivedCells, numGens);

    INITIALIZE(Earth, amountAliveCells, minNeighborCells, maxNeighborCells, revivedCells); //Initialize all settings
    PLAYGAME(Earth, numGens); //Play the game


return 0;

}
