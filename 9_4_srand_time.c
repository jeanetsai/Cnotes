#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

	int x,r;

	srand((unsigned)time(NULL));

	for(x=0;x<100;x++)
	{
	r=rand()%100 +1;
	/* 原本是0-99 
	+1後是1-100*/
	printf("%4d ", r);
	}
	putchar('\n');
return (0);
}
