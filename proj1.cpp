#include<iostream>
#include<iomanip>

int main() {
    
    std::cout << "Enter your filing status (single (1), jointly (2), separately (3), household (4)): ";
    int filing_status;
    std::cin >> filing_status;

    std::cout << "Enter your taxable income: ";
    double income;
    std::cin >> income;

    double tax = 0;

    // round up value to nearest cent
    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    // single status
    if(filing_status == 1){   // 10% rate
        if(income >= 0 && income <= 11600){
            tax = income * 0.10;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 11601 && income <= 47150){    // 12% rate
            tax = 0.10 * 11600 + (income - 11600) * 0.12;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 47151 && income <= 100525){   // 22% rate
            tax = 0.10 * 11600 + 0.12 * (47150 - 11600) + (income - 47150) * 0.22;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 100526 && income <= 191950){  // 24% rate
            tax = 0.10 * 11600 + 0.12 * (47150 - 11600) + 0.22 * (100525 - 47150) + (income - 100525) * 0.24;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 191951 && income <= 243725){  // 32% rate
            tax = 0.10 * 11600 + 0.12 * (47150 - 11600) + 0.22 * (100525 - 47150) + 0.24 * (191950 - 100525) + (income - 191950) * 0.32;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 243726 && income <= 609350){  // 35% rate
            tax = 0.10 * 11600 + 0.12 * (47150 - 11600) + 0.22 * (100525 - 47150) + 0.24 * (191950 - 100525) + 0.32 * (243725 - 191950) + (income - 243725) * 0.35;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 609351){   // 37% rate
            tax = 0.10 * 11600 + 0.12 * (47150 - 11600) + 0.22 * (100525 - 47150) + 0.24 * (191950 - 100525) + 0.32 * (243725 - 191950) + 0.35 * (609350 - 243725) + (income - 609350) * 0.37;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else{
            std:: cout << "Invalid input\n";
        }
    }

    // married jointly filing status
    else if(filing_status == 2){
        if(income >= 0 && income <= 23200){     // 10%
            tax = income * 0.10;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 23201 && income <= 94300){    // 12%
            tax = 0.10 * 23200 + (income - 23200) * 0.12;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 94301 && income <= 201050){   // 22%
            tax = 0.10 * 23200 + 0.12 * (94300 - 23200) + (income - 94300) * 0.22;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 201051 && income <= 383900){  // 24%
            tax = 0.10 * 23200 + 0.12 * (94300 - 23200) + 0.22 * (201050 - 94300) + (income - 201050) * 0.24;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 383901 && income <= 487450){  // 32%
            tax = 0.10 * 23200 + 0.12 * (94300 - 23200) + 0.22 * (201050 - 94300) + 0.24 * (383900 - 201050) + (income - 383900) * 0.32;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 487451 && income <= 731200){  // 35%
            tax = 0.10 * 23200 + 0.12 * (94300 - 23200) + 0.22 * (201050 - 94300) + 0.24 * (383900 - 201050) + 0.32 * (487450 - 383900) + (income - 487450) * 0.35;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 731201){  // 37%
            tax = 0.10 * 23200 + 0.12 * (94300 - 23200) + 0.22 * (201050 - 94300) + 0.24 * (383900 - 201050) + 0.32 * (487450 - 383900) + 0.35 * (731200 - 487450) + (income - 731200) * 0.37;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else{
            std:: cout << "Invalid input\n";
        }
    }

    // married separately filing status
    else if(filing_status == 3){
        if(income >= 0 && income <= 11600){     // 10%
            tax = income * 0.10;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 11601 && income <= 47150){    // 12%
            tax = 0.10 * 11600 + (income - 11600) * 0.12;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 47151 && income <= 100525){   // 22%
            tax = 0.10 * 11600 + 0.12 * (47150 - 11600) + (income - 47150) * 0.22;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 100526 && income <= 191950){  // 24%
            tax = 0.10 * 11600 + 0.12 * (47150 - 11600) + 0.22 * (100525 - 47150) + (income - 100525) * 0.24;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 191951 && income <= 243725){  // 32%
            tax = 0.10 * 11600 + 0.12 * (47150 - 11600) + 0.22 * (100525 - 47150) + 0.24 * (191950 - 100525) + (income - 191950) * 0.32;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 243726 && income <= 365600){   // 35%
            tax = 0.10 * 11600 + 0.12 * (47150 - 11600) + 0.22 * (100525 - 47150) + 0.24 * (191950 - 100525) + 0.32 * (243725 - 191950) + (income - 243725) * 0.35;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 365601){   //37%
            tax = 0.10 * 11600 + 0.12 * (47150 - 11600) + 0.22 * (100525 - 47150) + 0.24 * (191950 - 100525) + 0.32 * (243725 - 191950) + 0.35 * (365600 - 243725) + (income - 365600) * 0.37;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else{
            std:: cout << "Invalid input\n";
        }
    }

    // head of household filing status
    else if(filing_status == 4){    // 10%
        if(income >= 0 && income <= 16550){
            tax = income * 0.10;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 16551 && income <= 63100){    // 12%
            tax = 0.10 * 16550 + (income - 16550) * 0.12;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 63101 && income <= 100500){   // 22%
            tax = 0.10 * 16550 + 0.12 * (63100 - 16550) + (income - 63100) * 0.22;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 100501 && income <= 191950){  // 24%
            tax = 0.10 * 16550 + 0.12 * (63100 - 16550) + 0.22 * (100500 - 63100) + (income - 100500) * 0.24;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 191951 && income <= 243700){  // 32%
            tax = 0.10 * 16550 + 0.12 * (63100 - 16550) + 0.22 * (100500 - 63100) + 0.24 * (191950 - 100500) + (income - 191950) * 0.32;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 243701 && income <= 609350){  // 35%
            tax = 0.10 * 16550 + 0.12 * (63100 - 16550) + 0.22 * (100500 - 63100) + 0.24 * (191950 - 100500) + 0.32 * (243700 - 191950) + (income - 243700) * 0.35;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else if(income >= 609351){  //37%
            tax = 0.10 * 16550 + 0.12 * (63100 - 16550) + 0.22 * (100500 - 63100) + 0.24 * (191950 - 100500) + 0.32 * (243700 - 191950) + 0.35 * (609350 - 243700) + (income - 609350) * 0.37;
            std:: cout << "Your tax is $" << tax << "\n";
        }
        else{
            std:: cout << "Invalid input\n";
        }
    }
    else{
        std:: cout << "Choose only 1 to 4. \n";
    }
}

