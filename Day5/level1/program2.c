/*Write a C program that uses functions to perform the following operations: 
     i) Reading a complex number 
     ii) Writing a complex number 
     iii) Addition of two complex numbers 
     iv) Multiplication of two complex numbers 
  (Note: represent complex number using a structure.*/




#include <stdio.h>

struct Complex {
    double real;
    double imaginary;
};

// Function to read a complex number from the user
void readComplex(struct Complex* c) {
    printf("Enter the real part: ");
    scanf("%lf", &(c->real));

    printf("Enter the imaginary part: ");
    scanf("%lf", &(c->imaginary));
}

// Function to write a complex number to the console
void writeComplex(const struct Complex* c) {
    if (c->imaginary < 0) {
        printf("Complex number: %.2f - %.2fi\n", c->real, -c->imaginary);
    } else {
        printf("Complex number: %.2f + %.2fi\n", c->real, c->imaginary);
    }
}

// Function to add two complex numbers
struct Complex addComplex(const struct Complex* c1, const struct Complex* c2) {
    struct Complex result;
    result.real = c1->real + c2->real;
    result.imaginary = c1->imaginary + c2->imaginary;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(const struct Complex* c1, const struct Complex* c2) {
    struct Complex result;
    result.real = (c1->real * c2->real) - (c1->imaginary * c2->imaginary);
    result.imaginary = (c1->real * c2->imaginary) + (c1->imaginary * c2->real);
    return result;
}

int main() {
    struct Complex complex1, complex2, sum, product;

    printf("Reading complex number 1:\n");
    readComplex(&complex1);

    printf("\nReading complex number 2:\n");
    readComplex(&complex2);

    printf("\nComplex number 1:\n");
    writeComplex(&complex1);

    printf("\nComplex number 2:\n");
    writeComplex(&complex2);

    sum = addComplex(&complex1, &complex2);
    printf("\nSum of the two complex numbers:\n");
    writeComplex(&sum);

    product = multiplyComplex(&complex1, &complex2);
    printf("\nProduct of the two complex numbers:\n");
    writeComplex(&product);

    return 0;
}
