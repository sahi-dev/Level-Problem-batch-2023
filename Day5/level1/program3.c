/*Write a program using structures to calculate the difference between two time periods using a user-defined function.*/




#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time calculateTimeDifference(struct Time* t1, struct Time* t2) {
    struct Time diff;
    int seconds1, seconds2, timeDiff;

    seconds1 = t1->hours * 3600 + t1->minutes * 60 + t1->seconds;
    seconds2 = t2->hours * 3600 + t2->minutes * 60 + t2->seconds;

    timeDiff = seconds1 - seconds2;

    diff.hours = timeDiff / 3600;
    timeDiff = timeDiff % 3600;

    diff.minutes = timeDiff / 60;
    diff.seconds = timeDiff % 60;

    return diff;
}

int main() {
    struct Time time1, time2, diff;

    printf("Enter the first time period:\n");
    printf("Hours: ");
    scanf("%d", &(time1.hours));
    printf("Minutes: ");
    scanf("%d", &(time1.minutes));
    printf("Seconds: ");
    scanf("%d", &(time1.seconds));

    printf("\nEnter the second time period:\n");
    printf("Hours: ");
    scanf("%d", &(time2.hours));
    printf("Minutes: ");
    scanf("%d", &(time2.minutes));
    printf("Seconds: ");
    scanf("%d", &(time2.seconds));

    diff = calculateTimeDifference(&time1, &time2);

    printf("\nDifference between the time periods: %d hours, %d minutes, %d seconds\n",
           diff.hours, diff.minutes, diff.seconds);

    return 0;
}
