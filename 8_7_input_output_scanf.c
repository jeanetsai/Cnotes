#include <stdlib.h>
#include <stdio.h>


int main(){
    FILE *infile,*outfile;
    long a;
    double  b, c, sum=0;
    char d;
    infile = fopen("8_7_input.txt", "r");
    outfile = fopen("8_7_output.txt", "a");

    if(infile == NULL && outfile == NULL){
       printf("File DOES NOT EXIST");
    }
    else{
         while(feof(infile)== 0)
         {
              fscanf(infile, "%ld %lf %lf", &a, &b, &c); 
              printf("%ld %.3f %.3f\n", a, b, c); 
              fprintf(outfile,"%ld %.3f %.3f\n", a, b, c); 
              sum = a + b + c;
         }
    }
    
    printf("sum is %.3f\n", sum);
    fprintf(outfile,"sum is %.3f\n", sum);
    fclose(infile);
    fclose(outfile);
    system("pause");
}

