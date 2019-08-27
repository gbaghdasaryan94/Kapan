#include <stdio.h>
#include "b.h"

int main() {
    int n=5;
    int m=5;
    int z=1;
    int i;
    int j;
    for (j=0; j<n;j++){
	for (i=0; i<=n*2;i++){
	    if (i>=m && i<=n+z)
	        printf("#");
	    else
	    printf(" ");
/*	    if (i==n)
	    printf(" ";*/
	}
	printf("\n");
	    m=m-1;
	    z=z+1;

	}


}
