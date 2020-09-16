
Pointer => memory or a chunk of memory

03 - Understanding pointers
1. A pointer is declared as a specific data type
char a;
char*ptr
2. A pointer must be initialized before it's used

The pointer's Dual Nature

Pointer宣告時必須有 星星符號
char *ptr

The pointer variable is used with or without
the 星星符號

沒有星星時
ptr = refer to an address
有星星時
*ptr = the value stored at the address

EX01_01
#include <stdio.h>

int main()
{
	char a;
	char *ptr;

	/* initialize variables! */
	a = 'A';

	printf("Value of variable 'a': %c\n",a); //output:character A
	/* assign ptr to a's address */
	ptr = &a;
	printf("Address of variable 'a': %p\n",ptr); 
	//output:pointer 0022FEBB
	printf("Value of pointer 'ptr': %c\n",*ptr); 
	//output:character A

	return(0);
}

04 - Exploring pointer tools
C language pointer tools

-1. Operators
-2. Symbolic constants

1.C Pointer OPerators
-Unary * (pointer)
-Unary & (address-of)
-sizeof => returns the bytes the variable occupied in storage
2.C Symbolic constants
-NULL, a pointer not assigned to any specifit address
-size_t, byte count, number of byte in the buffer


01_02_1 01_02-examine1.c

#include <stdio.h>

int main()
{
	char a;

	/* initialize variables! */
	a = 'A';

	printf("Value of variable 'a': %c\n",a);
	//character:A
	printf("Address of variable 'a': %p\n",&a);
	//address:0060FEFF
	printf("Size of variable 'a': %lu\n",sizeof(a));
	//long unsigned integer:1

	return(0);
}

01_02-pexamine1.c

#include <stdio.h>

int main()
{
	char a;
	char *ptr; //指向字串的指標變數

	/* initialize variables! */
	a = 'A';
	ptr = &a;

	printf("Value of variable 'a': %c\n",*ptr);
	//character:A
	printf("Address of variable 'a': %p\n",ptr);
	//address:0060FEFB

	return(0);
}

05 - Using pointers as function arguments
01_03-scanf1.c

#include <stdio.h>

int main()
{
	int age;

	printf("Your age: ");
	/* the second argument is a memory location,
	   the address of variable 'age' */
	scanf("%d",&age);//注意此處可以用指標
	printf("You claim to be %d years old\n",age);

	return(0);
}

01_03-scanf2.c

#include <stdio.h>

int main()
{
	int age;
	int *aptr;

	/* must always initialize a pointer */
	aptr = &age; //aptr是個指向age的指標

	printf("Your age: ");
	/* as an address, the pointer is passed directly */
	scanf("%d",aptr);
	/* the asterisk operator is used to obtain the
	   value referenced by the pointer, the value
	   of variable 'age' */
	printf("You claim to be %d years old\n",*aptr);

	return(0);
}

01_03-set1.c

#include <stdio.h>

void set(int *x, int *y)
{
	*x = 100;
	*y = 200;
	//contents of the location are set
}

int main()
{
	int a,b;

	set(&a,&b); // 傳入指標變數
	printf("A = %d and B = %d\n",a,b);
	//a=100 b=200
	return(0);
}

01_03-set2.c

#include <stdio.h>

void set(int *x, int *y)
{
	*x = 100;
	*y = 200;
}

int main()
{
	int a,b;
	int *x,*y;

	/* assign the pointers to the variable's
	   addresses */
	x = &a;
	y = &b;

	/* send the addresses to the function via
	   the pointers */
	set(x,y); //傳入指標變數
	printf("A = %d and B = %d\n",a,b);
	//a,b可替代成*x,*y

	return(0);
}

06 - Working with function pointers
Functions 也有 datatype
01_04-fopen1.c

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;

	fp = fopen("01_04-fopen1.c","r");
	//fopen returns a pointer of filetype
	//returns address of file structure memory
	
	/* always test the pointer returned from a function */
	if( fp==NULL )
	{
		/* exit upon function failure */
		fprintf(stderr,"Unable to open file\n");
		exit(1);
	}
	puts("File opened!");
	/* close the file */
	fclose(fp);

	return(0);
}

01_04-integer1.c

//The address returned from a pointer function 
//matches the function's data type, 
//which is true for any type of function.

#include <stdio.h>
#include <stdlib.h>
//So here you see an integer pointer function iptr 指標函式
int *iptr(void)//integer pointer variable
{
	static int a = 53;

	return(&a);
	//It returns an address, 
	//the address of an integer, 
	//which must be stored in an integer pointer variable.
}

int main()
{
	int *x; //上述的integer pointer variable在此宣告

	x = iptr();
	if( x==NULL )
	{
		fprintf(stderr,"Memory error\n");
		exit(1);
	}
	printf("The address returned is %p\n",x);
	//%p=00402000
	printf("The value returned is %d\n",*x);
	//%d=53
	return(0);
}

//Perhaps the most common pointer function is malloc
//which allocates or sets aside a chunk of memory,
//returning the address in the pointer variable.
01_04-malloc1.c

#include <stdio.h>
#include <stdlib.h> //malloc要用到這個
//malloc datatype:void
//meaning that a void address is returned, 
//or an untyped chunk of memory is returned.
int main()
{
	void *chunk;

	chunk = malloc(1024);//1024 bytes to allocate
	/* always test pointer allocation */
	if( chunk==NULL )
	{
		puts("Memory allocation failed!");
	}
	else
	{
		printf("1024 bytes allocated at %p\n",chunk);
		//%p=00150D80
		free(chunk);//memory chunch is freed
	}

	return(0);
}

//always examine 指標是否為NULL
//NULL 不是0 一但指標是NULL 就是failed

07 - Challenge Obtain an address
08 - Solution Obtain an address

01_06-Solution-address

#include <stdio.h>

int main()
{
	char a,*x;
	int b,*y;

	printf("Address of 'a': %p\n",&a);
	//0060FEF7
	printf("Address of 'b': %p\n",&b);
	//0060FEF0
	x = &a;
	y = &b;
	printf("Address of 'a': %p\n",x);
	//0060FEF7
	printf("Address of 'b': %p\n",y);
	//0060FEF0

	return(0);
}

09 - Comparing arrays and pointers
02_01-array1.c
#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x;
	//一般的矩陣列印出值
	for( x=0; x<5; x++ )
		printf("%d\n",a[x]);

	return(0);
}
02_01-array2.c

#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x;

	for( x=0; x<5; x++ )
		printf("%p\n",&a[x]);
	//印出每一個的指標 每個都間隔4bytes(integer)
	// 0060FEE8 0060FEEC 0060FEF0 0060F4F4 0060FEF8

	return(0);
}
02_01-pointer2.c
#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x,*p;

	p = a;
	for( x=0; x<5; x++ )
	{
		printf("%p\n",p);//印出每一個的指標 每個都間隔4bytes(integer)
		p++;//若沒有p++ 則每次出來都是矩陣的啟始位置 0060FEE4
		//p++輸出 0060FEE4 0060FEE8 0060FEEC 0060FEF0 0060FEF4
	}

	return(0);
}
02_01-pointer3.c
#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x,*p;

	p = a;
	for( x=0; x<5; x++ )
	{
		printf("%d\n",*p);//11 22 33 44 55
		p++;
	}

	return(0);
}
02_01-pointer4.c
#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x,*p;

	p = a;
	for( x=0; x<5; x++ )
	{
		printf("%d\n", *(p+x) );//11 22 33 44 55
	}

	return(0);
}

/*筆記*/
For array a[] and pointer *p

- To assign p to the base of the array: p=a
- To assign p to array element n : p=&a[n]
- To access element n's address: p+n
- To access element n's value: *(p+n)

02_01-pointerbonus1.c
#include <stdio.h>

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int x,*p;

	/* initialize the pointer to the array
	   without the & (address-of) operator */
	p = a;
	/* loop throuh all five elements */
	for( x=0; x<5; x++ )
	{
		/* &a[x] is the address of element 'x' in array 'a' */
		/* p+x is the address of element offset 'x' from
		   base 'p' */
		printf("Address of element %d: %p = %p\n",
				x,
				&a[x],
				p+x
			  );
		/* a[x] is the value of element 'x' in array 'a' */
		/* *(p+x) is the value of element offset 'x' relative
		   to the base address stored in variable 'p' */
		printf("Value of element %d: %d = %d\n",
				x,
				a[x],
				*(p+x)
			  );
	}

	return(0);
}
/* Pointer notation isn't a substitute for array notation and
   vice-versa. Each has a different purpose and identity in
   the C language, though it's possible to represent array
   notation by using pointers, as shown in this example
   and in the movie. */

10 - Allocating storage   

Memory Allocation
- Array work for many types of storage
- To dynamically allocate storage, use a pointer
(利用pointer來動態分配記憶體)
- The pointer holds the buffer's address

Malloc()Function 動態分配記憶體
- Prototyped in stdlib.h
- Void *malloc(size_t size);
- Argument: size, buffer size in bytes (size_t values)
- Success: Buffer's address (pointer) is returned
- Filed: Upon failure, NULL is returned
- Always test for the NULL

02_02-malloc1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *storage;

	storage = malloc(16);
	if( storage==NULL )
	{
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	else
	{
		puts("Memory allocated");
	}

	return(0);
}

02_02-malloc2.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *storage; //char pointer

	storage = (char *)malloc( sizeof(char) * 16 );
	if( storage==NULL )
	{
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	else
	{
		puts("Memory allocated");
	}

	return(0);
}
02_02-malloc3.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;
	int size = 5; //儲存五個整數

	storage = (int *)malloc( sizeof(int) * size);
	if( storage==NULL )
	{
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	else
	{
		printf("Memory allocated for %d integers\n",size);
		//Memory allocated for 5 integers
	}

	return(0);
}
02_02-malloc4.c 字串指標

#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* 15 characters are required for input */
	char *input;

	input = (char *)malloc( sizeof(char) * 15 + 1 );
	//指派字串需要注意
	//因為字串尾端是null character \0 故要加1
	if( input==NULL )
	{
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	else
	{
		puts("15 characters are available for input");
	}

	return(0);
}

11 - Exploring allocation functions

有四種 Memory Allocation Functions
- malloc() allocates uninitialized storage
- calloc() allocate and initializes storage
0 for integer, null characters for char
- realloc() dynamically resizeds an existing buffer
Contents of the old buffer are copied to the new (as much as possible)
An existing buffer can be resized by specifying its address both as an argument and as the return value
realloc() doesn't initialize the added storage
- free() use free() on an allocated buffer to recover memory or storage
After using free(), set a pointer's value to NULL
不需要每次程式結束都用free 因為他會自動free

02_03-malloc1.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;
	int x;

	storage = (int *)malloc( sizeof(int) * 5);
	if( storage==NULL )
	{
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	puts("Memory allocated");
	/* the memory is allocated, but uninitialized
	   values output are garbage */
	for( x=0; x<5; x++ )
		printf("%d\n",*(storage+x) );
	//BAD 因為沒初始值 出來會變成一堆垃圾
	//印出殘留在記憶體裡的值

	return(0);
}
02_03-calloc1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;
	int x;

	/* the calloc() function allocates and
	   initializes storage to all zeros or
	   all null characters in a char buffer */
	storage = (int *)calloc( 5, sizeof(int) );
	//quantity:5 integer sized chunks, sizeof(int)=4
	if( storage==NULL )
	{
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	puts("Memory allocated");
	/* the pointer is allocated, and the storage
	   locations are initialized to zero */
	for( x=0; x<5; x++ )
		printf("%d\n",*(storage+x) );
	//BAD 因為沒初始值 出來會變成一堆0
	return(0);
}

02_03-realloc1.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;
	int x;

	/* use malloc to set the buffer size to
	   store five integers */
	storage = (int *)malloc( sizeof(int) * 5);
	if( storage==NULL )
	{
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	puts("Memory allocated");
	/* initialize and output the values */
	for( x=0; x<5; x++ )
	{
		*(storage+x) = (x+1) * 11;
		printf("%d\n",*(storage+x) );
	}

	/* now increase the buffer size by two
	   integer values */
	storage = (int *)realloc(storage, sizeof(int) * 7 );
	if( storage==NULL )
	{
		fprintf(stderr,"Reallocation failed\n");
		exit(1);
	}
	puts("Buffer re-sized");
	/* add the final two values */
	*(storage+5) = 66; 
	*(storage+6) = 77; 
	/* output the results */
	for( x=0; x<7; x++ )
	{
		printf("%d\n",*(storage+x) );
		//11 22 33 44 55 66 77
	}

	return(0);
}
02_03-free1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *storage;
	int x;

	/* the malloc() function allocates the pointer */
	storage = (int *)malloc( sizeof(int) * 5);
	if( storage==NULL )
	{
		fprintf(stderr,"Allocation failed\n");
		exit(1);
	}
	puts("Memory allocated");
	/* the pointer is allocated, but the storage
	   locations haven't been initialized */
	for( x=0; x<5; x++ )
		printf("%d\n",*(storage+x) );

	/* release the allocated memory */
	free(storage); //free the storage
	storage = NULL;//指標指向空 代表不使用這指標了
	puts("Memory freed");
	/* it's unnecessary to free() storage before
	   a program quits, but if you plan on re-
	   using the pointer, or it's allocated within
	   a function, do free it and assign the
	   pointer to the NULL symbolic constant,
	   as shown here */

	return(0);
}

12 - Accessing the buffer

1. 一個pointer可以walk through the data
2. 兩個pointers可以manage a base and an offset

Pointer Math
- Mathematically manipulating a pointer alters its address by the data size
- p++; //Adds one integer-size chunk to the address
- After incrementing, p references the next integer in memory

- character pointer c
c+1//指向the second character in the buffer

- double pointer d
d+4//指向the fifth value in the buffer

02_04-walk1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p,x;

	/* allocate storage */
	p = (int *)malloc( sizeof(int) * 10 );
	if( p==NULL )
	{
		fprintf(stderr,"Allocation failure\n");
		exit(1);
	}

	/* fill storage */
	for( x=0; x<10; x++ )
	{
		*p = x * 100;
		/* reference the next integer location */
		p++;
	}
	puts("Memory allocated and filled");

	return(0);
}
02_04-walk2
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *base,*p,x;
	//比上面多一個base指標 永遠指向初始

	/* allocate storage */
	base = (int *)malloc( sizeof(int) * 10 );
	if( base==NULL )
	{
		fprintf(stderr,"Allocation failure\n");
		exit(1);
	}

	/* retain the base */
	p = base;
	/* fill storage */
	for( x=0; x<10; x++ )
	{
		*p = x * 100;
		/* reference the next integer location */
		p++;
	}
	puts("Memory allocated and filled");

	/* output the buffer's contents */
	p = base;//跑掉的p指標又指回初始的指標
	for( x=0; x<10; x++ )
	{
		printf("%d\n",*p);
		p++;
	}
	//100 200 300 400 ... 900
	return(0);
}


02_04-base-offset1.c
本例是上一例的另一種寫法
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p,x;
	//如果不想讓指標p跑掉 可以用p+x 則p永遠指向初值

	/* allocate storage */
	p = (int *)malloc( sizeof(int) * 10 );
	if( p==NULL )
	{
		fprintf(stderr,"Allocation failure\n");
		exit(1);
	}

	/* fill storage */
	for( x=0; x<10; x++ )
	{
		/* use offset; retain p */
		*(p+x) = x * 100;
	}
	puts("Memory allocated and filled");

	/* output the buffer's contents */
	for( x=0; x<10; x++ )
	{
		printf("%d\n",*(p+x) );
	}

	return(0);
}
02_04-array1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[10],x;

	/* fill storage */
	for( x=0; x<10; x++ )
	{
		a[x] = x * 100;
		/* a[x] ~ *(p+x) */
	}

	/* output the buffer's contents */
	for( x=0; x<10; x++ )
	{
		printf("%d\n",a[x] );
		/* a[x] ~ *(p+x) */
	}

	return(0);
}

注意超出記憶體 Avoiding Buffer Overruns
It's possible to reference a value beyond allocated memory

13 - Working with pointers in structures

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//the structure itself isn't allocated as a pointer, dot notation is used to access its members even when the member is a pointer.

	struct person {
		char *name; //char 指標 name
		int *age; //int 指標 age
	} my; //結構變數my 因為不是指標 取出成員用*號
	char n[] = "Jennifer";

	/* allocate storage for the age integer */
	my.age = (int *)malloc( sizeof(int) * 1);
	if( my.age==NULL )
	{
		fprintf(stderr,"Allocation error\n");
		exit(1);
	}
	/* assign value; the asterisk is required, but the
	   standard dot operator is used */
	*my.age = 26;

	/* because 'n' is an array and 'my.name' is a pointer,
	   you can just copy the base address
	   again, the dot operator is used */
	my.name = n;

	/* output results
	   'my.name' is a character pointer and the
	   asterisk isn't required
	   the asterisk is required for 'my.age' */
	printf("%s is %d years old\n",
			my.name,
			*my.age
		  );
	//Jennifer is 26 years old

	return(0);
}
14 - Creating structure pointers

02_06-structptr1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct person {
		char name[32];
		int age;
	} president = {
		"George Washington",
		59
	};
	struct person *first;
	//如果結構變數是指標 取出成員要改成用->

	/* output regular structure */
	printf("%s is %d years old\n",
			president.name,
			president.age
		 );
	//president不是指標 用.呼叫成員
	
	/* assign structure pointer */
	first = &president;

	/* output pointer reference */
	//first是指標 用->呼叫成員
	printf("%s is %d years old\n",
			first->name,
			first->age
		 );

	return(0);
}

02_06-structptr2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct person {
		char name[32];
		int age;
	} *first;

	/* allocate the structure's memory */
	first = (struct person *)malloc( sizeof(struct person) * 1);
	if( first==NULL )
	{
		fprintf(stderr,"Unable to allocate storage\n");
		exit(1);
	}

	/* assign structure members */
	strcpy(first->name,"George Washington");
	printf("How old was %s? ",first->name);
	/* first->age is still an integer variable */
	scanf("%d",&first->age);

	/* output results */
	printf("%s was %d years old\n",
			first->name,
			first->age
		 );

	return(0);
}

02_06-structptr3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct person {
		char *name;
		int *age;
	} *first;

	//都是指標 每個一開始都要配記憶體
	/* allocate the structure's memory */
	first = (struct person *)malloc( sizeof(struct person) * 1);
	if( first==NULL )
	{
		fprintf(stderr,"Unable to allocate storage\n");
		exit(1);
	}
	/* allocate structure members */
	first->name = (char *)malloc( sizeof(char) * 32);
	first->age = (int *)malloc( sizeof(int) * 1);
	if( first->name==NULL || first->age==NULL )
	{
		fprintf(stderr,"Unable to allocate storage\n");
		exit(1);
	}

	/* assign structure members */
	strcpy(first->name,"George Washington");
	printf("How old was %s? ",first->name);
	/* first->age is still an integer variable */
	scanf("%d",first->age);

	/* output results */
	printf("%s was %d years old\n",
			first->name,
			*first->age
		 );

	return(0);
}

15 - Saving pointers and buffers

02_07-saveptr1.c

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *base,x;
	FILE *fp;

	/* allocate storage */
	base = (int *)malloc( sizeof(int) * 10 );
	//分配10個integer的空間
	if( base==NULL )
	{
		fprintf(stderr,"Allocation failure\n");
		exit(1);
	}

	/* fill storage */
	for( x=0; x<10; x++ )
	{
		*(base+x) = x * 100;
	}
	puts("Memory allocated and filled");

	/* open the file */
	fp = fopen("integers.dat","w");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to create file\n");
		exit(1);
	}

	/* save the buffer */
	fwrite(base,sizeof(int),10,fp);//pointer base
	//fp= file pointer
	puts("Data saved");

	/* close the file */
	fclose(fp);

	return(0);
}


02_07-readptr1.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *base,r,x;
	FILE *fp;

	/* allocate storage */
	base = (int *)malloc( sizeof(int) * 10 );
	if( base==NULL )
	{
		fprintf(stderr,"Allocation failure\n");
		exit(1);
	}

	/* open the file */
	fp = fopen("integers.dat","r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to read file\n");
		exit(1);
	}

	/* fill the buffer */
	r = fread(base,sizeof(int),10,fp);
	/* confirm the proper data is read */
	if( r!=10 )
	{
		fprintf(stderr,"File read error\n");
		exit(1);
	}
	puts("Data read");
	/* close the file */
	fclose(fp);

	/* output results */
	puts("Values:");
	for( x=0; x<10; x++ )
	{
		printf("%d\n",*(base+x) );
	}
	//100 200 300 ... 900
	return(0);
}

//sizeof裡面千萬不要放指標 是錯的寫法
02_07-saveptr2
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct human {
		char *name;
		int age;
	} *towrite;
	const char filename[] = "saved.dat";
	char *r;
	FILE *fp;

	/* allocate structure */
	towrite = (struct human *)malloc( sizeof(struct human) * 1);
	if( towrite==NULL )
	{
		fprintf(stderr,"Unable to allocate structure memory\n");
		exit(1);
	}
	/* now that structure is allocated, allocate storage
	   for the name pointer */
	towrite->name = (char *)malloc( sizeof(char) * 32);
	if( towrite->name==NULL )
	{
		fprintf(stderr,"Unable to allocate string memory\n");
		exit(1);
	}

	/* fill the towrite structure; prompt the user */
	printf("Enter your name: ");
	r = fgets(towrite->name,32,stdin);
	/* check for input error */
	if( r==NULL )
	{
		fprintf(stderr,"Input error\n");
		exit(1);
	}
	printf("How old are you: ");
	/* towrite->age is an integer, not a pointer, so
	   the ampersand is required */
	scanf("%d",&towrite->age);

	/* write the structure to a file */
	/* open the file */
	fp = fopen(filename,"w");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to create %s\n",filename);
		exit(1);
	}
	/* write the structure */
	fwrite(towrite,sizeof(struct human),1,fp);
	/* close the file */
	fclose(fp);
	printf("Data written to %s\n",filename);
	
	return(0);
}
02_07-saveptr1-final
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *base,x;
	FILE *fp;

	/* allocate storage */
	base = (int *)malloc( sizeof(int) * 10 );
	if( base==NULL )
	{
		fprintf(stderr,"Allocation failure\n");
		exit(1);
	}

	/* fill storage */
	for( x=0; x<10; x++ )
	{
		*(base+x) = x * 100;
	}
	puts("Memory allocated and filled");

	/* open the file */
	fp = fopen("integers.dat","w");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to create file\n");
		exit(1);
	}

	/* save the buffer */
	fwrite(base,sizeof(base),1,fp);
	puts("Data saved");

	/* close the file */
	fclose(fp);

	return(0);
}

//存檔時不要存pointer 記得要轉成array等數據

16 - Challenge Saving and reading a record
分成兩個程式
第一個程式:create 一個結構 fill with 資料 並存至檔案saved.dat
第二個程式:讀檔saved.dat fill結構 output structure資料
Structure: allocated as a pointer
有兩個成員: string name, integer age

   
17 - Solution Saving and reading a record


02_09-solution-write1

#include <stdio.h>
#include <stdlib.h>

int main()
{//因為你要存檔 所以structure裡面沒有pointer
	struct human {
		char name[32];
		int age;
	} *towrite;
	const char filename[] = "saved.dat";
	char *r;
	FILE *fp;

	/* allocate structure */
	towrite = (struct human *)malloc( sizeof(struct human) * 1);
	if( towrite==NULL )
	{
		fprintf(stderr,"Unable to allocate structure memory\n");
		exit(1);
	}

	/* fill the towrite structure; prompt the user */
	printf("Enter your name: ");
	r = fgets(towrite->name,32,stdin);
	/* check for input error */
	if( r==NULL )
	{
		fprintf(stderr,"Input error\n");
		exit(1);
	}
	printf("How old are you: ");
	/* towrite->age is an integer, not a pointer, so
	   the ampersand is required */
	scanf("%d",&towrite->age);

	/* write the structure to a file */
	/* open the file */
	fp = fopen(filename,"w");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to create %s\n",filename);
		exit(1);
	}
	/* write the structure */
	fwrite(towrite,sizeof(struct human),1,fp);
	/* close the file */
	fclose(fp);
	printf("Data written to %s\n",filename);
	
	return(0);
}


02_09-solution-read1

#include <stdio.h>
#include <stdlib.h>

int main()
{//structure要跟前面一樣
	struct human {
		char name[32];
		int age;
	} *toread;
	const char filename[] = "saved.dat";
	FILE *fp;

	/* allocate structure */
	toread = (struct human *)malloc( sizeof(struct human) * 1);
	if( toread==NULL )
	{
		fprintf(stderr,"Unable to allocate structure memory\n");
		exit(1);
	}

	/* read the structure into memory */
	/* open the file */
	fp = fopen(filename,"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to read from %s\n",filename);
		exit(1);
	}
	/* read in the structure */
	fread(toread,sizeof(struct human),1,fp);
	/* close the file */
	fclose(fp);

	/* output results */
	puts("Data read:");
	/* The 'name' member probably ends in a newline */
	printf("Name: %sAge: %d\n",
			toread->name,
			toread->age
		  );
	
	return(0);
}

18 - Understanding a linked list

Linked List:
A dynamic storage concoction
involving structures and pointers

- 就像database的record
- members describe data
- 其中一個structure 成員為pointer
- the pointer references the next structure in the list

A linked list structure
-First
-Current
-Next

For Each Structure Added
- New (Next) structure is allocated
- The structure's address is stored
in the preceding structure's linking member
- Structure is filled with data
- The new (next) structure's linking member is set to NULL

Linked List Advantages over and Array
- The linked list is dynamic
- Easily add structures (records) to the list
- Create links for complex data structures

19 - Implementing a linked list

03_02-linkedlist1.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

/* read standard input, discard newline */
char *input(void)
{
	static char buffer[SIZE];
	char *r;
	int x;

	/* initialize the buffer */
	buffer[0]='\0';

	/* gather input */
	r = fgets(buffer,SIZE,stdin);
	if( r==NULL )
	{
		fprintf(stderr,"Input error\n");
		exit(1);
	}
	
	/* remove the newline */
	for(x=0; x<SIZE; x++)
	{
		/* remove newline */
		if( buffer[x]=='\n' )
		{
			buffer[x]='\0';
			break;
		}
	}

	return(buffer);
}

int main()
{
	struct item {
		int id;
		char name[SIZE];
		float price;
		struct item *next;//A pointer to another structure
	};
	struct item *first,*current;
	char temp[SIZE];

	/* allocate initial structure */
	first = (struct item *)malloc( sizeof(struct item) * 1);
	if( first==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* the first structure is now the current structure */
	current = first;

	/* fill structure */
	current->id = 1;
	printf("Record %d Fruit: ",current->id);
	strcpy(current->name,input() );
	printf("Price: ");
	strcpy(temp,input() );
	current->price = strtof(temp,NULL);
	/* don't forget to initialize the pointer! */
	current->next = NULL;

	/* output the contents */
	printf("%d: %s for %.2f/pound\n",
			current->id,
			current->name,
			current->price
		  );

	return(0);
}

03_02-linkedlist2
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

/* define structure externally to ensure
   that it's available to all functions */
struct item {
	int id;
	char name[SIZE];
	float price;
	struct item *next;
};

/* read standard input, discard newline */
char *input(void)
{
	static char buffer[SIZE];
	char *r;
	int x;

	/* initialize the buffer */
	buffer[0]='\0';

	/* gather input */
	r = fgets(buffer,SIZE,stdin);
	if( r==NULL )
	{
		fprintf(stderr,"Input error\n");
		exit(1);
	}
	
	/* remove the newline */
	for(x=0; x<SIZE; x++)
	{
		/* remove newline */
		if( buffer[x]=='\n' )
		{
			buffer[x]='\0';
			break;
		}
	}

	return(buffer);
}

/* allocate a new structure */
struct item *allocate(void)
{
	struct item *p;

	p = (struct item *)malloc( sizeof(struct item) * 1);
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

/* fill the structure */
void fill(struct item *s, int i)
{
	char temp[SIZE];

	s->id = i;
	printf("Record %d Fruit: ",i);
	strcpy(s->name,input() );
	printf("Price: ");
	strcpy(temp,input() );
	s->price = strtof(temp,NULL);
	/* the 'next' member is filled in the main() function */
}

/* output the list */
void output(struct item *s)
{
	while( s!=NULL )
	{
		printf("%d: %s for %.2f/pound\n",
				s->id,
				s->name,
				s->price
			  );
		s = s->next;
	}
}

int main()
{
	struct item *first,*current;

	/* allocate initial structure */
	first = allocate();

	/* the base structure is now the current structure */
	current = first;

	/* fill structure */
	fill(current,1);
	/* cap the final structure */
	current->next = NULL;

	/* output the contents */
	output(first);

	return(0);
}
03_02-linkedlist3.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

/* define structure externally to ensure
   that it's available to all functions */
struct item {
	int id;
	char name[SIZE];
	float price;
	struct item *next;
};

/* read standard input, discard newline */
char *input(void)
{
	static char buffer[SIZE];
	char *r;
	int x;

	/* initialize the buffer */
	buffer[0]='\0';

	/* gather input */
	r = fgets(buffer,SIZE,stdin);
	if( r==NULL )
	{
		fprintf(stderr,"Input error\n");
		exit(1);
	}
	
	/* remove the newline */
	for(x=0; x<SIZE; x++)
	{
		/* remove newline */
		if( buffer[x]=='\n' )
		{
			buffer[x]='\0';
			break;
		}
	}

	return(buffer);
}

/* allocate a new structure */
struct item *allocate(void)
{
	struct item *p;

	p = (struct item *)malloc( sizeof(struct item) * 1);
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

/* fill the structure */
void fill(struct item *s, int i)
{
	char temp[SIZE];

	s->id = i;
	printf("Record %d Fruit: ",i);
	strcpy(s->name,input() );
	printf("Price: ");
	strcpy(temp,input() );
	s->price = strtof(temp,NULL);
	/* the 'next' member is filled in the main() function */
}

/* output the list */
void output(struct item *s)
{
	while( s!=NULL )
	{
		printf("%d: %s for %.2f/pound\n",
				s->id,
				s->name,
				s->price
			  );
		s = s->next;
	}
}

int main()
{
	struct item *first,*current;
	int x;

	/* this linked list has five items */
	for(x=0; x<5; x++)
	{
		/* allocate initial structure */
		if( x==0 )
		{
			first = allocate();
			current = first;
		}
		else
		{
			/* set the next structure link */
			current->next = allocate();
			/* make the next structure the
			   current structure */
			current = current->next;
		}
		fill(current,x+1);
	}
	/* cap the final structure */
	current->next = NULL;

	/* output the list */
	output(first);

	return(0);
}
 
20 - Removing structures
03_03-remove1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

/* define structure externally to ensure
   that it's available to all functions */
struct item {
	int id;
	char name[SIZE];
	float price;
	struct item *next;
};

/* allocate a new structure */
struct item *allocate(void)
{
	struct item *p;

	p = (struct item *)malloc( sizeof(struct item) * 1);
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

/* fill the structure */
void fill(struct item *s, int i)
{
	char *fruit[] = { "apples", "bananas", "grapes", "strawberries", "watermelon" };
	float prices[] = { 1.20, 2.58, 2.09, 2.40, 0.51 };

	s->id = i;
	strcpy(s->name,fruit[i]);
	s->price = prices[i];
}

/* output the list */
void output(struct item *s)
{
	while( s!=NULL )
	{
		printf("%d: %s for $%.2f/pound\n",
				s->id+1,
				s->name,
				s->price
			  );
		s = s->next;
	}
}

int main()
{
	struct item *first,*current;
	int x;

	/* build a linked list with 5 items */
	for(x=0; x<5; x++)
	{
		/* allocate initial structure */
		if( x==0 )
		{
			first = allocate();
			current = first;
		}
		else
		{
			/* set the next structure link */
			current->next = allocate();
			/* make the next structure the
			   current structure */
			current = current->next;
		}
		fill(current,x);
	}
	/* cap the final structure */
	current->next = NULL;

	/* output the list */
	puts("Original List:");
	output(first);

	/* remove the fourth structure from the list */
	puts("Removing the fourth record...");
	current = first;
	/* locate the third structure to remove
	   the fourth */
	while(current->id != 2)
	{
		current = current->next;
		/* always test with pointers! */
		if( current==NULL )
		{
			fprintf(stderr,"Structure out of bounds\n");
			exit(1);
		}
	}
	/* refocus the next pointer to reference
	   structure 4 instead of 3 */
	current->next = (current->next)->next;

	/* output the updated list */
	puts("Updated List:");
	output(first);

	return(0);
}

03_03-remove2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

/* define structure externally to ensure
   that it's available to all functions */
struct item {
	int id;
	char name[SIZE];
	float price;
	struct item *next;
};

/* allocate a new structure */
struct item *allocate(void)
{
	struct item *p;

	p = (struct item *)malloc( sizeof(struct item) * 1);
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

/* fill the structure */
void fill(struct item *s, int i)
{
	char *fruit[] = { "apples", "bananas", "grapes", "strawberries", "watermelon" };
	float prices[] = { 1.20, 2.58, 2.09, 2.40, 0.51 };

	s->id = i;
	strcpy(s->name,fruit[i]);
	s->price = prices[i];
}

/* output the list */
void output(struct item *s)
{
	while( s!=NULL )
	{
		printf("%d: %s for $%.2f/pound\n",
				s->id+1,
				s->name,
				s->price
			  );
		s = s->next;
	}
}

int main()
{
	struct item *first,*current,*temp;
	int x;

	/* build a linked list with 5 items */
	for(x=0; x<5; x++)
	{
		/* allocate initial structure */
		if( x==0 )
		{
			first = allocate();
			current = first;
		}
		else
		{
			/* set the next structure link */
			current->next = allocate();
			/* make the next structure the
			   current structure */
			current = current->next;
		}
		fill(current,x);
	}
	/* cap the final structure */
	current->next = NULL;

	/* output the list */
	output(first);

	/* remove the fourth structure from the list */
	puts("Removing the fourth record:");
	current = first;
	/* locate the third structure to remove
	   the fourth */
	while(current->id != 2)
	{
		current = current->next;
		/* always test with pointers! */
		if( current==NULL )
		{
			fprintf(stderr,"Structure out of bounds\n");
			exit(1);
		}
	}
	/* save the current->next pointer */
	temp = current->next;
	/* refocus the next pointer to reference
	   structure 4 instead of 3 */
	current->next = temp->next;
	/* free the storage */
	free(temp);

	/* output the updated list */
	output(first);

	return(0);
}
03_03-remove3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

/* define structure externally to ensure
   that it's available to all functions */
struct item {
	int id;
	char name[SIZE];
	float price;
	struct item *next;
};

/* allocate a new structure */
struct item *allocate(void)
{
	struct item *p;

	p = (struct item *)malloc( sizeof(struct item) * 1);
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

/* fill the structure */
void fill(struct item *s, int i)
{
	char *fruit[] = { "apples", "bananas", "grapes", "strawberries", "watermelon" };
	float prices[] = { 1.20, 2.58, 2.09, 2.40, 0.51 };

	s->id = i;
	strcpy(s->name,fruit[i]);
	s->price = prices[i];
}

/* output the list */
void output(struct item *s)
{
	while( s!=NULL )
	{
		printf("%d: %s for $%.2f/pound\n",
				s->id+1,
				s->name,
				s->price
			  );
		s = s->next;
	}
}

int main()
{
	struct item *first,*current,*temp;
	int x;

	/* build a linked list with 5 items */
	for(x=0; x<5; x++)
	{
		/* allocate initial structure */
		if( x==0 )
		{
			first = allocate();
			current = first;
		}
		else
		{
			/* set the next structure link */
			current->next = allocate();
			/* make the next structure the
			   current structure */
			current = current->next;
		}
		fill(current,x);
	}
	/* cap the final structure */
	current->next = NULL;

	/* output the list */
	output(first);

	/* remove the first structure from the list */
	puts("Removing the first record:");
	/* save the first record */
	temp = first;
	/* reset the second record as the first */
	first = first->next;
	/* free the storage */
	free(temp);

	/* output the updated list */
	output(first);

	return(0);
}

21 - Adding structures

03_04-insert1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

/* define structure externally to ensure
   that it's available to all functions */
struct item {
	int id;
	char name[SIZE];
	float price;
	struct item *next;
};

/* allocate a new structure */
struct item *allocate(void)
{
	struct item *p;

	p = (struct item *)malloc( sizeof(struct item) * 1);
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

/* fill the structure */
void fill(struct item *s, int i)
{
	char *fruit[] = { "apples", "bananas", "grapes", "strawberries", "watermelon" };
	float prices[] = { 1.20, 2.58, 2.09, 2.40, 0.51 };

	s->id = i;
	strcpy(s->name,fruit[i]);
	s->price = prices[i];
}

/* output the list */
void output(struct item *s)
{
	while( s!=NULL )
	{
		printf("%d: %s for $%.2f/pound\n",
				s->id+1,
				s->name,
				s->price
			  );
		s = s->next;
	}
}

int main()
{
	struct item *first,*current,*temp;
	int x;

	/* build a linked list with 5 items */
	for(x=0; x<5; x++)
	{
		/* allocate initial structure */
		if( x==0 )
		{
			first = allocate();
			current = first;
		}
		else
		{
			/* set the next structure link */
			current->next = allocate();
			/* make the next structure the
			   current structure */
			current = current->next;
		}
		fill(current,x);
	}
	/* cap the final structure */
	current->next = NULL; 

	/* output the list */
	output(first);//a new structure is inserted

	/* insert a new structure after the 2nd structure */
	puts("Inserting a new structure...");

	current = first;
	/* locate the 2nd structure */
	while(current->id!=1)
	{
		current = current->next;
		if( current==NULL )
		{
			fprintf(stderr,"Structure out of bounds\n");
			exit(1);
		}
	}

	/* allocate the new structure */
	temp = allocate();

	/* fill the new structure */
	temp->id = 5;
	strcpy(temp->name,"apricots");
	temp->price = 1.36;
	/* reference the following structure */
	temp->next = current->next;
	/* update the current structure */
	current->next = temp;

	/* output the updated list */
	output(first);

	return(0);
}

03_04-insert2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

/* define structure externally to ensure
   that it's available to all functions */
struct item {
	int id;
	char name[SIZE];
	float price;
	struct item *next;
};

/* allocate a new structure */
struct item *allocate(void)
{
	struct item *p;

	p = (struct item *)malloc( sizeof(struct item) * 1);
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

/* fill the structure */
void fill(struct item *s, int i)
{
	char *fruit[] = { "apples", "bananas", "grapes", "strawberries", "watermelon" };
	float prices[] = { 1.20, 2.58, 2.09, 2.40, 0.51 };

	s->id = i;
	strcpy(s->name,fruit[i]);
	s->price = prices[i];
}

/* output the list */
void output(struct item *s)
{
	while( s!=NULL )
	{
		printf("%d: %s for $%.2f/pound\n",
				s->id+1,
				s->name,
				s->price
			  );
		s = s->next;
	}
}

int main()
{
	struct item *first,*current,*temp;
	int x;

	/* build a linked list with 5 items */
	for(x=0; x<5; x++)
	{
		/* allocate initial structure */
		if( x==0 )
		{
			first = allocate();
			current = first;
		}
		else
		{
			/* set the next structure link */
			current->next = allocate();
			/* make the next structure the
			   current structure */
			current = current->next;
		}
		fill(current,x);
	}
	/* cap the final structure */
	current->next = NULL;

	/* output the list */
	output(first);

	/* add a structure at the start of the list */
	puts("Adding a new structure...");

	/* allocate the new structure */
	temp = allocate();

	/* fill the new structure */
	temp->id = 5;
	strcpy(temp->name,"apricots");
	temp->price = 1.36;
	/* reset the start of the list */
	temp->next = first;
	/* reset the first pointer */
	first = temp;

	/* output the updated list */
	output(first);

	return(0);
}

22 - Creating a double-linked list

//Foward pointer+backward pointer在結構間前進後退
//所以structure裡面有兩個pointer : previous/next

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

/* define structure externally to ensure
   that it's available to all functions */
struct item {
	int id;
	char name[SIZE];
	float price;
	struct item *next;
	struct item *previous;
};

/* allocate a new structure */
struct item *allocate(void)
{
	struct item *p;

	p = (struct item *)malloc( sizeof(struct item) * 1);
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

/* fill the structure */
void fill(struct item *s, int i)
{
	char *fruit[] = { "apples", "bananas", "grapes", "strawberries", "watermelon" };
	float prices[] = { 1.20, 2.58, 2.09, 2.40, 0.51 };

	s->id = i;
	strcpy(s->name,fruit[i]);
	s->price = prices[i];
}

/* output the list forward */
void output_forward(struct item *s)
{
	while( s!=NULL )
	{
		printf("%d: %s for $%.2f/pound\n",
				s->id+1,
				s->name,
				s->price
			  );
		s = s->next;
	}
}

/* output the list backward */
void output_backward(struct item *s)
{
	while( s!=NULL )
	{
		printf("%d: %s for $%.2f/pound\n",
				s->id+1,
				s->name,
				s->price
			  );
		s = s->previous;
	}
}

int main()
{
	struct item *first,*last,*current,*temp;
	int x;

	/* build a linked list with 5 items */
	for(x=0; x<5; x++)
	{
		/* allocate initial structure */
		if( x==0 )
		{
			first = allocate();
			current = first;
			fill(current,x);
			current->previous = NULL;
		}
		else
		{
			/* set the next structure link */
			current->next = allocate();
			/* save the current structure */
			temp = current;
			/* make the next structure the
			   current structure */
			current = current->next;
			fill(current,x);
			current->previous = temp;
		}
	}
	/* cap the final structure */
	current->next = NULL;
	/* set the last pointer */
	last = current;

	/* output the list forward*/
	puts("Forward:");
	output_forward(first);

	/* output the list backward */
	puts("Backward:");
	output_backward(last);

	return(0);
}


23 - Saving a linked list

03_06-llsave1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

/* define structure externally to ensure
   that it's available to all functions */
struct item {
	int id;
	char name[SIZE];
	float price;
	struct item *next;
};

/* allocate a new structure */
struct item *allocate(void)
{
	struct item *p;

	p = (struct item *)malloc( sizeof(struct item) * 1);
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

/* fill the structure */
void fill(struct item *s, int i)
{
	char *fruit[] = { "apples", "bananas", "grapes", "strawberries", "watermelon" };
	float prices[] = { 1.20, 2.58, 2.09, 2.40, 0.51 };

	s->id = i;
	strcpy(s->name,fruit[i]);
	s->price = prices[i];
}

/* output the list */
void output(struct item *s)
{
	while( s!=NULL )
	{
		printf("%d: %s for $%.2f/pound\n",
				s->id+1,
				s->name,
				s->price
			  );
		s = s->next;
	}
}

int main()
{
	struct item *first,*current;
	int x;
	FILE *fp;

	for(x=0; x<5; x++)
	{
		if( x==0 )
		{
			first = allocate();
			current = first;
		}
		else
		{
			current->next = allocate();
			current = current->next;
		}
		fill(current,x);
	}
	current->next = NULL;

	output(first);

	/* save the data */
	printf("Saving...");
	fp = fopen("lldata.dat","w");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to create file\n");
		exit(1);
	}

	/* write the five structures */
	fwrite(first,sizeof(struct item),5,fp);

	/* close the file */
	fclose(fp);
	puts("saved!");

	return(0);
}
03_06-llread1
#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

/* define structure externally to ensure
   that it's available to all functions */
struct item {
	int id;
	char name[SIZE];
	float price;
	struct item *next;
};

/* allocate a new structure */
struct item *allocate(void)
{
	struct item *p;

	p = (struct item *)malloc( sizeof(struct item) * 1);
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

/* output the list */
void output(struct item *s)
{
	while( s!=NULL )
	{
		printf("%d: %s for $%.2f/pound\n",
				s->id+1,
				s->name,
				s->price
			  );
		s = s->next;
	}
}

int main()
{
	struct item *first,*current;
	int x;
	FILE *fp;

	/* open the file */
	puts("Reading data...");
	fp = fopen("lldata.dat","r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to open file\n");
		exit(1);
	}

	/* the list has five items */
	for(x=0; x<5; x++)
	{
		/* allocate initial structure */
		if( x==0 )
		{
			first = allocate();
			current = first;
		}
		else
		{
			current->next = allocate();
			/* update the pointer member,
			   discarding the saved info */
			current = current->next;
		}
		/* use fread to fill the structure */
		fread(current,sizeof(struct item),1,fp);
		//read one structure at a time
	}
	/* cap the final structure */
	current->next = NULL;

	/* close the file */
	fclose(fp);

	/* output the list */
	output(first);

	return(0);
}
//上述可能會報錯 因為fwrite假設是連續的空間 但未必是

03_06-llsave2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

/* define structure externally to ensure
   that it's available to all functions */
struct item {
	int id;
	char name[SIZE];
	float price;
	struct item *next;
};

/* allocate a new structure */
struct item *allocate(void)
{
	struct item *p;

	p = (struct item *)malloc( sizeof(struct item) * 1);
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

/* fill the structure */
void fill(struct item *s, int i)
{
	char *fruit[] = { "apples", "bananas", "grapes", "strawberries", "watermelon" };
	float prices[] = { 1.20, 2.58, 2.09, 2.40, 0.51 };

	s->id = i;
	strcpy(s->name,fruit[i]);
	s->price = prices[i];
}

/* output the list */
void output(struct item *s)
{
	while( s!=NULL )
	{
		printf("%d: %s for $%.2f/pound\n",
				s->id+1,
				s->name,
				s->price
			  );
		s = s->next;
	}
}

int main()
{
	struct item *first,*current;
	int x;
	FILE *fp;

	for(x=0; x<5; x++)
	{
		if( x==0 )
		{
			first = allocate();
			current = first;
		}
		else
		{
			current->next = allocate();
			current = current->next;
		}
		fill(current,x);
	}
	current->next = NULL;

	output(first);

	/* save the data */
	printf("Saving...");
	fp = fopen("lldata.dat","w");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to create file\n");
		exit(1);
	}

	/* second write the five structures */
	current = first;
	while( current!=NULL )
	{
		fwrite(current,sizeof(struct item),1,fp);
		current = current->next;
	}

	/* close the file */
	fclose(fp);
	puts("saved!");

	return(0);
}

24 - Challenge Manage a linked list


03_07-challenge1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16
enum { FALSE, TRUE };
struct family {
	char name[SIZE];
	char relationship[SIZE];
	int age;
	struct family *next;
};

/* read standard input, discard newline */
char *input(void)
{
	static char buffer[SIZE];
	char *r;
	int x;

	/* initialize the buffer */
	buffer[0]='\0';

	/* gather input */
	r = fgets(buffer,SIZE,stdin);
	if( r==NULL )
	{
		fprintf(stderr,"Input error\n");
		exit(1);
	}
	
	/* remove the newline */
	for(x=0; x<SIZE; x++)
	{
		/* remove newline */
		if( buffer[x]=='\n' )
		{
			buffer[x]='\0';
			break;
		}
	}

	return(buffer);
}

int main()
{
	struct family *first,*current;
	int done;
	char command[SIZE];

	/* initialize first record to NULL */
	first = NULL;

	/* main menu and input loop */
	done = FALSE;
	puts("Family Database");
	while(!done)
	{
		/* initialize the current pointer to
		   the start of the list */
		current = first;
		/* output menu */
		puts("Menu:");
		puts("A - Add record");
		puts("D - Delete record");
		puts("L - List all records");
		puts("O - Open");
		puts("S - Save");
		puts("Q - Quit");
		printf("Choice: ");
		/* read input */
		strcpy(command,input() );
		/* process selection */
		switch(command[0])
		{
			/* add a record */
			case 'A':
			case 'a':
				break;
			/* delete a record */
			case 'D':
			case 'd':
				break;
			/* list all records */
			case 'L':
			case 'l':
				break;
			/* open/retrieve existing records */
			case 'O':
			case 'o':
				break;
			/* save all records */
			case 'S':
			case 's':
				break;
			/* quit the program */
			case 'Q':
			case 'q':
				done = TRUE;
				puts("Bye!");
				break;
			/* something weird typed */
			default:
				puts("Unrecognized command");
		}
	}

	return(0);
}


25 - Solution Manage a linked list
03_08-solution1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16
enum { FALSE, TRUE };
struct family {
	char name[SIZE];
	char relationship[SIZE];
	int age;
	struct family *next;
};
char filename[] = "family.dat";

/* read standard input, discard newline */
char *input(void)
{
	static char buffer[SIZE];
	char *r;
	int x;

	/* initialize the buffer */
	buffer[0]='\0';

	/* gather input */
	r = fgets(buffer,SIZE,stdin);
	if( r==NULL )
	{
		fprintf(stderr,"Input error\n");
		exit(1);
	}
	
	/* remove the newline */
	for(x=0; x<SIZE; x++)
	{
		/* remove newline */
		if( buffer[x]=='\n' )
		{
			buffer[x]='\0';
			break;
		}
	}

	return(buffer);
}

/* allocate a new structure */
struct family *allocate(void)
{
	struct family *p;

	p = (struct family *)malloc( sizeof(struct family) * 1);
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	return(p);
}

/* fill the structure */
void fill(struct family *s)
{
	char temp[SIZE];

	printf("Name: ");
	strcpy(s->name,input() );
	printf("Relationship: ");
	strcpy(s->relationship,input() );
	printf("Age: ");
	strcpy(temp,input() );
	s->age = strtod(temp,NULL);
	putchar('\n');
}

/* output the list */
int output(struct family *s)
{
	int count = 0;

	/* check for empty list */
	if( s==NULL )
	{
		puts("List is empty");
	}
	/* output all records */
	else
	{
		while( s!=NULL )
		{
			printf("%d: %s, your %s, is %d years old\n",
					count+1,
					s->name,
					s->relationship,
					s->age
				  );
			s = s->next;
			count++;
		}
	}
	putchar('\n');

	return(count);
}

/* save the linked list */
void save(struct family *s)
{
	FILE *fp;
	int records,x;

	/* confirm that the list isn't empty */
	if( s==NULL )
	{
		puts("List is empty\n");
		return;
	}

	/* count the number of records */
	records = output(s);
	printf("%d records to save...",records);
	
	/* open the file */
	fp = fopen(filename,"w");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to create %s\n\n",filename);
		/* don't quit on this error */
		return;
	}

	/* save all the records */
	for( x=0; x<records; x++ )
	{
		fwrite(s, sizeof(struct family), 1, fp);
		/* okay to change s here */
		s = s->next;
	}
	printf("%d written...",records);

	/* close the file */
	fclose(fp);

	puts("done!\n");
}

/* read the linked list from a file */
void open(struct family *s)
{
	FILE *fp;
	int records;

	/* open the file */
	fp = fopen(filename,"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to read from %s\n\n",filename);
		/* don't quit on this error */
		return;
	}
	printf("Opening file %s...",filename);

	/* retrieve the records */
	records = 1;
	/* allocate the first structure */
	while(1)
	{
		fread(s, sizeof(struct family), 1, fp);
		/* the NULL pointer is saved */
		if( s->next==NULL )
			break;
		s->next = allocate();
		s = s->next;
		records++;
	}
	printf("%d records read...",records);

	/* close the file */
	fclose(fp);

	puts("done!\n");

}

int main()
{
	struct family *first,*current,*temp;
	int done,r,record;
	char command[SIZE];

	/* initialize first record to NULL */
	first = NULL;

	/* main menu and input loop */
	done = FALSE;
	puts("Family Database");
	while(!done)
	{
		/* initialize the current pointer to
		   the start of the list */
		current = first;
		/* output menu */
		puts("Menu:");
		puts("A - Add record");
		puts("D - Delete record");
		puts("L - List all records");
		puts("O - Open");
		puts("S - Save");
		puts("Q - Quit");
		printf("Choice: ");
		/* read input */
		strcpy(command,input() );
		/* process selection */
		switch(command[0])
		{
			/* add a record */
			case 'A':
			case 'a':
				/* check to see if first record initialized */
				if( first==NULL )
				{
					current = allocate();
					first = current;
					fill(current);
				}
				else
				{
					while(current->next)
						current = current->next;
					current->next = allocate();
					current = current->next;
					fill(current);
				}
				current->next = NULL;
				break;
			/* delete a record */
			case 'D':
			case 'd':
				if( first==NULL )
				{
					puts("Nothing to delete\n");
					break;
				}
				else
				{
					/* output the list */
					r = output(first);

					/* prompt */
					printf("Remove record 1 to %d? ",r);
					record = strtod(input(), NULL);
					if( record<1 || record>r )
					{
						puts("Value out of range\n");
						break;
					}
					printf("Removing record %d...",record);
					/* test for first record */
					if( record==1 )
					{
						/* Check to see if first is the only record */
						if( first->next==NULL )
						{
							free(first);
							first = NULL;
						}
						else
						{
							temp = first;
							first = first->next;
							free(temp);
						}
						puts("Done!\n");
						break;
					}
					/* record to delete isn't the first record */
					/* visit the previous record */
					while(record-2)
					{
						current=current->next;
						record--;
					}
					/* save the next record */
					temp = current->next;
					/* reset the current record pointer */
					current->next = temp->next;
					/* free the removed structure */
					free(temp);
					puts("Deleted\n");
				}
				break;
			/* list all records */
			case 'L':
			case 'l':
				output(first);
				break;
			/* open/retrieve existing records */
			case 'O':
			case 'o':
				first = allocate();
				open(first);
				break;
			/* save all records */
			case 'S':
			case 's':
				save(first);
				break;
			/* quit the program */
			case 'Q':
			case 'q':
				done = TRUE;
				puts("Bye!");
				break;
			/* something weird typed */
			default:
				puts("Unrecognized command");
		}
	}

	return(0);
}

26 - Understanding pointers to pointers

04_01-main1.c
#include <stdio.h>

int main( int argc, char *argv[] )
//char *argv[] 是 array of pointers
{
	int x;

	for(x=0; x<argc; x++)
		printf("%s\n",argv[x]);

	return(0);
}

04_01-main2

#include <stdio.h>

int main( int argc, char **argv )
//char *argv[] 是 array of pointers
//char **argv
{
	int x;

	for(x=0; x<argc; x++)
		printf("%s\n",*(argv+x) );

	return(0);
}

Pointers to Pointers
- An array of pinters is a collection of addresses
- All addresses must be initialized
- The pointer to the pointers =
the location where the array of pointers is stored
 
*fruit[] = 0xFFFF0800, ->apples
		   0xFFFF0807, ->bananas
		   0xFFFF080F, ->Grapes
		   0xFFFF0817, ->Strawberries
=**fruit





04_01-strings1
#include <stdio.h>

int main()
{
	char *fruit[] = {
		"Apples", "Bananas", "Grapes", "Strawberries"
	}; // *fruit[]裡面存的是指標 fruit[x]是指標
	int x;

	for(x=0; x<4; x++)
		printf("Address: %p = %s\n", fruit[x], fruit[x]);

	return(0);
}
04_01-strings2
#include <stdio.h>

int main()
{
	char *fruit[] = {
		"Apples", "Bananas", "Grapes", "Strawberries"
	};
	char **f;
	int x;

	f = fruit; //initialize f 初始化為fruit
	for(x=0; x<4; x++)
		printf("Address: %p = %s\n", *(f+x), *(f+x) );
		//輸出是pointers
	return(0);
}
04_01-strings3
#include <stdio.h>

int main()
{
	char *fruit[] = {
		"Apples", "Bananas", "Grapes", "Strawberries"
	};
	char **f;
	int x;

	f = fruit;
	for(x=0; x<4; x++)
	{
		printf("Address: %p = %s\n", *f, *f );
		f++;
	}
	//輸出是pointers
	return(0);
}
04_01-strings4
#include <stdio.h>

int main()
{
	char *fruit[] = {
		"Apples", "Bananas", "Grapes", "Strawberries"
	};
	char **f;
	int x;

	f = fruit;
	for(x=0; x<4; x++)
	{
		printf("First letter: %c\n", **f );
		f++;
		//輸出first letter in each string
		// A B G S
		// **f = *(*f)  
		//(*f) =address
		//**f = *(*f)=char值
	}

	return(0);
}

04_01-strings5
#include <stdio.h>

int main()
{
	char *fruit[] = {
		"Apples", "Bananas", "Grapes", "Strawberries"
	};
	char **f;
	int x,y;

	f = fruit;
	for(x=0; x<4; x++)
	{
		y = 0;
		while( *(*f+y) )//*f=pointer y=offset *(*f+y)=memory location 等於NULL時while結束 
		{
			putchar( *(*f+y) );
			y++;
		}
		putchar('\n');
		f++;
	}

	return(0);
}


27 - Sending a pointer to a function

可以將指標傳入function as an argument
04_02-array1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *day0 = "Sunday";
	char *day1 = "Monday";
	char *day2 = "Tuesday";
	char *day3 = "Wednesday";
	char *day4 = "Thursday";
	char *day5 = "Friday";
	char *day6 = "Saturday";
	char **week;
	int x;

	week = (char **)malloc( sizeof(char *) * 7);
	if( week==NULL )
	{
		fprintf(stderr,"Unable to allocate array\n");
		exit(1);
	}

	*(week+0) = day0;
	*(week+1) = day1;
	*(week+2) = day2;
	*(week+3) = day3;
	*(week+4) = day4;
	*(week+5) = day5;
	*(week+6) = day6;

	for( x=0; x<7; x++)
		printf("%s\n",*(week+x) );
	//output:Sunday~Saturday

	return(0);
}

04_02-fill1 有BUG 會crash
#include <stdio.h>
#include <stdlib.h>

void fill(int *n)
{
	int x;

	n = (int *)malloc( sizeof(int) * 4);
	if( n==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	for(x=0; x<4; x++)
	{
		*(n+x) = (x+1)*11;
		printf("%d ",*(n+x) );
	}
	putchar('\n');
}

int main()
{
	int *numbers;
	int x;

	fill(numbers);
	for(x=0; x<4; x++)
	{
		printf("%d ",*(numbers+x) );
	}
	//output:crashed 11 22 33 44
	putchar('\n');

	return(0);
}

04_02-fill2
#include <stdio.h>
#include <stdlib.h>

void fill(int *n)
{
	int x;

	n = (int *)malloc( sizeof(int) * 4);
	if( n==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}
	printf("Allocated address: %p\n",n);

	for(x=0; x<4; x++)
	{
		*(n+x) = (x+1)*11;
		printf("%d ",*(n+x) );
	}
	putchar('\n');
}

int main()
{
	int *numbers;
	int x;

	fill(numbers);
	printf("After the call: %p\n",numbers);
	for(x=0; x<4; x++)
	{
		printf("%d ",*(numbers+x) );
	}
	putchar('\n');

	return(0);
}
04_02-fill3

#include <stdio.h>
#include <stdlib.h>

void fill(int **n)
{
	int x;

	*n = (int *)malloc( sizeof(int) * 4);
	if( *n==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	for(x=0; x<4; x++)
	{
		*(*n+x) = (x+1)*11;
		printf("%d ",*(*n+x) );
	}
	putchar('\n');
}

int main()
{
	int *numbers;
	int x;

	fill(&numbers);
	for(x=0; x<4; x++)
	{
		printf("%d ",*(numbers+x) );
	}
	//11 22 33 44
	putchar('\n');

	return(0);
}


28 - Sorting pointers

04_03-weekdays1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char weekdays[7][10] = {
		"Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday"
	};
	char temp[10];
	int x,y;

	/* output original array */
	puts("Unsorted:");
	for( x=0; x<7; x++ )
		printf(" %s\n",weekdays[x]);

	/* sort the array, bubble sort */
	for( x=0; x<6; x++ )
	{
		for( y=x+1; y<7; y++ )
		{
			/* Sort alphabetically, A to Z */
			if( strcmp(weekdays[x],weekdays[y]) > 0 )
			{
				strcpy(temp,weekdays[x]);
				strcpy(weekdays[x],weekdays[y]);
				strcpy(weekdays[y],temp);
			}
		}
	}

	/* output the sorted result */
	puts("Sorted:");
	for( x=0; x<7; x++ )
		printf(" %s\n",weekdays[x]);

	return(0);
}

04_03-weekdays2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *weekdays[7] = {
		"Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday"
	};
	char *temp;
	int x,y;

	/* output original array */
	puts("Unsorted:");
	for( x=0; x<7; x++ )
		printf(" %s\n",weekdays[x]);

	/* sort the array, bubble sort */
	for( x=0; x<6; x++ )
	{
		for( y=x+1; y<7; y++ )
		{
			/* Sort alphabetically, A to Z */
			if( strcmp(weekdays[x],weekdays[y]) > 0 )
			{
				temp = weekdays[x];
				weekdays[x] = weekdays[y];
				weekdays[y] = temp;
			}
		}
	}

	/* output the sorted result */
	puts("Sorted:");
	for( x=0; x<7; x++ )
		printf(" %s\n",weekdays[x]);

	return(0);
}



29 - Managing memory

The memcpy() and memmove() Functions
- Defined in the string.h header file
- Copy or move a chunk of memory
- Work with bytes or size_t values
- 這些函式Manipulate memory
- The memory(address) is a pointer or name of an array
- Memory contents are moved or copied

04_04-memcpy1 重要 摳矩陣
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a[] = { 100, 101, 102, 103 };
	int b[4];
	int x;

	memcpy(b,a, sizeof(int) * 4);
	//這個memcpy把a矩陣裡面的東西copy進b矩陣
	//矩陣裡有四個東西

	for(x=0; x<4; x++)
		printf("%d = %d\n",a[x],b[x]);

	return(0);
}
04_04-memmove1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a[] = { 100, 101, 102, 103, 104 };
	int x;

	memmove(&a[1],a, sizeof(int) * 4);
	//&a[1]=address of a[1]
	//將a矩陣摳到a[1]的位置 

	for(x=0; x<5; x++)
		printf("%d\n",a[x]);
	//100 100 101 102 103

	return(0);
}

04_04-memcpy2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct person {
		char name[8];
		int age;
	} man = { "Paul", 64 };
	unsigned char *buffer;
	int x;

	/* output the structure */
	printf("%s is %d years old\n",man.name,man.age);

	/* allocate the unsigned char buffer */
	buffer = (unsigned char *)malloc( sizeof(struct person) );
	if( buffer==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* copy memory */
	memcpy(buffer,&man,sizeof(struct person));
	//copy &man進buffer
	
	/* dump the buffer */
	puts("Buffer dump:");
	for( x=0; x<(int)sizeof(struct person); x++ )
	{
		printf(" %02X",*(buffer+x));
	}
	putchar('\n');

	return(0);
}

04_04-memcpy3 void buffer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct person {
		char name[8];
		int age;
	} man = { "Paul", 64 };
	void *buffer;//stored in a void buffer
	int *bufint;
	char *bufchar;

	/* allocate the void buffer */
	buffer = malloc( sizeof(struct person) );
	if( buffer==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* copy memory */
	memcpy(buffer,&man,sizeof(struct person));
	//&man is copied to buffer
	/* initialize the data type pointers */
	bufchar = (char *)buffer;
	bufint = (int *)(buffer+8);
	//bufchar:character pointer;bufint:integer pointer
	//can access information in the void buffer 
	/* the string referenced by bufchar is a
	   pointer, but the contents of bufint
	   are required, so it's prefixed with
	   the asterisk operator */
	printf("%s is %d years old\n",bufchar,*bufint);
	//bufchar = string *bufint = integer value
	//Paul is 64 years old
	return(0);
}




30 - Creating pointers to functions

void (*fp)(int a)
function as a pointer

void (*fp):data type
fp:function name
(int a):argument list

04_05-output1

#include <stdio.h>

void output(int a[])//傳入矩陣
{
	int x;

	for(x=0; x<5; x++)
		printf("%d\n",a[x]);
	//output: 3 5 7 9 11
	}

int main()
{
	int numbers[] = { 3, 5, 7, 9, 11 };

	output(numbers);

	return(0);
}

04_05-output2
#include <stdio.h>

void output(int a[])
{
	int x;

	for(x=0; x<5; x++)
		printf("%d\n",a[x]);
	//3 5 7 9 11
}

int main()
{
	int numbers[] = { 3, 5, 7, 9, 11 };
	void (*fp)(int a[]);
	//function pointer variable, type:void
	fp = output; //initialize fp
	fp(numbers);

	return(0);
}

04_05-main1
#include <stdio.h>

int main()
{
	printf("The main() function's address is %p\n",
			main//main是一個pointer, 輸出指標
		  );

	return(0);
}




31 - Challenge Manipulate a pointer array


32 - Solution Manipulate a pointer array

04_07-solution1
#include <stdio.h>
#include <stdlib.h>

/* allocate pointer and assign text */ 
void get_input(char **b)
{
	int x;

	/* allocate the buffer */
	*b = (char *)malloc( sizeof(char) * 16 );
	if( *b==NULL )
	{
		fprintf(stderr,"Unable to allocate buffer\n");
		exit(1);
	}

	/* read in text */
	fgets(*b,16,stdin);

	/* remove the newline */
	for( x=0; x<16; x++ )
	{
		/* search for newline */
		if( *(*b+x)=='\n' )
		{
			/* replace with null character */
			*(*b+x)='\0';
			/* exit loop */
			break;
		}
	}
}

/* create the array of pointers and output the results */
int main()
{
	char **names;
	int x;

	/* allocate space for the pointer array */
	names = (char **)malloc( sizeof(char *) * 5 );
	if( names==NULL )
	{
		fprintf(stderr,"Unable to allocate array\n");
		exit(1);
	}

	/* read the names */
	for( x=0; x<5;x++ )
	{
		printf("Name #%d: ",x+1);
		get_input( names+x );
	}

	/* output the results */
	for( x=0; x<5;x++ )
		printf("%s\n",*(names+x));

	return(0);
} 

04_07-solution2

#include <stdio.h>
#include <stdlib.h>

/* allocate pointer and assign text */ 
void get_input(char **b)
{
	int x;

	/* allocate the buffer */
	*b = (char *)malloc( sizeof(char) * 16 );
	if( *b==NULL )
	{
		fprintf(stderr,"Unable to allocate buffer\n");
		exit(1);
	}

	/* read in text */
	fgets(*b,16,stdin);

	/* remove the newline */
	for( x=0; x<16; x++ )
	{
		/* search for newline */
		if( *(*b+x)=='\n' )
		{
			/* replace with null character */
			*(*b+x)='\0';
			/* exit loop */
			break;
		}
	}
}

/* create the array of pointers and output the results */
int main()
{
	char *names[5];
	int x;

	/* read the names */
	for( x=0; x<5;x++ )
	{
		printf("Name #%d: ",x+1);
		get_input( &names[x] );
	}

	/* output the results */
	for( x=0; x<5;x++ )
		printf("%s\n",names[x]);

	return(0);
}