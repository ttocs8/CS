#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int upper = 0;
int numSamples = 0;
int minimum;
int maximum;
int sum = 0;
double mean = 0.0;
int randomInt = 0;
int barSize;
vector<int> v;
vector<int> fre(upper);
int freq = 0;

int RandNumber(){
    int num = rand() % upper; //random number from 0 - 100
    return num;
}

void GetInput(){ //get user input
    cout << "Enter end range: " << endl;
    cin >> upper;
    cout << "Enter number of samples" << endl;
    cin >> numSamples;
    cout << endl;
}

void PopulateVector(){
     //fill the vector with random integers
        randomInt = RandNumber();
        v.push_back(randomInt);
}

void maxValue(){ //get max value
    for(int i = 0; i < upper; i++){
        if(fre.at(i) > maximum){
            maximum = fre.at(i);
        }
    }
}

void minValue(){ // get min value
    for(int i = 0; i < upper; i++){
        if(fre.at(i) < minimum){
            minimum = fre.at(i);
        }
    }
}

void sumValue(){ //get the sum of values
    for(int i = 0; i < upper; i++){
        sum += fre.at(i);
    }
}

void meanValue(){ // get the mean of the values
    for(int i = 0; i < upper; i++){
        mean = static_cast<double>(numSamples)/(upper);
    }
}

void bar(int num){
    barSize = num / 16;
    for(int i = 0; i < barSize; i++){
        cout << "*";
    }
}

void printStats(){ //print out stats
    cout << "Index \t Value Bar" << endl;
    for(int i = 0; i < upper; i++){ //set index values
        cout << setw(5) << i << "\t";
        cout << setw(5) << fre.at(i) << "\t";
        bar(fre.at(i));

        cout << endl;
    }

    cout << "Scale: " << 16 << " per *\n";
    cout << endl;
    cout << "Range: 0 to " << (upper-1) << endl;
    cout << "Sample Count: " << numSamples << endl;
    cout << "Min Value: " << minimum << endl;
    cout << "Max Value: " << maximum << endl;
    cout << "Sum Value: " << sum << endl;
    cout << "Mean Value: " << mean << endl;
    cout << endl;
}




int main(){
    srand(time(NULL));

    GetInput();

    while(!(upper <= 100 && upper >= 0)){ //check if end range is between 0 - 100
      cout << "Error: Please enter a range from 0-100" << endl;
      GetInput();
    }

    minimum = numSamples;
    upper++; //incrememnt upper so the frequency matrix is properly sized
    fre.resize(upper);

    for(int i = 0; i < numSamples; i++){ //populate vector and count
        PopulateVector();
        fre.at(randomInt) += 1;
    }

    minValue(); //call all functions
    maxValue();
    sumValue();
    meanValue();
    printStats();
    return 0;
}

