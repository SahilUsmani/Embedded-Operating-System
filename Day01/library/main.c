
#include<stdio.h>
#include"arithmetic.h"
#include"arith.h"
#include"arithmat.h"
int main(void)
{
    int res = 0;

    res = add(90,2);
    printf("Addition:: %d\n", res);

    res = sub(90,2);
    printf("Subtraction:: %d\n", res);

    res = mul(90,2);
    printf("Multiplication:: %d\n", res);

    res = div(90,2);
    printf("Division:: %d\n", res);

    res = mod(90,2);
    printf("Remainder:: %d\n", res);

    res = sqr(9);
    printf("Square:: %d\n", res);

    return 0;
}
