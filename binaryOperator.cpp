// File: binaryOperator
// Created by Hugo Valle on 10/10/2017 for CS1410.
// Copyright (c) 2017 WSU
#include <iostream>

using namespace std;
// Constants, Structs, Classes
class Distance
{
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) // constructor no arguments
    {}
    Distance(int f, float i)           // constructor with two args.
    {
        feet = f;
        inches = i;
    }
    void getdist()      // get the length for user
    {
        cout<<"\nEnter feet: ";
        cin >> feet;
        cout<<"Enter inches: ";
        cin >> inches;
    }
    void showdist()     // display distance
    {
        cout<<feet << "\'-" << inches << "\"";
    }
    Distance operator + (Distance) const;   // add 2 distances
    //Distance operator += (Distance);   // add 1 distance to existing one.
};
// Return the sum
Distance Distance::operator+(Distance d2) const
{
    int f = feet + d2.feet;
    float i = inches + d2.inches;
    if(i >= 12.0)
    {
        i -= 12.0;
        f++;
    }
    return Distance(f, i);
}
// Prototypes
// Main Program Program
int main()
{
    Distance d1, d3;
    Distance d2(11, 6.25);
    d1.getdist();
    cout<<"Distance d1= "; d1.showdist(); cout<<endl;
    cout<<"Distance d2= "; d2.showdist(); cout<<endl;
    // Add binary operator support
    d3 = d1 + d2;
    cout<<"Distance d3= "; d3.showdist(); cout<<endl;

    return 0;
}
// Function Definitions