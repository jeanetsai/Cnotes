#include <stdio.h>

int main(){

printf("char\t%lu\n",sizeof(char));
printf("int\t%lu\n",sizeof(int));
printf("float\t%lu\n",sizeof(float));
printf("double\t%lu\n",sizeof(double));
/*output:1 4 4 8 ptr+1 若為char則移動1 int則移動4 float則移動4 double移動8*/
}

