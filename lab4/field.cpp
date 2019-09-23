#include <iostream>
#include <cmath>

using namespace std;

const double Q = 0.000000001;
const double Ke = 9000000000;

double Efield(double r, double a = 1){
   double val;
    if(r < a){
       val = Ke*Q*(r/pow(a,3));
    }
    else if(r >= a){
       val = (Ke*Q)/pow(r,2);
    }
    return val;
}

int main(){
    double R, A;
    cout << "Enter r: ";
    cin >> R;
    cout << "Enter a: ";
    cin >> A;
    cout << "Efield: " << Efield(R,A) << endl;

}

