#include <stdio.h>

int main(){
	FILE *p;
	int c;
	/*Open the process*/
	//p = popen("uname","r"); /*Unix*/
	p = popen("ver","r");   /*Windows*/
	
	if ( p == NULL){
		puts("Unable to creat process");
		return(1);
	}
	 /*Read from the process*/
	while((c=fgetc(p)) != EOF){
		putchar(c);
	}
	pclose(p);
/*Output:
Microsoft Windows [ª©¥» 6.1.7600]*/
return (0);
} 


