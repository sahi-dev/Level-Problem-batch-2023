/*Use structures to find the volume and the total surface area of the box. 
   You need to access the members of the structure with the help of a structure pointer:
    b. With the help of ( -> ) Arrow operator using pointer as well as dot representation.*/




#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box *box) {
    return box->length * box->width * box->height;
}

double calculateSurfaceArea(struct Box *box) {
    double length = box->length;
    double width = box->width;
    double height = box->height;

    return 2 * (length * width + length * height + width * height);
}

int main() {
    struct Box myBox;
    struct Box *ptrBox = &myBox;

    printf("Enter the length of the box: ");
    scanf("%lf", &(ptrBox->length));

    printf("Enter the width of the box: ");
    scanf("%lf", &(ptrBox->width));

    printf("Enter the height of the box: ");
    scanf("%lf", &(ptrBox->height));

    double volume = calculateVolume(ptrBox);
    double surfaceArea = calculateSurfaceArea(ptrBox);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}
