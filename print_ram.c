#include <stdio.h>

void prnt_1_byte(char *);
void prnt_2_bytes(short *);
void prnt_4_bytes(int *);
void prnt_8_bytes(double *);

int main() {
    char char_var = 'A';
    short short_var = 99;
    int count, quant,offset,step, int_var = 9999;
    double double_var = 9999.9999;

    printf("\nEnter quantity/offset/step: ");

    scanf("%d/%d/%d", &quant, &offset, &step);

    printf("\n     Sizes on this machine:\n       size of char: %u byte\n       size of short: %u bytes\n       size of int: %u bytes\n       size of float: %u bytes\n       size of double: %u bytes\n \n", sizeof(char), sizeof(short), sizeof(int), sizeof(float), sizeof(double));

    for (count = offset; count < ((quant * step) + offset); count += step) {

        prnt_1_byte(&char_var + count);

        prnt_2_bytes(&short_var + count);

        prnt_4_bytes(&int_var + count);

        prnt_8_bytes(&double_var + count);
    }
    
    return 0;
}

void prnt_1_byte(char *ptr) {
    
    printf("\nAddress: %p\n", ptr);
    
    printf("Size: %u bytes\n", sizeof(* ptr));

    printf("Value: | short: %hd | int: %d | float %.2lf | hex: %x | char: %c |\n \n", *ptr, *ptr, *ptr, *ptr, *ptr);
}

void prnt_2_bytes(short *ptr) {
    
    printf("\nAddress: %p\n", ptr);
    
    printf("Size: %u bytes\n", sizeof(* ptr));

    printf("Value: | short: %hd | int: %d | float %.2lf | hex: %x | char: %c |\n \n", *ptr, *ptr, *ptr, *ptr, *ptr);
}

void prnt_4_bytes(int *ptr) {
    
    printf("\nAddress: %p\n", ptr);

    printf("Size: %u bytes\n", sizeof(* ptr));

    printf("Value: | short: %hd | int: %d | float %.2lf | hex: %x | char: %c |\n \n", *ptr, *ptr, *ptr, *ptr, *ptr);
}

void prnt_8_bytes(double *ptr) {

    printf("\nAddress: %p\n", ptr);

    printf("Size: %u bytes\n", sizeof(* ptr));

    printf("Value: | short: %hd | int: %d | float: %.2lf | hex: %x | char: %c |\n______________________________________________________________\n", *ptr, *ptr, *ptr, *ptr);
}