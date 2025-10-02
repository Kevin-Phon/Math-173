// A function BMI(double weight, int height) which returns the body mass index of a person given their weight in pounds and height in inches.

// A function woof(int n) which prints "Woof!" n times.

// A function greet(std::string name) which prints "Hello, <name>!" where name is the input string.

#include <iostream>
#include <string>

// Function to calculate BMI
double BMI(double weight, int height){
    return (703 * weight) / (height * height);
}

// Function to print "Woof!" n times
void woof(int n){
    for (int i = 0; i < n; i++){
        std:: cout << "Woof!\n";
    }
}

// Function to greet a person
void greet(std::string name){
    std:: cout << "Hello, " << name << "!\n";
}

int main(){

    // BMI
    double weight;
    int height;
    std:: cout << "Enter weight (in pounds): ";
    std:: cin >> weight;

    std:: cout << "Enter height (in inches): ";
    std:: cin >> height;

    std:: cout << "Your BMI is: " << BMI(weight, height) << ".\n";

    // woof
    woof(3);

    // greet
    std:: cout << "Enter your name: ";
    std:: string name;
    std:: cin >> name;
    greet(name);
}