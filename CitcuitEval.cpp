// CircuitEval.cpp : Defines the entry point for the console application.
// Circuit evaluation 2019
// Aniekan Umanah 11/04/19.
// copywright  2019 Aniekan Umanah. All rights reserved.

// model circuit with two voltage sources.


#include <iostream>   // header file for input/output stream

using namespace std;

// function prototypes
float currentIx(float,float,float,float,float); // retruns the current flowing in Ix
float currentIy(float,float,float,float,float); // retruns the current flowing in Iy

int main(void)
{
    // declare variable to hold resistor, current, voltage values
    float R1, R2, R3, Ry, Rz, V1, V2;
    float Rx, D, Ix, Iy, Iz, Vz;
    
    cout << "Enter Resistor values in ohms";
    // prompt user to enter values
    cout << "\nR1: ";
    cin >> R1;
    cout << "\nR2: ";
    cin >> R2;
    cout << "\nR3: ";
    cin >> R3;
    cout << "\nRy: ";
    cin >> Ry;
    cout << "\nRz: ";
    cin >> Rz;
    cout << "\nEnter voltage values in volts";
    cout << "\nV1: ";
    cin >> V1;
    cout << "\nV2: ";
    cin >> V2;
    
    Rx = R1 + ((R2 * R3) / (R2 + R3)); // resultant resitance of combination
    cout << "Load Rx is " << Rx << " ohms\n" <<endl; // display resistance
    D = ((Rx + Rz)*(Ry + Rz)) - (Rz*Rz); // calculate the determinant of the matrices
    
    // call currentIx function passing 5 values and returning the Ix variable
    Ix = currentIx(Rz, Ry, V1, V2, D);
    // call currentIy function passing 5 values and returning the Iy variable
    Iy = currentIy(Rx, Rz, V1, V2, D);
    Iz = Ix + Iy; // calculate output current
    Vz = Rz * Iz; // calculate output voltage
    
    // display results
    cout << "Current Ix = " << Ix << "A"<<endl;
    cout << "Current Iy = " << Iy << "A"<<endl;
    cout << "Output voltage Vz = " << Vz << "V"<<endl;
    
    return 0;
}
// function to calculate current in Ix
float currentIx(float a,float b,float c,float d,float e)
{
    float Dx; // varaible to hold current
    Dx = ((c *(a + b)) - (d * a)) / e; // calculate Ix
    return Dx; // return value to calling function
}
// function to calculate current in Iy
float currentIy(float a,float b,float c,float d,float e)
{
    float Dy; // variable to hold current
    Dy = (((a + b) * d) - (c * b)) / e; // calculate Iy
    return Dy; // return value to calling function
}
