#include<stdio.h>
#include<cs50.h>

void say(string word,int n);
void caugh(int n);
void apchi(int n);

int main(void)
{
    apchi(7);
}

void say(string word,int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%s \n",word);
    }
}

void caugh(int n)
{
    say("caugh",n);
}

void apchi(int n)
{
    say("apchi",n);
}