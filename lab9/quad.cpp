// Add your information here
//Scott Hunt
//hunts5

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <math.h>



using namespace std;

//const double PI =  3.141592653589793238463;
// Please replace this Point class with your version from Part B
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

    bool operator==(Point &rhs) {
        return (rhs.x == x && rhs.y == y);
    }

    double getX(){
        return x;
    }

    double getY(){
        return y;
    }

    void setX(double val){
        x = val;
    }

    void setY(double val){
        y = val;
    }

private:
    double x,y;
};


class Quad {
    // implement cout for Quad classes objects
    friend ostream & operator<<( ostream &output, const Quad &C ){
        output << "Point 1: " << C.P1 << endl << "Point 2: " << C.P2 << endl << "Point 3: " << C.P3 << endl << "Point 4: " << C.P4 << endl;
        return output;
    }

    // implement cin for Quad classes objects
    friend istream & operator>>( istream &input, Quad &C ){
        input >> C.P1 >> C.P2 >> C.P3 >> C.P4;
        return input;
    }


public:
    // Add your functions/methods here //
    Quad(){
        P1.setX(0);
        P1.setY(0);
        P2.setX(0);
        P2.setY(0);
        P3.setX(0);
        P3.setY(0);
        P4.setX(0);
        P4.setY(0);
    }

    Quad(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
        P1.setX(x1);
        P1.setY(y1);
        P2.setX(x2);
        P2.setY(y2);
        P3.setX(x3);
        P3.setY(y3);
        P4.setX(x4);
        P4.setY(y4);
    }

    double getArea(){
        return  (abs((P1.getX() * P2.getY()) + (P2.getX() * P3.getY()) + (P3.getX() * P4.getY()) + (P4.getX() * P1.getY()) - (P2.getX() * P1.getY()) - (P3.getX() * P2.getY()) - (P4.getX() * P3.getY()) - ((P1.getX() * P4.getY()))))/2;
    }

    bool isQuad(){
        if((P1.getX() * (P2.getY() - P3.getY())) + (P2.getX() * (P3.getY() - P1.getY())) + (P3.getX() * (P1.getY() - P2.getY()))){
            return true;
        }

        return false;
    }


private:
    Point P1, P2, P3, P4;
};

/*int main(){
    Quad C1;
    Quad C2;
    bool check;

    cout << "Values should be all 0" << endl;
    cout << C1;
    cout << endl;
    cout << endl;

    cout << "Enter points for a Quad: "; cin >> C1;
    cout << endl;
    cout << "Points entered: \n" << C1 << endl;
    cout << "Area: " << C1.getArea() << endl;
    cout << "Valid Quad? ";
    if(C1.isQuad()){
        cout << "Yes \n";
    }
    else {
        cout << "No \n";
    }


    return 0;
}*/

