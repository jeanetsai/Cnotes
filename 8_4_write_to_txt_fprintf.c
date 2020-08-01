#include <stdio.h>
#include <unistd.h>
int main(){



FILE *f = fopen("8_4_file.txt", "w");
if (f == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}

/* print some text */
const char *text = "Write this to the file";
fprintf(f, "Some text: %s\n", text);

/* print integers and floats */
int i = 1;
float py = 3.1415927;
fprintf(f, "Integer: %d, float: %f\n", i, py);

/* printing single chatacters */
char c = 'A';
fprintf(f, "A character: %c\n", c);

fclose(f);

/*Output:
Some text: Write this to the file
Integer: 1, float: 3.141593
A character: A
*/
return (0);
} 


