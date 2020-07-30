#include <stdio.h>
#include <unistd.h>
int main(){

	int r;
	
	r = unlink("5_delete_this.txt");
	if (r==0)
		puts("File deleted");
	else
		puts("Failed");	

	return(0);

}
