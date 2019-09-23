// Add your information here
//Scott Hunt
//hunts5

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <math.h>
#define PI 3.141592653589793238463;


using namespace std;

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


class Circle {
    // implement cout for Circle classes objects
    friend ostream & operator<<( ostream &output, const Circle &C ){
        output << "Point 1: " << C.P1 << endl << "Point 2: " << C.P2;
        return output;
    }

    // implement cin for Cricle classes objects
    friend istream & operator>>( istream &input, Circle &C ){
        input >> C.P1 >> C.P2;
        return input;
    }



public:
    // Add your functions/methods here //
    Circle(){
        P1.setX(0);
        P1.setY(0);
        P2.setX(0);
        P2.setY(0);
    }

    Circle(double x1, double y1, double x2, double y2){
        P1.setX(x1);
        P1.setY(y1);
        P2.setX(x2);
        P2.setY(y2);
    }

    bool operator==(Circle &c1) {
        return (c1.getRadius() == getRadius() && P1 == c1.P1);
    }

    bool isCircle(){
        if(P1 == P2){
            return false;
        }
        return true;
    }


    double getRadius(){
        return sqrt(pow(P2.getX() - P1.getX(),2) + pow(P2.getY() - P1.getY(),2));
    }

    double getDiameter(){
        return getRadius() * 2;
    }

    double getArea(){
        return getRadius() * getRadius() * PI;
    }

    double getCircum(){
        return 2 * getRadius() * PI;
    }



private:
    Point P1, P2;
};

/*int main(){
    Circle C1;
    Circle C2;
    bool check;

    cout << "Values should be all 0" << endl;
    cout << C1;
    cout << endl;
    cout << endl;

    cout << "Enter points for a circle: "; cin >> C1;
    cout << endl;
    cout << "Points entered: \n" << C1 << endl;
    cout << "Valid Circle? ";
    if(C1.isCircle()){
        cout << "Yes \n";
    }
    else {
        cout << "No \n";
    }
    cout << endl;
    cout << "Radius: " << C1.getRadius() << endl;
    cout << "Diamter: " << C1.getDiameter() << endl;
    cout << "Circumference: " << C1.getCircum() << endl;
    cout << "Area: " << C1.getArea() << endl;

    cout << endl;
    cout << "Enter points for another circle: "; cin >> C2;
    check = C1 == C2;
    cout << "Are C1 and C2 the same circle? ";
    if(check){
        cout << "Yes \n";
    }
    else {
        cout << "No \n";
    }
    cout << endl;


    return 0;
}*/

