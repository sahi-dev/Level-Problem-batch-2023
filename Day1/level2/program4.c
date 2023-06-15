/*Write a function to accept an integer (32 bits) and operation type to do the following and return the result to main function.
    - Set 2 bits from nth bit position, if operation type is 1
    - Clear 3 bits from nth bit position, if operation type is 2
    - Toggle MSB, if operation type is 3
   You can consider the below function prototype,
    - bit_operations(int num, int oper_type, int pos);*/



#include <stdio.h>

int bit_operations(int num, int oper_type, int pos) {
    int result = num; // Initialize the result with the input number

    switch (oper_type) {
        case 1: // Set 2 bits from nth bit position
            result |= (0x3 << pos);
            break;
        case 2: // Clear 3 bits from nth bit position
            result &= ~(0x7 << pos);
            break;
        case 3: // Toggle MSB
            result ^= (1 << 31);
            break;
        default:
            printf("Invalid operation type.\n");
            return 0;
    }

    return result;
}

int main() {
    int num, oper_type, pos;
    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);
    printf("Enter the operation type (1: Set bits, 2: Clear bits, 3: Toggle MSB): ");
    scanf("%d", &oper_type);
    
    if (oper_type == 1 || oper_type == 2) {
        printf("Enter the bit position: ");
        scanf("%d", &pos);
    }

    int result = bit_operations(num, oper_type, pos);
    printf("Result: %d\n", result);

    return 0;
}
