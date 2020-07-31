#include <stdio.h>
#include <dirent.h>

int main(){
	
	DIR *directory;
	//�C�X�ثe��Ƨ��U���Ҧ��ɮ� 
	struct dirent *file;
	
	/*open the directory*/
	directory = opendir(".");
		if( directory == NULL ) //failed to open dir
		{
			puts("Unable to open current directory");
			return(1);
		}
		
	/*dir opened, do something*/
	//����ɮפF 
	file= readdir(directory);
	printf("I Found the file %s \n", file->d_name);
	
	//�C�X�ثe��Ƨ��U���Ҧ��ɮ� 
	while ( (file=readdir(directory)) != NULL)
		printf("Found the file %s \n", file->d_name);
	
	//puts("Opened current directory");
	
	/*close the directory*/
	closedir(directory);

	return(0);



}




