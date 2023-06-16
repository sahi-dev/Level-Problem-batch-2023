/*Bit Operations:
https://1.bp.blogspot.com/-Tfj_D_f_AF0/VZO5QIIGAUI/AAAAAAAAAmI/5Rw6uIU3EiI/s1600/DS1307%2BTime%2BKeeper%2BRegister.PNG

DS1307 has its time registers in BCD format as shown in the image found in the above link, so 
a. Write a function to Set, clear and toggle bit of an 8-bit number

Concepts to be used.
- Operators*/



#include <stdio.h>

void set_bit(unsigned char *number, int bit_number) {
  *number |= (1 << bit_number);
}

void clear_bit(unsigned char *number, int bit_number) {
  *number &= ~(1 << bit_number);
}

void toggle_bit(unsigned char *number, int bit_number) {
  *number ^= (1 << bit_number);
}

int main() {
  unsigned char number;
  printf("Enter a number: ");
  scanf("%hhx", &number);

  set_bit(&number, 0);
  printf("After setting bit 0, number = 0x%x\n", number);

  clear_bit(&number, 1);
  printf("After clearing bit 1, number = 0x%x\n", number);

  toggle_bit(&number, 2);
  printf("After toggling bit 2, number = 0x%x\n", number);

  return 0;
}

