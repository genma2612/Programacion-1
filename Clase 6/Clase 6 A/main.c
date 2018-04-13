#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int vector[5]={5,2,8,6,5};
    int a = 9;
    int b = 5;
    int c;
    //swap
    c = a;
    a = b;
    b = c;
    printf("a = %d - b %d - c %d\n", a, b, c);
    return 0;
}
