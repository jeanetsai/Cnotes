#include <stdio.h>

int main(){

	char *veeps[5]={"Adams","Jeff","Burr","Clinton","George"};
	int x;


	for(x=0;x<5;x++){
		printf("%s \n",*(veeps+x));
	}
	/*output:
	Adams  
	Jeff
	Burr
	Clinton
	George
	*/
	for(x=0;x<5;x++){
		printf("%c \n",*(*(veeps+x)));
	}	
	/*output:
	A  
	J
	B
	C
	G
	*/	
}




