/*#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;


class Sphere {
public:
    Sphere(){
        setRadius(0);
    }

    Sphere(double radius){
        setRadius(radius);
    }

    double getRadius(){
        return r;
    }

    void setRadius(double radius){
        r = radius;
    }

    void display(){
        cout << "Sphere Parameters: " << endl;
        cout << "Radius: " << getRadius() << endl;
        cout << "Surface Area: " << getSurfaceArea() << endl;
        cout << "Volume: " << getVolume() << endl << endl;
    }

private:
    double getSurfaceArea(){
        return 4 * M_PI * (r*r);
    }

    double getVolume(){
        return ((4 * M_PI * (r*r*r))/3);
    }

    double r;

};

int main(){

    Sphere sphere1;
    sphere1.display();

    Sphere sphere2(2);
    sphere2.display();

    sphere2.setRadius(4);
    sphere2.display();

    return 0;
}
*/
