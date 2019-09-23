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


class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }

public:
    // Add your functions/methods here //
    Line(){}

    Line(double x1, double x2, double y1, double y2){
        P1.setX(x1);
        P1.setY(y1);
        P2.setX(x2);
        P2.setY(y2);
    }

    double getSlope(){
        return (P2.getY() - P1.getY()) / (P2.getX() - P1.getX());;
    }

    double getLength(){
        return sqrt(pow(P2.getX() - P1.getX(),2) + pow(P2.getY() - P1.getY(),2));
    }

    double getYIntercept(){
        return -(-P1.getY() + getSlope() * P1.getX());
    }

    string getVertical(){
        if(P1.getX() == P2.getX()){
            return "Yes";
        }
        else {
            return "No";
        }
    }

    string getHorizontal(){
        if(getSlope() == 0){
            return "Yes";
        }
        else {
            return "No";
        }
    }

    string getParallel(Line &L1, Line &L2){
        if(L1.getSlope() == L2.getSlope()){
            return "Yes";
        }
        else{
            return "No";
        }
    }


private:
    Point P1, P2;
};

int main(){
    Line L1;
    Line L2(5,6,7,8);

    cout << "L1: should have all zeros for values" << endl;
    cout << L1 << endl;

    cout << "Enter Two Points For Line: ";
    cin >> L1;
    cout << L1 << endl;

    cout << "Slope of L1" << endl;
    cout << L1.getSlope() << endl;

    cout << "Length of L1" << endl;
    cout << L1.getLength() << endl;

    cout << "Y-Intercept of L1" << endl;
    cout << L1.getYIntercept() << endl;

    cout << "Vertical?" << endl;
    cout << L1.getVertical() << endl;

    cout << "Horizontal?" << endl;
    cout << L1.getHorizontal() << endl;

    cout << "Parallel to another Line?" << endl;
    cout << L1.getParallel(L1, L2) << endl;


    return 0;
}

