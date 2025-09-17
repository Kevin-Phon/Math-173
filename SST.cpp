#include <iostream>

int main() {
    double income;
    char self_employed;
    double tax = 0.0;

    std:: cout << "Enter your income: ";
    std:: cin >> income;

    std:: cout << "Are you self-employed? (y/n): ";
    std:: cin >> self_employed;

    // if(income <= 176100 and self_employed == 'n'){
    //     tax = income * 0.062;
    // }else if(income > 176100 and self_employed == 'n'){
    //     tax = 176100 * 0.062;
    // }else if(income <= 176100 and self_employed == 'y'){
    //     tax = income * 0.124;
    // }else if(income > 176100 and self_employed == 'y'){
    //     tax = 176100 * 0.124;
    // }else{
    //     std:: cout << "\n";
    //     std:: cout << "Enter a valid income and self_employed";
    // }

    if(self_employed == 'n'){
        if(income <= 176100){
            tax = income * 0.062;
        }else{
            tax = 176100 * 0.062;
        }
    }else if(self_employed == 'y'){
        if(income <= 176100){
            tax = income * 0.124;
        }else{
            tax = 176100 * 0.124;
        }
    }else{
        std:: cout << "\n";
        std:: cout << "Enter a valid income and self_employed";
    }

    std:: cout << "Your Social Security Tax is $" << tax << ".\n";
}