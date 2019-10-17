#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    long cnum;
    char partly[16];
    bool luhn = false;
    int j = 0;
    string ctype = "INVALID";
    cnum = get_long("Number: ");
    int nDig = floor(log10(cnum)) + 1;
    if (nDig != 13 && nDig != 15 && nDig != 16)
    {
        printf("%s\n", ctype);
        return 0;
    }
    sprintf(partly, "%li", cnum);
    for (int i = 0; i < nDig ; i++)
        if ((i / 2) * 2 == i)
            if (partly[i] - '0' > 4)
            {
                j = j + (partly[i] - '5') * 2 + 1;
            }
            else
            {
                j = j + (partly[i] - '0') * 2;
            }
        else
        {
            j += partly[i] - '0';
        }
    if ((j / 10) * 10 == j)
    {
        luhn = true;
    }
    if (partly[0] == '4' && luhn)
    {
        ctype = "VISA";
    }
    else if (partly[0] == '3' && (partly[1] == '4' || partly[1] == '7'))
    {
        ctype = "AMEX";
    }
    else if (luhn && partly[0] == '5' && (partly[1] - '0' > 0 && partly[1] - '0' < 6))
    {
        ctype = "MASTERCARD";
    }
    printf("%s\n", ctype);
}