#include <stdio.h>
#include <stdlib.h>
int main(){
	
	const char filename[] = "4_file.txt";
	FILE *fh;
	char buffer[64];	
	/* open the file */
	fh = fopen(filename, "r");
		if (fh == NULL){
			printf("Unable to read from file %s \n",filename);
			return(1);
		}
	
	printf("File '%s' opened \n", filename);
	
	/* read the file 64 characters at a time */
	while( fgets(buffer,64,fh) )
		printf("%s", buffer);
	
	
	/* close when you're done*/
	fclose(fh);
	
	return(0);
	
/* Output:
File '4_file.txt' opened	
This is a book.
That is a pen.*/

}
