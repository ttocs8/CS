#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>

using namespace std;

int room[15][15] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
int quit = 1;
char dir;
int numTurns = 0, numRoadsterFound = 0, numCaught = 0;
char playAgain = 'y';


int GenerateRandomNumber(){
    int num = rand() % 15; //random number from inputted numbers
    return num;
}

void ResetBoard(){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            room[i][j] = 0;
        }
    }
}

void InitElonPosition(){
    int posX = GenerateRandomNumber();
    int posY = GenerateRandomNumber();

    room[posX][posY] = 3; //Initial Alseep Elon position
}

void InitRoadsterPosition(){
    int posX = GenerateRandomNumber();
    int posY = GenerateRandomNumber();

    room[posX][posY] = 2; //Initial Roadster position
}

int InitUserPosition(){
    int posX = GenerateRandomNumber();
    int posY = GenerateRandomNumber();

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if(room[i][j] != 3 && room[i][j] != 2)
            room[posX][posY] = 1;
        }
    }
}


bool ElonProximity(){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if(room[i][j] == 3 && (room[i+1][j+1] == 1 || room[i-1][j-1] == 1 || room[i][j+1] == 1 || room[i][j-1] == 1 || room[i-1][j] == 1 || room[i+1][j] == 1)){
                room[i][j] = 4; //wake Him
                return true;
            }
        }
    }
    return false;
}


void Hints(){
    bool awake = ElonProximity();
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if(room[i][j] == 2 && ((room[i+2][j+2] == 1 || room[i-2][j-2] == 1 || room[i][j+2] == 1 || room[i][j-2] == 1 || room[i-2][j] == 1 || room[i+2][j] == 1) || (room[i+1][j+1] == 1 || room[i-1][j-1] == 1 || room[i][j+1] == 1 || room[i][j-1] == 1 || room[i-1][j] == 1 || room[i+1][j] == 1))){
                cout << "Hint: You are very close to roadster" << endl; //close to roadtser
            }
        }
     }
    if(awake == true){
        cout << "Hint: You have awoken Elon. Run." << endl;
    }
}

void MoveElon(){
    int posX = GenerateRandomNumber();
    int posY = GenerateRandomNumber();

        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 15; j++){
                if(room[i][j] != 2 && room[i][j] != 1 && room[i][j] == 4){
                    room[i][j] = 0;
                    room[posX][posY] = 4; //make random place Awake Elon
                }
            }
         }
}

int FoundRoadster(){
    int num;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if(room[i][j] == 1 && (room[i+1][j+1] == 2 || room[i-1][j-1] == 2 || room[i][j+1] == 2 || room[i][j-1] == 2 || room[i-1][j] == 2 || room[i+1][j] == 2)){
                cout << "You found the roadster!" << endl;
                numRoadsterFound++;
                return 0;
            }
        }
    }
    return 1;
}


int CaughtByElon(){
    int num;
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if(room[i][j] == 1 && (room[i+1][j+1] == 4 || room[i-1][j-1] == 4 || room[i][j+1] == 4 || room[i][j-1] == 4 || room[i-1][j] == 4 || room[i+1][j] == 4)){
                cout << "Elon caught you!" << endl;
                numCaught++;
                return 0;
            }
        }
    }
    return 1;
}

void printBoard(){
    bool found = FoundRoadster();
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if(room[i][j] == 4){
                cout << "[E]"; //Where AWAKE Elon Musk is
            }
           // else if(room[i][j] == 3){
            //    cout << "[e]"; //Where SLEEPING Elong Musk is
            //}
            else if(room[i][j] == 2 && found == false){
              cout << "[R]"; //Where the roadster is (((for testing purposes only)))
            }
            else if(room[i][j] == 1){
                cout << "[&]"; //Where the player is
            }
            else if(room[i][j] == 0){
                cout << "[ ]";
            }
            else {
                cout << "[ ]";
            }
        }
        cout << endl;
    }
}


void MovePlayer(char direction){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if(direction == 'w' && room[i][j] == 1){
                room[i][j] = 0;   //make previous cell empty
                room[i-1][j] = 1; //up 1 row
            }
            else if(direction == 's' && room[i][j] == 1){
                room[i][j] = 0;
                i+=1;
                room[i][j] = 1; //down 1 row
            }
            if(direction == 'a' && room[i][j] == 1){
                room[i][j] = 0;
                room[i][j-1] = 1; //left 1 column
            }
            if(direction == 'd' && room[i][j] == 1){
                room[i][j] = 0;
                j+=1;
                room[i][j] = 1; //right 1 column
            }
        }
     }
    numTurns++;
    ElonProximity();
    CaughtByElon();
    printBoard();
    Hints();
}


void InitilizeBoard(){
    ResetBoard();
    InitElonPosition();
    InitUserPosition();
    InitRoadsterPosition();
    printBoard();
}


void PrintStats(){
    cout << "Turns to find roadster: " << numTurns << endl;
    cout << "Times roadster was found:  " << numRoadsterFound << endl;
    cout << "Times caught by Elon: " << numCaught << endl;

}

int main(){
    srand(time(NULL));

    InitilizeBoard();
    while(playAgain != 'n'){
        while(quit != 0){
            cout << "_______________________________________________" << endl;
            cout << "& = player       E = Elon      R = Roadster" << endl;
            cout << "_______________________________________________" << endl;

            cout << "Enter a letter w(forward), a(left), s(backward), d(right): ";
            cin >> dir;

            MovePlayer(dir);
            MoveElon();

            quit = FoundRoadster();
        }
        cout << "Play again? y/n";
        cin >> playAgain;
        if(playAgain == 'y'){
            InitilizeBoard();
            quit = 1;
        }
    }

    PrintStats();




    return 0;
}
