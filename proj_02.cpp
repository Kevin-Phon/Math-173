// proj02.cpp
// This program asks the user for a date (year, month, and day) on or after Jan 1, 2000.
// It prints the day of the week for that date and then prints the calendar for that month.
// The program repeats until the user decides to quit.

#include <iostream>
#include <string>
#include <iomanip>

// Month and Weekdays
const std:: string WEEKDAYS[7] = {"Sunday", "Monday", 
                                "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

const std:: string MONTHS[12] = {"January", "February", "March", "April", "May", "June", "July", 
                            "August", "September", "October", "November", "December"};

// function for leap year
// checks if a year is a leap year
bool isLeapYear(int year){
    if (year % 400 == 0) return true;
    else if (year % 100 == 0) return false;
    else if (year % 4 == 0) return true;
    else return false;
}

// function for days in month
// return number of days in the given month
int daysInMonth(int year, int month){
    switch(month){
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0; // invalid month
    }
}

// function for total days since January 1, 2000
int totalDaysSince2000(int year, int month, int day){
    int total_days = 0;

    // add days for complete years since 2000
    for(int y = 2000; y < year; y++){
        total_days += isLeapYear(y) ? 366 : 365;
    }

    // add days for complete months in the current year
    for(int m = 1; m < month; m++){
        total_days += daysInMonth(year, m);
    }

    // add days in the current month
    total_days += day - 1; // subtract 1 because we start counting from day 0

    return total_days;
}

// function to print the calendar format
void printCalendar(int year, int month){

    // compute weekday of the 1st of the month (use day = 1)
    int days_before_first = totalDaysSince2000(year, month, 1);
    int first_weekday = (days_before_first + 6) % 7; // 6 is the day of the week for Jan 1, 2000, 0 = Sun, ..., 6 = Sat

    std:: cout << "    " << MONTHS[month - 1] << " " << year << "\n";
    std:: cout << "Su Mo Tu We Th Fr Sa\n";

    // print balnk spaces before 1st day
    // each column will be 3 characters: two for number (right-aligned) and one space separator
    // so, three spaces "   " for a blank column
    for(int i = 0; i < first_weekday; i++){
        std:: cout << "   ";
    }

    // print all the days of the month
    int days_in_month = daysInMonth(year, month);
    // for each day compute its weekday
    for(int d = 1; d <= days_in_month; d++){    
        std:: cout << std::setw(2) << d << " ";    // right-align in width 2, then print a space -> column width = 3

        int current_weekday = (first_weekday + d - 1) % 7;    // this calculates the weekday of the current day d, 0 = Sun, 6 = Sat
        if(current_weekday == 6){ // if Sat -> newline     // for day d, add (d - 1) days and % by 7
            std:: cout << "\n";
        }

        // ensure final new line if last day wasn't Saturday
        if((first_weekday + days_in_month -1) % 7 != 6){
            std:: cout << "\n";
        }

    }
    std:: cout << "\n";
}

int main(){
    std:: cout << "\n";
    std:: cout << "Welcome to the Perpetual Calendar Program! \n";
    std:: cout << "\n";

    // char again = 'y';
    while(true){

        int year, month, day;

        std:: cout << "Enter a year: ";
        std:: cin >> year;

        std:: cout << "Enter a month (1=Jan, 2=Feb, ...): ";
        std:: cin >> month;

        std:: cout << "Enter a numerical date (1-31): ";
        std:: cin >> day;
        std:: cout << "\n";

        // total days since Jan 1, 2000
        // recall totalDaysSince2000 function
        int total_days = totalDaysSince2000(year, month, day);

        // Jan 1, 2000 was a Saturday. We want 0 = Sunday, 1 = Monday, ..., 6 = Saturday
        // so add 6 then take modulo 7 (same logic from the printCalendar function)
        int weekday = (total_days + 6) % 7; 

        // print result sentence
        // if the user types 1 (January), month - 1 = 0 → MONTHS[0] → "January".
        std:: cout << MONTHS[month - 1] << " " << day << ", " << year <<
                    " falls on a " << WEEKDAYS[weekday] << ".\n\n";

        // print the calendar for that month
        // recall printCalendar function
        printCalendar(year, month);
        std:: cout << "\n";

        // ask to continue
        char again;
        std:: cout << "\nWould you like to enter another date? (y/n): ";
        std:: cin >> again;
        std:: cout << "\n";
        if (again == 'n' || again == 'N'){
            std:: cout << "Thank you!\n";
            break;
        }
    }
}