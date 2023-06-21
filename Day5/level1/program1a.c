/*Use structures to find the volume and the total surface area of the box. 
   You need to access the members of the structure with the help of a structure pointer:
    a. With the help of (*) asterisk or indirection operator and (.) dot operator.*/




#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box* boxPtr) {
    double volume = (*boxPtr).length * (*boxPtr).width * (*boxPtr).height;
    return volume;
}

double calculateSurfaceArea(struct Box* boxPtr) {
    double surfaceArea = 2 * ((*boxPtr).length * (*boxPtr).width +
                              (*boxPtr).width * (*boxPtr).height +
                              (*boxPtr).height * (*boxPtr).length);
    return surfaceArea;
}

int main() {
    struct Box myBox;
    struct Box* boxPtr = &myBox;

    printf("Enter the length of the box: ");
    scanf("%lf", &myBox.length);

    printf("Enter the width of the box: ");
    scanf("%lf", &myBox.width);

    printf("Enter the height of the box: ");
    scanf("%lf", &myBox.height);

    double volume = calculateVolume(boxPtr);
    double surfaceArea = calculateSurfaceArea(boxPtr);
    
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}
