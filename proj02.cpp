// proj02.cpp
// This program asks the user for a date (year, month, and day) on or after Jan 1, 2000.
// It prints the day of the week for that date and then prints the calendar for that month.
// The program repeats until the user decides to quit.

#include <iostream>
#include <string>
#include <iomanip>

// Month and Weekdays
const std:: string WEEKDAYS[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

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

    // add days in the current month (days before the given day)
    total_days += day - 1; // subtract 1 because we start counting from day 0

    return total_days;
}

// function to print the calendar format
void printCalendar(int year, int month){
    // compute weekday of the 1st of the month (use day = 1)
    int days_before_first = totalDaysSince2000(year, month, 1);
    int first_weekday = (days_before_first + 6) % 7; // 6 is the anchor for Jan 1, 2000

    std:: cout << "    " << MONTHS[month - 1] << " " << year << "\n";
    std:: cout << "Su Mo Tu We Th Fr Sa\n";

    // print blank spaces before 1st day
    // each column is 3 chars wide (setw(2) + " "), so use 3 spaces per blank column
    for(int i = 0; i < first_weekday; i++){
        std:: cout << "   ";
    }

    // print all the days of the month
    int days_in_month = daysInMonth(year, month);

    for(int d = 1; d <= days_in_month; d++){
        // print day in width 2 with one trailing space -> total 3 chars per column
        std:: cout << std:: setw(2) << d << " ";

        // weekday of this day (0=Sun .. 6=Sat)
        int current_weekday = (first_weekday + d - 1) % 7;

        // newline after Saturday
        if(current_weekday == 6){
            std:: cout << "\n";
        }
    }

    // ensure final newline if last day wasn't Saturday (run this once, after the loop)
    if ((first_weekday + days_in_month - 1) % 7 != 6){
        std:: cout << "\n";
    }
}

int main(){
    std:: cout << "\n";
    std:: cout << "Welcome to the Perpetual Calendar Program! \n";
    std:: cout << "\n";

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
        int total_days = totalDaysSince2000(year, month, day);

        // Jan 1, 2000 was a Saturday. We want 0 = Sunday, 1 = Monday, ..., 6 = Saturday
        int weekday = (total_days + 6) % 7; 

        // print result sentence
        std:: cout << MONTHS[month - 1] << " " << day << ", " << year <<
                    " falls on a " << WEEKDAYS[weekday] << ".\n\n";

        // print the calendar for that month (based on 1st's weekday)
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
    return 0;
}
