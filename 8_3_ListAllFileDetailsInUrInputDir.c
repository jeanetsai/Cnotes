#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

/*#include <sys/stat.h>
#include <time.h>*/
#define SIZE 512

int main(){
	
	//
	DIR *directory;
	FILE *output;
	struct dirent *entry;
	char path[SIZE];
	const char filename[] = "8_3_filelist.txt";
	int x,r;

	/*Open the output file 8_3_filelist.txt*/
	output = fopen(filename,"w");
	if (output == NULL) //failed to open 8_3_filelist.txt
	{
			printf("Unable to create file %s \n",filename);
			return (1);	
	}
	/*Fetch path from user's INPUT C:\Users\admin\Desktop\
	for the directory to read 使用者鍵入這個資料夾位置*/
	printf("Enter the directory to examine: ");
	fgets(path,SIZE,stdin);
	/* remove the newline */
	for(x=0;x<SIZE;x++)
	{
		if(path[x] == '\n')
		{
			path[x] = '\0';
			break;
		}
	}
/*change to the directory supplied by the user*/
	r = chdir(path); 
	//若此處failed代表input的path為invalid 
	if(r != 0)
	{
			printf("Unable to change to '%s' \n", path);
			fclose(output);
			return (1);
	}



	/*open the directory*/
	directory = opendir(path);
		if( directory == NULL ) //failed to open dir
		{
			printf("Unable to open directory %s \n",path);
			fclose(output); //記得關檔 
			return(1);
		}
	//Read the directory and save the filenames
	//列出目前資料夾下的所有檔案和資料夾 
	while ( (entry=readdir(directory)) != NULL){

		fprintf(output,"%s \n", entry->d_name);
	}
	printf("%s created listing files in %s \n",filename,path);
	
			
	/*close the directory*/
	fclose(output);
	closedir(directory);

	return (0);

/*output: 鍵入資料夾下所有檔案和資料夾的詳細資料 
*/
}
