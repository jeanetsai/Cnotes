#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(){

	const char filename[] = "8_thisfileinfo.txt";
	struct stat fstat;
	
	stat(filename,&fstat);
	printf("%s is %ld bytes long\n",
			filename,
			fstat.st_size
			);
	printf("It was modified on %s", ctime(&fstat.st_mtime));

	return (0);

/*output: 8_thisfileinfo.txt is 0 bytes long
It was modified on Fri Jul 31 21:16:28 2020
*/
}
