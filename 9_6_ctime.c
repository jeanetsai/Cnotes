#include <stdio.h>
#include <time.h>

int main(){
	
	time_t now;
	
	time(&now);
	printf("It is now %s",ctime(&now));
	
	/*Output: It is now Sat Aug 01 15:54:07 2020*/
	
	
	return (0);
}
