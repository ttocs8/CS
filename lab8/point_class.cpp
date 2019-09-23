// Add your information here
//Scott Hunt
//hunts5

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Please complete this Point class.
// The cin/cout operators have been overloaded for you
class Point {

    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }

    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }

public:
    Point(){
        x = 0;
        y = 0;
    }

    Point(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }

    // Add your functions here
    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    void setX(int val){
        x = val;
    }

    void setY(int val){
        y = val;
    }

private:
    int x,y;
};

int main(){
    Point P1;
    //Point P2(7,6);
    //cout << "Point P1 should have 0,0 as values" << endl;
    //cout << P1 << endl;
    //cout << "Point P2 should have 7,6 as values" << endl;
    //cout << P2 << endl;

    //cout << "Enter x and y points: ie 3 4 ";
    //cin >> P1;
    //cout << P1 << endl;
    P1.setX(5);
    P1.setY(6);
    cout <<  "x: " << P1.getX() << ", y: " << P1.getY() << endl;


    return 0;
}

