// Please place your information here
//
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

// This prototype is complete
class stringManip {
    public:
        stringManip();
        stringManip(string input);
        string retrieve();
        void setString(string input);
        void chop();
        void padString(int n);
        void center(int length);
        void truncate(int n);
        void removeNonAlpha();
        void convertToUpperCase();
        void convertToLowerCase();
    private:
        string tobeEdited;
};

// Not all functions are defined here
// Default Constructor
stringManip::stringManip(){
    // finish me
    tobeEdited = "";
}

// Overloaded Constructor
stringManip::stringManip(string in_string){
    // finish me
    tobeEdited = in_string;
}

// retrieve function
string stringManip::retrieve(){
    // finish me
    return tobeEdited;
}

void stringManip::setString(string input){
    tobeEdited = input;
}

//chop function
void stringManip::chop(){
    string tempString;
    vector<char> tempVect;
    tempVect.resize(tobeEdited.size());

    for (int i = 0; i < tobeEdited.size(); i++){
        tempVect.at(i) = tobeEdited[i];
        if(!isspace(tempVect.at(i))){
            tempVect.at(i) = tempVect.at(i);
            tempString.push_back(tempVect.at(i));
        }
    }
    tobeEdited = tempString;
}

// padString() function
void stringManip::padString(int length){
    // finish me
    while(tobeEdited.length() < length){
        tobeEdited.push_back(' ');
    }
}

// Add rest of functions here++
// center function
void stringManip::center(int length){
    stringManip temp(tobeEdited);
    temp.chop();
    string tempString = tobeEdited;
    int numSpaces = 0;

    if(length > tobeEdited.size()){
        numSpaces = length - temp.retrieve().size();
    }
    else {
        numSpaces = temp.retrieve().size() - length;
    }

    if(numSpaces/2 % 2 != 0){
        for (int i = 0; i < numSpaces/2; i++) {
             tempString.insert(tempString.begin(), ' ');
             tempString.push_back(' ');
        }
        temp.setString(tempString);
    }
    else if(numSpaces/2 % 2 == 0){
        for (int i = 0; i < numSpaces/2; i++) {
            tempString.insert(tempString.begin(), ' ');
             tempString.push_back(' ');
        }
         temp.setString(tempString);
    }

    tobeEdited = temp.retrieve();

}

//truncate function
void stringManip::truncate(int n){
    string tempString;
    vector<char> tempVect;
    tempVect.resize(tobeEdited.size());

    if(tobeEdited.size() >= n){
        for (int i = 0; i < n; i++){
            tempVect.at(i) = tobeEdited[i];
            tempString.push_back(tempVect.at(i));
        }
    }
    else {
        tempString = tobeEdited;
    }
    tobeEdited = tempString;
}

//removeNonAlpha() funciton
void stringManip::removeNonAlpha(){
    string tempString;
    vector<char> tempVect;
    tempVect.resize(tobeEdited.size());

    for (int i = 0; i < tobeEdited.size(); i++){
        tempVect.at(i) = tobeEdited[i];
        if(!isspace(tempVect.at(i)) && !isdigit(tempVect.at(i) && !ispunct(tempVect.at(i))) && isalpha(tempVect.at(i))){
            tempVect.at(i) = tempVect.at(i);
            tempString.push_back(tempVect.at(i));
        }
    }
    tobeEdited = tempString;
}

//convertToUpperCase() function
void stringManip::convertToUpperCase(){
    string tempString;
    vector<char> tempVect;
    tempVect.resize(tobeEdited.size());

    for (int i = 0; i < tobeEdited.size(); i++){
        tempVect.at(i) = tobeEdited[i];
        if(islower(tempVect.at(i))){
            tempVect.at(i) = toupper(tempVect.at(i));
            tempString.push_back(tempVect.at(i));
        }
        else {
            tempVect.at(i) = tempVect.at(i);
            tempString.push_back(tempVect.at(i));
        }

    }
    tobeEdited = tempString;
}

//convertToLowerCase() function
void stringManip::convertToLowerCase(){
    string tempString;
    vector<char> tempVect;
    tempVect.resize(tobeEdited.size());

    for (int i = 0; i < tobeEdited.size(); i++){
        tempVect.at(i) = tobeEdited[i];
        if(isalpha(tempVect.at(i)) && isupper(tempVect.at(i))){
            tempVect.at(i) = tolower(tempVect.at(i));
            tempString.push_back(tempVect.at(i));
        }
        else {
            tempVect.at(i) = tempVect.at(i);
            tempString.push_back(tempVect.at(i));
        }
    }
    tobeEdited = tempString;
}



// Add test cases to main()
int main(){
    stringManip S1;
    stringManip S2("testing 123!   "); //used for alpha converting
    stringManip S3("tes tin g 12   3   "); //used for chop
    stringManip S4("testing 123   "); //used for padding
    stringManip S5("testing 123!   "); //used for center

    S3.chop();
    cout << "Chop: " <<S3.retrieve() << endl;





    S2.convertToUpperCase();
    cout << "convertToUpperCase: " << S2.retrieve() << endl;

    S5.convertToLowerCase();
    cout << "convertToLowerCase: " << S5.retrieve() << endl;

    cout << "S5 before center(20): <" << S5.retrieve() << ">" << endl;
    S5.center(20);
    cout << "S5 after center(20):  <" << S5.retrieve() << ">" << endl;

    // Test case for padString() You should correct some of your own.
    cout << "S4 before padString(20): <" << S4.retrieve() << ">" << endl;
    S4.padString(20);
    cout << "S4 after padString(20):  <" << S4.retrieve() << ">" << endl;
    cout << "Should be:               <testing 123         >" << endl;


    //S2.padString(20);



    return 0;
}

