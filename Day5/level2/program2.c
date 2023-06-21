/*Write a program to enter to Cartesian coordinate points and display the distance between them.*/




#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

float calculateDistance(struct Point p1, struct Point p2) {
    float distance;
    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distance;
}

int main() {
    struct Point point1, point2;

    printf("Enter the coordinates of Point 1:\n");
    printf("x-coordinate: ");
    scanf("%f", &point1.x);
    printf("y-coordinate: ");
    scanf("%f", &point1.y);

    printf("Enter the coordinates of Point 2:\n");
    printf("x-coordinate: ");
    scanf("%f", &point2.x);
    printf("y-coordinate: ");
    scanf("%f", &point2.y);

    float distance = calculateDistance(point1, point2);

    printf("The distance between the two points is: %.2f\n", distance);

    return 0;
}
