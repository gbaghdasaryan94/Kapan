#include <stdio.h>
//to use 'sound()', 'delay()' functions
#include <dos.h>

int main()
{
	int k;
	//loop to increment the value of a till 100.
	for ( k = 1 ; a <= 100 ; a = k++ )
	{
		//calling the function for producing
		//the sound of value a.
		sound(a);
		//delay the sound 10 miliseconds.
		delay(10);
	}
	// function to stop the system sound.
	nosound();
	return 0;
}