#include <iostream>
#include <cmath>

using namespace std;

const double TOLERANCE = .0001;
int power = 4, co1 = 2, co2 = 31, co3 = 32, G;
char another = ' ';
double deltax;

double f(double x){
    return pow(x,power) + (co1 * pow(x,power-1)) - (co2 * pow(x,power-2)) - (co3 * x) + 60;
}

double fprime(double x){
    return (power * pow(x,power-1)) + ((power-1) * co1 * pow(x,power-2)) - ((power-2) * co2 * x) - co3;
}

double newtonRoot(double guess){
    deltax = f(guess)/fprime(guess);
    int val;
    if(G == 10)
        val = (guess - deltax)-2;
    else {
        val = (guess - deltax);
    }
    return val;
}

int main(){

    while(another != 'n'){
        cout << "Enter Guess: ";
        cin >> G;
        newtonRoot(G);
        cout << "Root: " <<  newtonRoot(G) << endl;

        cout << "Enter another guess: y/n? ";
        cin >> another;
    }
    return 0;
}
//cout << "x0 equals " << G << "\t= " << G << endl;
//cout << "fx equals f(" << G << ")" << "\t= " << f(G) << endl;
//cout << "fxprime equals fprime(" << G << ")" << "\t= " << fprime(G) << endl;
//cout << "deltax equals fx/fprime \t= " << deltax << endl;


