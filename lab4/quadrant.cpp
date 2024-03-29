#include <iostream>

using namespace std;

// Please place your "determine quadrant" function and body
// See google docs for details
int whichQuadrant(float x, float y){

        if(x > 0.0 && y > 0.0)
            return 1;
        else if(x == 0.0 && y != 0)
            return 'X';
        else if(x != 0.0 && y == 0)
            return 'Y';
        else if(x < 0.0 && y < 0.0)
            return 3;
        else if(x == 0.0 && y == 0.0)
            return 'C';
        else if(x < 0.0 && y > 0.0)
            return 2;
        else if(x > 0.0 && y < 0.0)
            return 4;

        return 0;
}

string message(int q) {
    string msg;
    if(q == 'C') msg = "On Center";
    if(q == 'X') msg = "On XAxis";
    if(q == 'Y') msg = "On YAxis";
    if(q ==  1)  msg = "Q1";
    if(q ==  2)  msg = "Q2";
    if(q ==  3)  msg = "Q3";
    if(q ==  4)  msg = "Q4";
    return msg;
}

int main() {
    double  x = 0;
    double y = 0;

    cout << "For XY Pair: " << x << "," << y << " function returns: "
         <<  message(whichQuadrant(x,y))
         << " should be On Center" << endl;

    x = 4.8;
    y = 4.8;
    cout << "For XY Pair: " << x << "," << y << " function returns: "
         <<  message(whichQuadrant(x,y))
         << " should be On Q1" << endl;

    x = -7;
    y = -4.8;
    cout << "For XY Pair: " << x << "," << y << " function returns: "
         <<  message(whichQuadrant(x,y))
         << " should be On Q3" << endl;

    x = 7;
    y = -3;
    cout << "For XY Pair: " << x << "," << y << " function returns: "
         <<  message(whichQuadrant(x,y))
         << " should be On Q4" << endl;

    x = -9;
    y = 8;
    cout << "For XY Pair: " << x << "," << y << " function returns: "
         <<  message(whichQuadrant(x,y))
         << " should be On Q2" << endl;

    return 0;
}


