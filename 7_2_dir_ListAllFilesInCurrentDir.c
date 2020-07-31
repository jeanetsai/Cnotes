#include <stdio.h>
#include <dirent.h>

int main(){
	
	DIR *directory;
	//列出目前資料夾下的所有檔案 
	struct dirent *file;
	
	/*open the directory*/
	directory = opendir(".");
		if( directory == NULL ) //failed to open dir
		{
			puts("Unable to open current directory");
			return(1);
		}
		
	/*dir opened, do something*/
	//找到檔案了 
	file= readdir(directory);
	printf("I Found the file %s \n", file->d_name);
	
	//列出目前資料夾下的所有檔案 
	while ( (file=readdir(directory)) != NULL)
		printf("Found the file %s \n", file->d_name);
	
	//puts("Opened current directory");
	
	/*close the directory*/
	closedir(directory);

	return(0);



}




