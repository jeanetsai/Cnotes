#include <stdio.h>

int main(){

	int r;
	
	r = rename("5_rename.txt","5_renamedone.txt");
	if (r==0)
		puts("Rename operation successful");
	else
		puts("Rename failed");	

	return(0);

}
