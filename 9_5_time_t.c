#include <stdio.h>
#include <time.h>

int main(){
	
	time_t now;
	
	time(&now);
	printf("It is now %ld\n",now);
	
	/*Output: It is now 1596268189*/
	
	
	return (0);
}
