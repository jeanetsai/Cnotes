#include <stdio.h>
#include <unistd.h>
int main(){



FILE *fp;
char* str = "string";
int x = 10;

fp=fopen("8_5_file.txt", "w");
if(fp == NULL)
    exit(-1);
fprintf(fp, "This is a string which is written to a file\n");
fprintf(fp, "The string has %d words and keyword %s\n", x, str);
fclose(fp);

return (0);

}
