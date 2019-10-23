#include <stdio.h>
#include <math.h>

int main()

{
    float n=-8;
    float p=pow(2, n/12);
    float f=round(440*p);

    printf("%f\n", f);
}