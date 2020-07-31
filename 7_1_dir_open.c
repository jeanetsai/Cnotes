#include <stdio.h>
#include <dirent.h>

int main(){
	
	DIR *directory;
	
	/*open the directory*/
	directory = opendir(".");
		if( directory == NULL ) //failed to open dir
		{
			puts("Unable to open current directory");
			return(1);
		}
		
	/*dir opened, do something*/
	puts("Opened current directory");
	
	/*close the directory*/
	closedir(directory);

	return(0);



}




