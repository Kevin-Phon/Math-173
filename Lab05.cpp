#include <iostream>

const double PI = 3.14151265;

// Function to calculate the area of a circle (PI r_square)
double area(double radius){
    return PI * radius * radius;
}

// Function to calculate the circumference of a circle (2 PI r)
double circumference(double radius){
    return 2 * PI * radius;
}

int main(){
    std:: cout << "Enter radius: ";
    double radius;
    std:: cin >> radius;

    std:: cout << "The area and curcumference of a circle are " << area(radius) << " and " << circumference(radius) << ", respectively. \n";
}