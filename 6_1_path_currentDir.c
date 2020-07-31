#include <stdio.h>
#include <unistd.h>

int main(){
	
	char path[512];
	//getcwd = Get current working directory
	getcwd(path,512);
	printf("This program is running in the %s directory \n", path);
	/* Output:
	This program is running in the C:\users\admin\desktop directory 
	*/
	return(0);



}




