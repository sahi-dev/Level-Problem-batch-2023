/*Write a simple calculator program which should accept inputs in the same order.
    - Operand 1
    - Operator
    - Operand 2
The order of scan should be same, for example, you should first scan in the following order.
printf("Enter Number1: );
Scan the first number form the user.
printf("Enter the operator: );
Scan the operator from the user.
printf("Enter Number2: );
Scan the second number form the user.*/


#include <stdio.h>

int main(void) {
    float num1, num2, result;
    char operator;

    // Read operand 1
    printf("Enter Number 1: ");
    scanf("%f", &num1);

    // Read operator
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Read operand 2
    printf("Enter Number 2: ");
    scanf("%f", &num2);

    // Perform calculation based on operator
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero\n");
                return 1;
            }
            break;
        default:
            printf("Error: Invalid operator\n");
            return 1;
    }

    // Print the result
    printf("Result: %.2f\n", result);

    return 0;
}
