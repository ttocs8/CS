/*#include <iostream>

using namespace std;

class Cuboid {
public:
    Cuboid(){
        setWidth(0);
        setLength(0);
        setHeight(0);
    }

    Cuboid(double len, double width, double height){
        setWidth(width);
        setLength(len);
        setHeight(height);
    }

    double getWidth(){
        return W;
    }

    double getLength(){
        return L;
    }
    double getHeight(){
        return H;
    }

    void setWidth(double wid){
        L = wid;
    }

    void setLength(double len){
        W = len;
    }

    void setHeight(double height){
        H = height;
    }

    void display(){
        cout << "Cuboid Parameters: " << endl;
        cout << "Width: " << getWidth() << endl;
        cout << "Length: " << getLength() << endl;
        cout << "Surface Area: " << getSurfaceArea() << endl;
        cout << "Volume: " << getVolume() << endl << endl;
    }

private:
    double getSurfaceArea(){
        return 2 *((W * L) + (H * L) + (H * W));
    }

    double getVolume(){
        return L * W * H;
    }

    double W;
    double L;
    double H;

};

/*int main(){

    Cuboid rect1;
    rect1.display();

    Cuboid rect2(2,4,2);
    rect2.display();

    rect2.setWidth(3);
    rect2.display();

    return 0;
}*/

