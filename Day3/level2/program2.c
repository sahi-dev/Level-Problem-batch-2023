/*BCD to Decimal:
https://1.bp.blogspot.com/-Tfj_D_f_AF0/VZO5QIIGAUI/AAAAAAAAAmI/5Rw6uIU3EiI/s1600/DS1307%2BTime%2BKeeper%2BRegister.PNG

DS1307 has its time registers in BCD format as shown in the image found in the above link, To set the time we need to convert the decimal number to BCD format, hence, write a fucntion to convert decimal to BCD

Concepts to be used.
- Operators
- Preprocessor*/



#include <stdio.h>

// Function to convert decimal to BCD
unsigned char decimalToBCD(unsigned char dec) {
  // Get the individual digits of the decimal number
  unsigned char hundreds = dec / 100;
  unsigned char tens = (dec % 100) / 10;
  unsigned char units = dec % 10;

  // Convert each digit to BCD
  hundreds = hundreds << 4;
  tens = tens << 2;

  // Check for the carry bit
  if (hundreds > 0xF) {
    hundreds = hundreds & 0xF;
    tens = tens | 0x10;
  }

  // Combine the BCD digits
  return hundreds | tens | units;
}

int main() {
  // Get a decimal number from the user
  unsigned char dec;
  printf("Enter a decimal number: ");
  scanf("%d", &dec);

  // Convert the decimal number to BCD
  unsigned char bcd = decimalToBCD(dec);

  // Print the BCD number in hexadecimal format
  printf("The BCD number is: 0x%X\n", bcd);

  return 0;
}




