#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

#define DIGIT 4

int main()
{
    // bi1 = 2*10^0, const
    BigInt bi1 = malloc(sizeof(struct Node));
    bi1->Next = NULL;

    BigInt bi2 = malloc(sizeof(struct Node));
    bi2->Next = NULL;

    BigInt addres = malloc(sizeof(struct Node));
    addres->Next = NULL;

    int bi1_c[DIGIT] = { 2,4,3,9 };
    int bi1_e[DIGIT] = { 3,2,1,0 };

    int bi2_c[DIGIT-1] = { 8,0,9 };
    int bi2_e[DIGIT-1] = { 2,1,0 };

    BigIntConstructor(bi1_c, bi1_e, DIGIT, bi1);
    BigIntConstructor(bi2_c, bi2_e, DIGIT-1, bi2);

    printf("BigInt 1:\n");
    PrintBigInt(bi1);

    printf("BigInt 2:\n");
    PrintBigInt(bi2);

    addres = BigIntAdd(bi1, bi2);
    printf("BigInt added:\n");
    PrintBigInt(addres);

    DeleteBigInt(bi1);
    DeleteBigInt(addres);
    DeleteBigInt(bi2);

    //2**4000
    int bi3_c[1] = { 2 };
    int bi3_e[1] = { 0 };

    BigInt multires = malloc(sizeof(struct Node));
    multires->Next = NULL;

    BigInt bi3 = malloc(sizeof(struct Node));
    bi3->Next = NULL;

    BigIntConstructor(bi3_c, bi3_e, 1, bi3);
    //BigIntConstructor(bi3_c, bi3_e, 1, multires);
    int cnt = 1;
    while (cnt < 4000)
    {
        BigInt bitmp = multires;
        multires = BigIntMulti(bi3, bitmp);
        DeleteBigInt(bitmp);
        cnt++;
    }

    unsigned len = Length(multires);
    printf("BigInt multiplied BigInt digits %d:\n", len);
    PrintBigInt(multires);

    int digit_counts[10] = { 0 };

    CountDigits(multires, digit_counts);
    for (int i = 0; i < 10; i++)
        printf("count of digit %d: %d\n", i, digit_counts[i]);

    DeleteBigInt(bi3);
    DeleteBigInt(multires);

    return 0;
}