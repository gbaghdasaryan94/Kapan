#include <stdio.h>

/*using namespace std;*/

int main(void) {
	int a=1;
	int b=5;
	int c=25;
	int d=50;
	int p=109;
	int hisun=0;
	int qsanhing=0;
	int hing=0;
	int mek=0;
	while (p>0) {
	    if (p-d>=0) {
	        p=p-d;
	        hisun=hisun+1;
	    } else
	    if (p-c>=0) {
	        p=p-c;
	        qsanhing=qsanhing+1;
	    }
	   if (p-b>=0) {
	       p=p-b;
	       hing=hing+1;
	   }
	   if (p-a>=0) {
	       p=p-a;
	       mek=mek+1;
	   }
	}
printf("Hisun= %i \n", hisun);
printf("Qsanhing= %i \n", qsanhing);
printf("Hing= %i \n", hing);
printf("Mek= %i \n", mek);
}