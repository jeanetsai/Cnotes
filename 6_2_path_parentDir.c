#include <stdio.h>
#include <unistd.h>

int main(){
	
	char path[512];

	//get parent directory
	chdir("..");
	getcwd(path,512);	//getcwd = Get current working directory
	printf("This program's parent directory is %s \n", path);
	/* Output:
	This program's parent directory is C:\users\admin\  
	*/
	return(0);



}




