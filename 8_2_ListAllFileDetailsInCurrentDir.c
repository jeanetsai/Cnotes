#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

int main(){
	
	//
	DIR *directory;
	//
	struct dirent *file;
	struct stat fstat;

	/*open the directory*/
	directory = opendir(".");
		if( directory == NULL ) //failed to open dir
		{
			puts("Unable to open current directory");
			return(1);
		}
	//dir opened, do something	
	printf("%-25s %-10s %s \n","Filename","Size","Timestamp");
	//�C�X�ثe��Ƨ��U���Ҧ��ɮשM��Ƨ� 
	while ( (file=readdir(directory)) != NULL){
		stat(file->d_name,&fstat);
		//
		if( S_ISDIR(fstat.st_mode))
			printf(" Dir ");
		else	
			printf(" File ");
			
		printf("%25s %10ld ",
				file->d_name,
				fstat.st_size
			);
		printf("%s", ctime(&fstat.st_mtime));
	}
			
	/*close the directory*/
	closedir(directory);

	return (0);

/*output: �ثe��Ƨ��U�Ҧ��ɮשM��Ƨ����ԲӸ�� 
*/
}
