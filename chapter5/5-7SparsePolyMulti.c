#include <stdio.h>

int main()
{
    int a = 67, b = 155;
    int c = ((a & b) << 1) + (a ^ b);
    printf("%d\n", c);
    return 0;
}