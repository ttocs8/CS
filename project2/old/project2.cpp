#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

/*

*

* OBJECT Oriented Programming will be implemented for the Board

* and each cell that will be alive

*

* initial paramters will be in a file called "initial_params.txt"

*

* There will be FOUR/FIVE rules

* and the user will be asked if they want to manipulate any (through cin)

* If YES, ask which one (cin), display everything that can be changed,

* get user input and then update the rules

*

* The grid will be displayed user ASCII character 219 in the terminal for

* an alive cell, and ASCII 178 for blank/dead cells

*

*

*

* TEST CODE FOR DISPLAYING BOARD BELOW

*/



class Cell{
    private:
        char Alive;
        char Dead;

    public:
        Cell(){
            Alive = 'A';
            Dead ='_';
        }

        void showAliveCell(){
            cout << Alive;
        }

        void showDeadCell(){
            cout << Dead;
        }

};



class World{
    private:
        Cell inhabitant;
        int array[25][50];
        int amtAliveCells;
        int minNeighCells;
        int maxNeighCells;
        int amtRevived;
        int cellX, cellY;
    public:
        World(){}

        void initWorld(){
            int count = 0;

            for(int i = 0; i < 25; i++){
                for(int j = 0; j< 50; j++){
                    array[i][j] = 0;
                }
             }

            while(count< amtAliveCells){
                cellX = rand()% 25;
                cellY = rand()% 50;
                array[cellX][cellY]= 1;
                count++;
            }

            for(int i = 0; i< 25; i++){
                for(int j = 0; j < 50; j++){
                if(array[i][j] != 1)
                    array[i][j] = 0;
                }
            }
        }

        void drawWorld(){

            for(int i = 0; i < 25; i++){
                for(int j = 0; j < 50; j++){
                    if(array[i][j]== 1){
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

        void setAmountCells(int n){
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





int main()

{

    srand(time(NULL));
    char al ='A';
    char de ='_';
    int amountAliveCells;
    int minNeighborCells;
    int maxNeighborCells;
    int revivedCells;

    ifstream inpFile;
    ofstream outFile;

    inpFile.open("initial_params.txt");


    if(!inpFile.fail()){

        while(!inpFile.eof()){
            inpFile >> amountAliveCells >> minNeighborCells >> maxNeighborCells >> revivedCells;
            if(inpFile.eof()){
                break;
            }
        }

        inpFile.close();

        }
    else{
        cout << "file not found"<< endl;
    }



    int txt = -1;

    while(txt != 0){

        cout << "* * * Initial Parameters and RULES********"<< endl;
        cout << "* 1. Amount of starting alive cells is "<< amountAliveCells<< " *" << endl;//0 - area of board
        cout << "* 2. Min amount of cell neighbors to live is " << minNeighborCells << " *" <<endl;
        cout << "* 3. Max amount of cell neighbors to live is "<< maxNeighborCells    << " *" <<endl;
        cout << "* 4. Amount of cell neighbors to revive is "<< revivedCells << " *" <<endl;
        cout << " Which of the above would you like to change (Type 0 for none of them)?";
        cin >> txt;

        switch(txt){
            case 1: cout << "How many alive cells "; cin >> amountAliveCells;
            break;

            case 2: cout << "Min neighors "; cin >> minNeighborCells;
            break;

            case 3: cout << "Max neighors "; cin >> maxNeighborCells;
            break;

            case 4: cout << "Revive "; cin>> revivedCells;
            break;

            default:
                break;
        }
        system("CLS");

    }

    World Earth;

    Earth.setAmountCells(amountAliveCells);
    Earth.setMinNCells(minNeighborCells);
    Earth.setMaxNCells(maxNeighborCells);
    Earth.setRevivedCells(revivedCells);

    Earth.initWorld();
    Earth.drawWorld();

    cout << "\n"<< al << " = Alive" << endl;
    cout << de << " = Dead" << endl;

return 0;

}


