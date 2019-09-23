#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.14;

using namespace std;


double calcFreq(double frequency){
    double val;
    val = frequency * 2 * PI;
    return val;
}

double calcPhaseAngle(double resistor, double freq, double capacity, double inductor){
    double val;
    double lineFreq = calcFreq(freq);
    val = atan(((inductor * lineFreq)/resistor) - (1/resistor * capacity * lineFreq));
    return val;
}

double calcCurrentAmp(double resistor, double freq, double capacitor, double inductor, double volts){
    double val;
    double lineFreq = calcFreq(freq);
    val = (lineFreq * volts) / sqrt(pow((inductor * pow(lineFreq,2) - (1/capacitor)),2) + pow(resistor,2) * pow(lineFreq,2));
    return val;
}

double calcTotalCurrent(double resistor, double freq, double capac, double induct, double time, double volts){
    double A = calcCurrentAmp(resistor, freq, capac, induct, volts);
    double lineFreq = calcFreq(freq);
    double phaseAngle = calcPhaseAngle(resistor, freq, capac, induct);
    double val;
    val = A * sin(lineFreq * time - phaseAngle);
    return val;
}

double ResistorDrop(double resistor, double freq, double capac, double induct, double time, double volts){
    double val;
    double A = calcCurrentAmp(resistor, freq, capac, induct, volts);
    double lineFreq = calcFreq(freq);
    double phaseAngle = calcPhaseAngle(resistor, freq, capac, induct);
    val = resistor * A * sin(lineFreq * time - phaseAngle);
    return val;
}

double InductorDrop(double resistor, double freq, double capac, double induct, double time, double volts){
    double val;
    double A = calcCurrentAmp(resistor, freq, capac, induct, volts);
    double lineFreq = calcFreq(freq);
    double phaseAngle = calcPhaseAngle(resistor, freq, capac, induct);
    val = induct * A * cos(lineFreq * time - phaseAngle);
    return val;
}

double CapacitorDrop(double resistor, double freq, double capac, double induct, double time, double volts){
    double val;
    double A = calcCurrentAmp(resistor, freq, capac, induct, volts);
    double lineFreq = calcFreq(freq);
    double phaseAngle = calcPhaseAngle(resistor, freq, capac, induct);
    val = (-A/(capac*lineFreq)) * cos(lineFreq * time - phaseAngle);
    return val;
}


double VofT(double resistor, double freq, double capac, double induct, double time, double volts){
    double sum;
    sum = ResistorDrop(resistor, freq, capac, induct, time, volts) + InductorDrop(resistor, freq, capac, induct, time, volts) + CapacitorDrop(resistor, freq, capac, induct, time, volts);
    return sum;
}

double VDiff(double resistor, double freq, double capac, double induct, double time, double volts){
    double val;
    val = VofT(resistor, freq, capac, induct, time, volts) - (ResistorDrop(resistor, freq, capac, induct, time, volts) + InductorDrop(resistor, freq, capac, induct, time, volts) + CapacitorDrop(resistor, freq, capac, induct, time, volts));
    return val;
}




int main() {
    double R = 0, L = 0, C = 0, A = 0, E0 = 0, F = 0, T = 0, dT = 0, phaseAngle = 0;
    double nstep = 0;
    double I = 0;
    cout << "Applied voltage amplitude: ";
    cin >> E0; //voltage
    cout << "Line frequency: ";
    cin >> F; //line frequency
    cout << "Resistor value: ";
    cin >> R; //Resistor Value
    cout << "Inductor value: ";
    cin >> L; //Inductor Value
    cout << "Capacitor value: ";
    cin >> C; //Capacitor Value
    cout << "delta T: ";
    cin >> dT; //count up to
    cout << endl;

   /* cout << "Applied voltage amplitude: ";
    cin >> E0; //Applied voltage amplitude
    cout << "Delta T: ";
    cin >> dT; // # timesteps / cycle
    */
    C = C * pow(10,-6); //get C in scientific notation

    cout << endl;
    cout << "RLC Circuit Summary:" << endl;

    cout << endl;
    cout << "Voltage: " << E0 << " @ 50-Hz" << endl;
    cout << "Resistor Value: " << R << "-ohms" << endl;
    cout << "Inductor Value: " << L << "-H" << endl;
    cout << "Capacitor Value: " << C << "-F" << endl;

    A = calcCurrentAmp(R, F, L, C, E0);
    phaseAngle = calcPhaseAngle(R, F, C, L);
    cout << endl;
    cout << "Calculated Paramters:" << endl;
    cout << "Current Amplitude: \t" << A << "-amps" << endl;
    cout << "Phase Angle: \t" << phaseAngle << "-degrees" << endl;

    cout << "Iter. \t" << "Time \t" << "AV \t" << "I \t" << "VR \t" << "VL \t" << "VC \t" << "VT \t" << "Vdiff" << endl;
    for(int i = 0; i < dT; i++){
        T = nstep/1000;
        A = calcCurrentAmp(R, F, L, C, E0);
        phaseAngle = calcPhaseAngle(R, F, C, L);
        I = calcTotalCurrent(R, F, C, L, T, E0);
        double vR = ResistorDrop(R, F, C, L, T, E0);
        double vL = InductorDrop(R, F, C, L, T, E0);
        double vC = CapacitorDrop(R, F, C, L, T, E0);
        double vT = VofT(R, F, C, L, T, E0);
        double Vdif = VDiff(R, F, C, L, T, E0);

        nstep++;
        cout << setprecision(0) << (nstep-1) << "\t" << setprecision(3) << fixed << T << "\t" << A <<"\t" << fabs(I) << "\t" << vR << "\t" << vL << "\t"  << vC << "\t" << vT << "\t" << Vdif <<endl;

    }
    return 0;
}

