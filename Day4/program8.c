/*No.of Days Elapsed*/



#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}

int daysInMonth(int month, int year) {
    int days;
    
    if (month == 2) {
        if (isLeapYear(year)) {
            days = 29;
        } else {
            days = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;
    } else {
        days = 31;
    }
    
    return days;
}

int main() {
    int startYear, startMonth, startDay;
    int endYear, endMonth, endDay;
    int totalDays = 0;
    
    printf("Enter the start date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &startYear, &startMonth, &startDay);
    
    printf("Enter the end date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &endYear, &endMonth, &endDay);
    
    // Calculate days for each year
    for (int year = startYear; year < endYear; year++) {
        if (isLeapYear(year)) {
            totalDays += 366;
        } else {
            totalDays += 365;
        }
    }
    
    // Calculate days for each month
    for (int month = 1; month < startMonth; month++) {
        totalDays -= daysInMonth(month, startYear);
    }
    totalDays -= startDay - 1;
    
    for (int month = 1; month < endMonth; month++) {
        totalDays += daysInMonth(month, endYear);
    }
    totalDays += endDay;
    
    printf("Number of days elapsed: %d\n", totalDays);
    
    return 0;
}
