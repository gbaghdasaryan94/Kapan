//greedy
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float nn=get_float("Money $: ");
    int n=100 * nn;
    int q1=25, q2=10, q3=5, q4=1;
    int c1 = n / q1;
    int c2 = n % q1 / q2;
    int c3 = n % q1 % q2 / q3;
    int c4 = n % q1 % q2 % q3 / q4;
    printf("25c %i, 10c %i, 5c %i, 1c %i", c1, c2, c3, c4);
    return 0;
}
