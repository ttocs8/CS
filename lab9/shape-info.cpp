#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <cmath>
#include <math.h>
#include<iomanip>
#include <fstream>
#include <sstream>
#include <cstring>


using namespace std;

const double PI =  3.141592653589793238463;
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


class Triangle {
    // implement cout for Triangle classes objects
    friend ostream & operator<<( ostream &output, const Triangle &C ){
        output << "Point 1: " << C.P1 << endl << "Point 2: " << C.P2 << endl << "Point 3: " << C.P3;
        return output;
    }

    // implement cin for Triangle classes objects
    friend istream & operator>>( istream &input, Triangle &C ){
        input >> C.P1 >> C.P2 >> C.P3;
        return input;
    }


public:
    // Add your functions/methods here //
    Triangle(){
        P1.setX(0);
        P1.setY(0);
        P2.setX(0);
        P2.setY(0);
        P3.setX(0);
        P3.setY(0);
    }

    Triangle(double x1, double y1, double x2, double y2, double x3, double y3){
        P1.setX(x1);
        P1.setY(y1);
        P2.setX(x2);
        P2.setY(y2);
        P3.setX(x3);
        P3.setY(y3);
    }

    bool operator==(Triangle &t1) {
        if(t1.isTriangle()){
            if(t1.P1 == P1 || t1.P2 == P1 || t1.P3 == P1){
                if(t1.P1 == P2 || t1.P2 == P2 || t1.P3 == P2){
                    if(t1.P1 == P3 || t1.P2 == P3 || t1.P3 == P3){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isTriangle(){
        if((P2.getY() - P1.getY()) / ((P2.getX() - P1.getX())) == (P3.getY() - P2.getY()) / (P3.getX()-P2.getX())){
            return false;
        }
        return true;
    }


    double getSideOne(){
        return sqrt(pow(P1.getX() - P3.getX(),2) + pow(P1.getY() - P3.getY(),2));
    }

    double getSideTwo(){
        return sqrt(pow(P2.getX() - P3.getX(),2) + pow(P2.getY() - P3.getY(),2));
    }


    double getBase(){
        return sqrt(pow(P1.getX() - P2.getX(),2) + pow(P1.getY() - P2.getY(),2));
    }


     //double getHeight(){
     //   return getSideOne() * cos( (PI/180) * (90 - acos((pow(getSideOne(),2) + pow(getBase(),2) - pow(getSideTwo(),2))/ (2 * getBase() * getSideOne()))));
     //}

    bool isEqualateral(){
        if(getSideOne() == getSideTwo() && getSideOne() == getBase()){
            return true;
        }
        return false;
    }

    double getArea(){

        double p = getPerimeter()/2;

        return sqrt(p*(p-getSideOne()) * (p-getSideTwo()) * (p-getBase()) );
    }

    double getPerimeter(){
        return getSideOne() + getSideTwo() + getBase();
    }

private:
    Point P1, P2, P3;
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

vector<char> breakupString(string str){
    vector<char> data;
    stringstream ss;
    ss << str;

    while(!ss.eof()){
        char temp;
        ss >> temp;
        data.push_back(temp);
    }

    return data;
}

vector<double> breakupstring(string str){
    vector<double> numdata;
    stringstream ss;     //requires sstream library included
    ss << str;

    while(!ss.eof()){
        double temp;
        ss >> temp;
        numdata.push_back(temp);
    }

    return numdata;
}

int main(){
    Circle C1;
    Triangle T1;
    Quad Q1;
    ifstream inpFile;
    ofstream outpFile;
    vector <double> points;

    inpFile.open("shapes.txt");

    //if(!inpFile.fail()){

        outpFile.open("shapes-info.txt");

        while(!inpFile.eof()){
            string line;
            inpFile >> line;           //read from inputfile - copy to a temporary num
            getline(inpFile, line,'\n');
            if(inpFile.eof()){        //check for eof after stream >> operation
                break;
            }

            points = breakupstring(line);

            outpFile << line << endl;
        }

        inpFile.close();
        outpFile.close();
    //}

    cin >> C1;
    cin >> T1;
    cin >> Q1;

}
