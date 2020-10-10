Always 記得: 字串後的空字元
02.06.Modifying arrays

01_03-array1
#include <stdio.h>

int main()
{
	int values[10];
	int x;

	for(x=0;x<10;x++)
		printf("%d\n",values[x]);

	return(0);
}

01_03-copy1
#include <stdio.h>

int main()
{
	int original[5] = { 45, 50, 88, 100, 213 };
	int duplicate[5];
	int x;

	for(x=0;x<5;x++)
		duplicate[x] = original[x];

	puts("Array values:");
	for(x=0;x<5;x++)
		printf("Element#%d %3d == %3d\n",
				x,
				original[x],
				duplicate[x]
			  );

	return(0);
}
02.07.Passing an array to a function
01_04-passelement1

#include <stdio.h>

void incshow(char a)
{
	a++;
	putchar(a);
}

int main()
{
	char text[] = "Gdkkn ";
	int x;

	for(x=0;x<6;x++)
		incshow(text[x]);
	putchar('\n');
	//Hello!
	return(0);
}

01_04-passarray1
#include <stdio.h>

void incshow(char array[])
{
	int x;

	for(x=0;x<6;x++)
	{
		array[x]++;
		putchar(array[x]);
	}
}

int main()
{
	char text[] = "Gdkkn ";

	incshow(text);
	putchar('\n');
	//Hello!
	return(0);
}

01_04-returnarray1 有BUG要修改
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int makearray[](void)//修改此處
{
	int static array[5];//修改此處
	int x;

	for(x=0;x<5;x++)
		array[x] = rand() % 10 + 1;

	return(array);
}

int main()
{
	int x,r[5];

	srand( (unsigned)time(NULL) );
	puts("Here are your 5 random numbers:");
	r = makearray();
	for(x=0;x<5;x++)
		printf("%d\n",r[x]);

	return(0);
}

02.08.Working multi-dimensional arrays
01_05-grid1
#include <stdio.h>

int main()
{
	int grid[5][2];
	int x;

	for(x=0;x<5;x++)
	{
		grid[x][0] = x+1;
		grid[x][1] = grid[x][0] * 10;
	}

	for(x=0;x<5;x++)
		printf("%d: %d\n",grid[x][0],grid[x][1]);
	//10 20 30 40 50
	return(0);
}

01_05-grid2
#include <stdio.h>

int main()
{
	char tictactoe[3][3];
	int x,y;

	/* initialize */
	for(x=0;x<3;x++)
		for(y=0;y<3;y++)
			tictactoe[x][y] = '.';

	/* display */
	puts("Tic Tac Toe");
	for(x=0;x<3;x++)
	{
		for(y=0;y<3;y++)
			printf(" %c ",tictactoe[x][y]);
		putchar('\n');
	}
	//Tic Tac Toe
	//.   .   .
	//.   .   .
	//.   .   .	  
	return(0);
}

01_05-grid3
#include <stdio.h>

int main()
{
	char tictactoe[3][3][3];
	int x,y,z;

	/* initialize */
	for(x=0;x<3;x++)
		for(y=0;y<3;y++)
			for(z=0;z<3;z++)
				tictactoe[x][y][z] = '.';

	/* display */
	puts("Tic Tac Toe");
	for(x=0;x<3;x++)
	{
		printf("%*c",x+1,' ');
		for(y=0;y<3;y++)
		{
			for(z=0;z<3;z++)
				printf(" %c ",tictactoe[x][y][z]);
			printf("     ");	/* 5 spaces */
		}
		putchar('\n');
	}

	return(0);
	//Tic Tac Toe
	//.   .   .			.   .   .		.   .   .
		//.   .   .			.   .   .		.   .   .
			//.   .   .			.   .   .		.   .   . 
}
01_05-grid4

#include <stdio.h>

int main()
{
	char tictactoe[9];
	int x,y,z;

	/* initialize */
	for(x=0;x<3;x++)
		for(y=0;y<3;y++)
			for(z=0;z<3;z++)
				tictactoe[x+y+z] = '.';

	/* display */
	puts("Tic Tac Toe");
	for(x=0;x<3;x++)
	{
		printf("%*c",x+1,' ');
		for(y=0;y<3;y++)
		{
			for(z=0;z<3;z++)
				printf(" %c ",tictactoe[x+y+z]);
			printf("     ");	/* 5 spaces */
		}
		putchar('\n');
	}

	return(0);
	//Tic Tac Toe
	//.   .   .			.   .   .		.   .   .
		//.   .   .			.   .   .		.   .   .
			//.   .   .			.   .   .		.   .   . 
	}

02.09.Building a structure
Struct 底下的 member 都能當成變數來處理

01_06-structure1
#include <stdio.h>

int main()
{
	struct pixel {
		int horz;
		int vert;
		char color;
	};
	struct pixel center;//pixel structure variable=>"center"
	//pixel=definition; center=structure variable

	center.horz = 320;
	center.vert = 240;
	center.color = 'r';

	printf("The pixel at %d,%d is colored ",
			center.horz,
			center.vert
		  );
	switch(center.color)
	{
		case 'r':
			puts("red");
			break;
		case 'g':
			puts("green");
			break;
		case 'b':
			puts("blue");
			break;
		default:
			puts("Invalid");
	}

	return(0);
}
01_06-structure2
#include <stdio.h>

int main()
{
	struct pixel {
		int horz;
		int vert;
		char color;
	} center; //center is a structure variable of pixel definition
	//pixel=definition; center=structure variable

	center.horz = 320;
	center.vert = 240;
	center.color = 'r';

	printf("The pixel at %d,%d is colored ",
			center.horz,
			center.vert
		  );
	switch(center.color)
	{
		case 'r':
			puts("red");
			break;
		case 'g':
			puts("green");
			break;
		case 'b':
			puts("blue");
			break;
		default:
			puts("Invalid");
	}

	return(0);
}
01_06-structure3
#include <stdio.h>

int main()
{
	struct pixel {
		int horz;
		int vert;
		char color;
	} top, center, bottom;
	//pixel=definition; top, center, bottom;=structure variables

	top.horz = 320;
	top.vert = 0;
	top.color = 'r';
	center.horz = 320;
	center.vert = 240;
	center.color = 'g';
	bottom.horz = 320;
	bottom.vert = 480;
	bottom.color = 'b';

	return(0);
}
01_06-structure4
#include <stdio.h>

int main()
{
	struct pixel {
		int horz;
		int vert;
		char color;
	} center = { 320, 240, 'r' };//initialized structure variable
	//pixel=definition; center=structure variable
	printf("The pixel at %d,%d is colored ",
			center.horz,
			center.vert
		  );
	switch(center.color)
	{
		case 'r':
			puts("red");
			break;
		case 'g':
			puts("green");
			break;
		case 'b':
			puts("blue");
			break;
		default:
			puts("Invalid");
	}
	//The pixel at 320, 240 is colored red
	return(0);
}
02.10.Nesting structures
Structure裡面可以有any member
所以struct裡面還可以放struct

01_07-nested1
#include <stdio.h>
#include <string.h>

int main()
{
	struct date {
		int month;
		int day;
		int year;
	};
	struct person {
		struct date birthday; //date=definition //birthday=structure variable
		//month day year = member
		char name[32];
	};
	struct person president;
	//person=definition; president = structure variable

	president.birthday.month = 2;
	president.birthday.day = 22;
	president.birthday.year = 1732;
	strcpy(president.name,"George Washington");

	printf("%s was born on %d/%d/%d\n",
			president.name,
			president.birthday.month,
			president.birthday.day,
			president.birthday.year
		  );

	return(0);
}


01_07-nested2
#include <stdio.h>
#include <string.h>

int main()
{
	struct date {
		int month;
		int day;
		int year;
	};
	struct person {
		struct date birthday;//date=definition //birthday,died=structure variable
		//month day year = member
		struct date died;
		char name[32];
	};
	struct person president;

	president.birthday.month = 2;
	president.birthday.day = 22;
	president.birthday.year = 1732;
	president.died.month = 12;
	president.died.day = 14;
	president.died.year = 1799;
	strcpy(president.name,"George Washington");

	printf("%s was born on %d/%d/%d and died on %d/%d/%d\n",
			president.name,
			president.birthday.month,
			president.birthday.day,
			president.birthday.year,
			president.died.month,
			president.died.day,
			president.died.year
		  );

	return(0);
}


01_07-nested3
#include <stdio.h>

int main()
{
	struct date {
		int month;
		int day;
		int year;
	};
	struct person {
		struct date birthday;//date=definition //birthday,died=structure variable
		//month day year = member
		struct date died;
		char name[32];
	} president = {
		{ 2, 22, 1732 },
		{ 12, 14, 1799 },
		"George Washington"
	};

	printf("%s was born on %d/%d/%d and died on %d/%d/%d\n",
			president.name,
			president.birthday.month,
			president.birthday.day,
			president.birthday.year,
			president.died.month,
			president.died.day,
			president.died.year
		  );

	return(0);
}


02.11.Creating an array of structures

each structure 變成每個 array的element

01_08-structarray1
#include <stdio.h>

int main()
{
	struct pixel {
		int horz;
		int vert;
		char color;
	};
	struct pixel box[4];//def:pixel;4 structure variables:box, each has 3 members
	int x;

	box[0].horz = 100;
	box[0].vert = 50;
	box[0].color = 'r';
	box[1].horz = 200;
	box[1].vert = 50;
	box[1].color = 'r';
	box[2].horz = 100;
	box[2].vert = 100;
	box[2].color = 'r';
	box[3].horz = 200;
	box[3].vert = 100;
	box[3].color = 'r';

	for(x=0;x<4;x++)
	{
		printf("Pixel %d: %d, %d =  %c\n",
				x+1,
				box[x].horz,
				box[x].vert,
				box[x].color
			  );
	}

	return(0);
}

01_08-structarray2
#include <stdio.h>

int main()
{
	struct pixel {
		int horz;
		int vert;
		char color;
	} box[4];//def:pixel;4 structure variables:box, each has 3 members
	int x;

	box[0].horz = 100;
	box[0].vert = 50;
	box[0].color = 'r';
	box[1].horz = 200;
	box[1].vert = 50;
	box[1].color = 'r';
	box[2].horz = 100;
	box[2].vert = 100;
	box[2].color = 'r';
	box[3].horz = 200;
	box[3].vert = 100;
	box[3].color = 'r';

	for(x=0;x<4;x++)
	{
		printf("Pixel %d: %d, %d =  %c\n",
				x+1,
				box[x].horz,
				box[x].vert,
				box[x].color
			  );
	}

	return(0);
}


01_08-structarray3

#include <stdio.h>

int main()
{
	struct pixel {
		int horz;
		int vert;
		char color;
	} box[4] = {
		{ 100,  50, 'r' },
		{ 200,  50, 'r' },
		{ 100, 100, 'r' },
		{ 200, 100, 'r' }
		//initialize
		//def:pixel;4 structure variables:box, each has 3 members
	};
	int x;

	for(x=0;x<4;x++)
	{
		printf("Pixel %d: %d, %d =  %c\n",
				x+1,
				box[x].horz,
				box[x].vert,
				box[x].color
			  );
	}

	return(0);
}



02.12.Sending a structure to a function
01_09-passmember1
#include <stdio.h>

char *show_color(char c);

int main()
{
	struct pixel {
		int horz;
		int vert;
		char color;
	} center;

	center.horz = 320;
	center.vert = 240;
	center.color = 'r';

	printf("The pixel at %d,%d is colored %s\n",
			center.horz,
			center.vert,
			show_color(center.color)
			//將字元 center.color 傳進show color函式
		  );

	return(0);
}

char *show_color(char c)
//requires only a char element, char c, as argument
{
	switch(c)
	{
		case 'r':
			return("red");
		case 'g':
			return("green");
		case 'b':
			return("blue");
		default:
			return("Invalid");
	}
}
01_09-passall1有bug故修正如下一範例

01_09-passall2 有點bug已修正
#include <stdio.h>

struct pixel {
	int horz;
	int vert;
	char color;
};//struct 要移出函式，移到最上面，先定義，才是external或global


void show_pixel(struct pixel p);
//show pixel function prototype


int main()
{
	struct pixel center;//structure variable:center

	center.horz = 320;
	center.vert = 240;
	center.color = 'r';

	show_pixel(center);

	return(0);
}

void show_pixel(struct pixel p)
//def:pixel, structure variable:center,p=refernce
//直接把整個結構丟進show_pixel函式
{
	printf("Pixel found at %d,%d, color = ",
			p.horz,
			p.vert
		  );
	switch(p.color)
	{
		case 'r':
			puts("red");
			break;
		case 'g':
			puts("green");
			break;
		case 'b':
			puts("blue");
			break;
		default:
			puts("Invalid");
	}//output: The pixel at 320,240 is colored red
}



02.13.Understanding a union


01_10-union1
#include <stdio.h>

int main()
{
	union storage {
		char a;
		int b;
	} reg; //def:storage; reg:union variable

	reg.a = 'A';
	printf("reg.a stores %c\n",reg.a);

	reg.b = 1346;
	printf("reg.b stores %d\n",reg.b);

	return(0);
}
01_10-union2
#include <stdio.h>

int main()
{
	union storage {
		char a;
		int b;
	} reg;
	//a,b share the same storage space
	reg.a = 'A';
	printf("reg.a stores %c\n",reg.a);
	//reg.a stores A
	reg.b = 1346;
	printf("reg.b stores %d\n",reg.b);
	//reg.b stores 1346
	printf("reg.a stores %c\n",reg.a);
	//reg.a stores B
	//union會亂改數值 危險 故少用
	return(0);
}



02.14.Challenge Presidents of the U.S.A.

- construct an array of structures
- the array has 4 elements, each of which is a structure
- display the 4 structures
- swap 2 elements in the array
- display the 4 structures again
- create a person structure
- the person structure contains 2 members, name, a string of 32 chars, and the second member is a date structure:tookoffice
- the date structure has 3 integer members:month,day,year
- an array of person structures:presidents



02.15.Solution Presidents of the U.S.A.
01_12-solution1
#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
};
struct person {
	char name[32];
	struct date tookoffice;
};

void show(struct person p[])
{
	int x;

	puts("Presidents:");
	for(x=0;x<4;x++)
	{
		printf("President %s took office on %d/%d/%d\n",
				p[x].name,
				p[x].tookoffice.month,
				p[x].tookoffice.day,
				p[x].tookoffice.year
			  );
	}
}

int main()
{
	struct person presidents[4] = {
		{ "George Washington", { 4, 30, 1789 } },
		{ "Thomas Jefferson", { 3, 4, 1801 } },
		{ "Abraham Lincoln", { 3, 4, 1861 } },
		{ "Theodore Roosevelt", { 9, 14, 1901 } }
	};
	struct person temp; //person structure temp

	/* show them */
	show(presidents);
	/* swap 2 and 3 */
	printf("Swapping...");
	temp = presidents[1];
	presidents[1] = presidents[2];
	presidents[2] = temp;
	printf("done!\n");
	/* show again */
	show(presidents);

	return(0);
}




03.16.Using single character IO
02_01-putchar1
#include <stdio.h>

int main()
{
	putchar('H');
	putchar('e');
	putchar('l');
	putchar('l');
	putchar('o');
	putchar('\n');

	return(0);
}



02_01-putchar2
#include <stdio.h>

int main()
{
	putc('H',stdout);//standard output device
	putc('e',stdout);
	putc('l',stdout);
	putc('l',stdout);
	putc('o',stdout);
	putc('\n',stdout);

	return(0);
}
02_01-getchar1
#include <stdio.h>

int main()
{
	int ch; //注意是int

	printf("Type a character: ");
	ch = getchar();
	printf("Character '%c' received.\n",ch);

	return(0);
}
02_01-getchar2
#include <stdio.h>

int main()
{
	int ch1,ch2;//注意是int

	printf("Type a character: ");
	ch1 = getchar();
	printf("Type a character: ");
	ch2 = getchar();
	printf("Characters '%c' and '%c' received.\n",ch1,ch2);

	return(0);
}
02_01-getchar3
#include <stdio.h>

int main()
{
	int ch1,ch2;

	printf("Type two characters: ");
	ch1 = getchar();
	ch2 = getchar();//連續輸入AB
	printf("Characters '%c' and '%c' received.\n",ch1,ch2);
	//Characters A and B received.\n
	return(0);
}
02_01-getchar4
#include <stdio.h>

int main()
{
	int ch1,ch2;

	printf("Type two characters: ");
	ch1 = getc(stdin);//standard input device
	ch2 = getc(stdin);
	printf("Characters '%c' and '%c' received.\n",ch1,ch2);

	return(0);
}
02_01-typewriter1
#include <stdio.h>

int main()
{ //注意是Int不是char
	int a;

	while(1)
	{
		a = getchar();
		if(a == EOF)
			//EOF=integer, value when end of file
		//輸入完畢 ctrl+z = 輸入EOF 或 mac unix ctrl+d = 輸入EOF
			break;
		putchar(a);
	};//本例a是integer 但是這樣寫可以輸入連續的char
	

	return(0);
}


03.17.Testing characters

Testing characters:
- called C-type functions after the ctype.h 標頭檔
- Testing functions are called IS functions
- When the test fails: Functions return 0 (FALSE)
- When the test passes: Functions return non-zero values (TRUE)

Character-Testing functions
- isalpha(): char is a letter of the alphabet
- isdigit(): char is a number (0-9)
- isupper(): char is uppercase
- islower(): char is loercase


02_02-testchar1
#include <stdio.h>
#include <ctype.h>

int main()
{
	char string[] = "Nifty TEXT! 123\n";
	char ch;
	int x = 0;

	while( (ch = string[x]) != '\0' )
		//end of the string: null character \0
	//loop: each character of the string
	{
		if( isalpha(ch) )
			putchar('_');
		//字母以底線取代
		else
			putchar(ch);
		x++;
		//_____ ____! 123
	}

	return(0);
}
02_02-testchar2
#include <stdio.h>
#include <ctype.h>

int main()
{
	char string[] = "Nifty TEXT! 123\n";
	char ch;
	int x = 0;

	while( (ch = string[x]) != '\0' )
	{
		if( isdigit(ch) )
			putchar('_');//數字以底線取代
		
		else
			putchar(ch);
		x++;
		//"Nifty TEXT! ___"
	}

	return(0);
}
02_02-testchar3
#include <stdio.h>
#include <ctype.h>

int main()
{
	char string[] = "Nifty TEXT! 123\n";
	char ch;
	int x = 0;

	while( (ch = string[x]) != '\0' )
	{
		if( isupper(ch) )
			putchar('_');
		//大寫以底線取代  _ifty ____! 123
		else
			putchar(ch);
		x++;
	}

	return(0);
}
02_02-testchar4
#include <stdio.h>
#include <ctype.h>

int main()
{
	char string[] = "Nifty TEXT! 123\n";
	char ch;
	int x = 0;

	while( (ch = string[x]) != '\0' )
	{
		if( islower(ch) )
			putchar('_');
		//小寫以底線取代 N____ TEXT! 123
		else
			putchar(ch);
		x++;
	}

	return(0);
}

03.18.Working with character conversions

C-type Functions
- Testing or IS functions test
- Functions to modify characters
- tolower():大寫轉小寫
- toupper():小寫轉大寫
- Only argument is an integer, the character to convert
- Return value is an integer, the converted character

02_03-lowercase1
#include <stdio.h>
#include <ctype.h>

int main()
{
	char string[] = "My aunt types her email in ALL CAPS.\n";
	int ch; //注意是Int不是char
	int x = 0;

	while( (ch = string[x]) != '\0' )
	{
		putchar( tolower(ch) );
		//my aunt types her email in all caps.
		x++;
	}

	return(0);
}

02_03-uppercase1
#include <stdio.h>
#include <ctype.h>

int main()
{
	char string[] = "stop shouting at me!\n";
	int ch; //注意是Int不是char
	int x = 0;

	while( (ch = string[x]) != '\0' )
	{
		putchar( toupper(ch) );
		//全轉大寫:STOP SHOUTING AT ME!
		x++;
	}

	return(0);
}

02_03-mixed1
#include <stdio.h>
#include <ctype.h>

int main()
{
	char string[] = "Nifty TEXT! 123\n";
	int ch; //注意是Int不是char
	int x = 0;

	while( (ch = string[x]) != '\0' )
	{
		if( isupper(ch) )
			putchar( tolower(ch) );
		//大寫轉小寫
		else if( islower(ch) )
			putchar( toupper(ch) );
		//小寫轉大寫
		else
			putchar(ch);
		//nIFTY test! 123
		x++;
	}

	return(0);
}

03.19.Understanding strings in C

Strings in C
- string 不是 data type
- A character array = string
- 最後一個必定為\0 null character
- \0 ASCII character code 0 不在strlen lenghth count裡面 但是矩陣中他一定占一格
- \0 the null character 不等於 NULL (pointer constant)
- Create a char array:
char string[] = "Hello!\n";
char string[] = {'H','\n','\0'};
char string[8] = "Hello!\n"; //\0也要算進去

- char string[32]; 表示有31個char,和最後的\0
- 關於字串的函式 必須引進標頭檔 string.harderr
- strlen(): string長度
- strstr(): 搜尋string
- strcpy(): copy a string

- 一開始宣告多長就是多長 千萬不要讓string overflow



03.20.Fetching string input 重要

-scanf: read string

02_05-yourname1
#include <stdio.h>

int main()
{
	char input[10];

	printf("Your name? ");
	scanf("%s",input);
	printf("Pleased to meet you, %s!\n",input);
	
	//本範例的致命錯誤:打空白鍵的話空白後面不會出現
	//而且要注意超過10會overflow 
	//input[10]=9字元+\0

	return(0);
}


02_05-yourname2
#include <stdio.h>

int main()
{
	char input[10];

	printf("Your name? ");
	scanf("%9s",input);
	//將輸入長度限制在9字元 因為要考慮\0
	printf("Pleased to meet you, %s!\n",input);

	return(0);
}


02_05-yourname3 重要
#include <stdio.h>

int main()
{
	char input[10];

	printf("Your name? ");
	fgets(input,10,stdin);//用fgets比較好
	//input:buffer storage; 10=size of the buffer
	//stdin:file=standard input
	printf("Pleased to meet you, %s!\n",input);

	return(0);
}



02_05-yourname4
#include <stdio.h>

int main()
{
	char input[10];
	int i;

	printf("Your name? ");
	fgets(input,10,stdin);
	/* repace the newline in the buffer with the null character */
	//禁止換行 偵測到按enter則塞\0結束
	for(i=0;i<10;i++)
	{
		if(input[i] == '\n')
			input[i] = '\0';
	}
	printf("Pleased to meet you, %s!\n",input);

	return(0);
}

03.21.Sending string output
//重要
//fgets(input,10,stdin);//用fgets比較好 會自動限制在9個字元的輸入
//puts 輸出 會自動加上\n
//printf 輸出 不會自動加上\n

02_06-string1
#include <stdio.h>

int main()
{
	char string[] = "I'm such a handsome program!\n";
	int a;

	a = 0;
	while( string[a] != '\0' )
	{
		putchar( string[a] );
		//putchar一次輸出一個字元
		a++;
	}

	return(0);
}

02_06-string2
#include <stdio.h>

int main()
{
	char string[] = "I'm such a handsome program!\n";
	int a;

	a = 0;
	while( putchar(string[a]) != '\0' )
	{
		a++;
	}

	return(0);
}

02_06-string3
#include <stdio.h>

int main()
{
	char string[] = "I'm such a handsome program!\n";
	int a;

	a = 0;
	while( putchar(string[a]) )
		//精簡成這樣因為 \0=false
	{
		a++;
	}

	return(0);
}

02_06-string4
#include <stdio.h>

int main()
{
	char string[] = "I'm such a handsome program!\n";
	int a;

	a = 0;
	while( putchar(string[a++]) )
		//再精簡
		;

	return(0);
}

02_06-puts1
#include <stdio.h>

int main()
{
	char string[] = "Yet another string literal";

	puts("A string literal");
	//puts 輸出 會自動加上\n
	puts(string);

	return(0);
}

02_06-printf1
#include <stdio.h>

int main()
{
	printf("Hello, Earth!");
	//printf 輸出 不會自動加上\n

	return(0);
}

02_06-printf2
#include <stdio.h>

int main()
{
	printf("Hello, Earth!\n");
	printf("%s","Hello, Moon!\n");

	return(0);
}


03.22.Reviewing printf() placeholders
%d, %i = integer to decimal
%u = unsigned integer
%f = floating point (float, double)
%e, %E = scientific notation
%g, %G = floating point / science output for large numbers
%c = single characters
%s = strings
%x, %X = hexadecimal (lowercase, uppercase)
%o = octal
%p = memory address in hexadecimal
%z = memory size (of size_t value)
%% = output the % character 輸出一個%

%hd = short integer
%l = long int
%ll = long long
%lu = long unsigned
%ld = long double

%5d  = 5 spaces for the integer
%-5d = the values are left justified within that five-character width.
%05d = a zero prefix is the width, any leading spaces are replaced with zeros

%7.2f = value in a width of seven spaces. The 5th character would be the decimal point, and then two digits appear after the decimal point.
%.2f = 沒規定width 小數只有兩位 2 digits 


03.23.Using printf() placeholders

02_08-convchar1
#include <stdio.h>

int main()
{
	int a = 123;

	puts("The %d placeholder, no width specification:");
	printf("%d\n",a);//123
	puts("8-character width:");
	printf("%8d\n",a);//_____123
	printf("%8d\n",a*10);//____1230
	printf("%8d\n",a*100);//___12300
	puts("Left-justified 8-character width:");
	printf("%-8d\n",a);//123
	printf("%-8d\n",a*10);//1230
	printf("%-8d\n",a*100);//12300
	puts("8-character width padded with zeros:");
	printf("%08d\n",a);//00000123
	printf("%08d\n",a*10);//00001230
	printf("%08d\n",a*100);//00012300

	return(0);
}


02_08-convchar2
#include <stdio.h>

int main()
{
	float a = 1234.5678;

	puts("Placeholder %f, no width specification:");
	printf("%f\n",a);//1234.567749
	puts("Width of 15 characters, %15f:");
	printf("%15f\n",a);//包含小數點共15個位置____1234.567749
	puts("Width of 6 characters, 1 decimal place, %6.1f");//包含小數點共6個位置 只有一個小數1234.6
	printf("%6.1f\n",a);
	puts("No width, limit to 2 decimal places, %.2f");//四捨五入至小數第二位
	printf("%.2f\n",a);

	return(0);
}

02_08-convchar3
#include <stdio.h>

int main()
{
	double avogadro = 6.022e23;

	puts("Large value with %f:");
	printf("%f\n",avogadro);//6022000000000....0000
	puts("With the %e and %E placeholders:");
	printf("%e\n",avogadro);//6.022000e+023
	printf("%E\n",avogadro);//6.022000E+023
	puts("With %g and %G:");
	printf("%g\n",avogadro);//6.022e+023
	printf("%G\n",avogadro);//6.022E+023

	return(0);
}

02_08-convchar4
#include <stdio.h>

int main()
{
	char string[] = "Deadly spiders!";

	puts("String displayed with %s:");
	printf("%s\n",string);//Deadly spiders!
	puts("String displayed in a 24-character width:");
	printf("%24s\n",string);//      Deadly spiders!
	puts("24-character width, left-justified:");
	printf("%-24s\n",string);//Deadly spiders!
	puts("24-character width, 6-character truncated:");
	//.6 縮減成6個字元 24個位置 %靠右對齊 %-負號靠左對齊
	printf("%24.6s\n",string);//      Deadly
	puts("24-character width, 6-character truncated, left-justified:");
	printf("%-24.6s\n",string);//Deadly

	return(0);
}


03.24.Exploring string functions

String functions:
- 用到字串時必須引入這個標頭檔 string.h
- strlen = string length
- strcmp = string compare
- strstr = string search

size_t strlen(const char *s)
- single argument, a string variable or literal
- 傳回整數值 returns an integer (size_t) value
- 注意 最後的\0 null character不算在strlen內
- \n, \t 這些跳脫字元算是一個single character

02_09-strlen1
#include <stdio.h>
#include <string.h>

int main()
{
	char string[] = "Hello, you happy planet.";
	int len;

	len = strlen(string);
	printf("The string \"%s\" is %d characters long.\n",string,len);
	//24 characters long. 不包含\0
	return(0);
}

字串的比較strcmp
int strcmp(const char *s1, const char *s2);
- 2 arguments, the strings to compare
- 若兩者完全一樣，則回傳0
- 若兩者不一樣，則回傳非0整數



02_09-strcmp1
#include <stdio.h>
#include <string.h>

int main()
{
	char r[] = "red";
	char g[] = "green";
	char b[] = "blue";

	if( strcmp(r,"blue") == 0 )
		printf("%s compares with \"blue\"\n",r);
	if( strcmp(g,"blue") == 0 )
		printf("%s compares with \"blue\"\n",g);
	if( strcmp(b,"blue") == 0 )//完全相同 印出blue
		printf("%s compares with \"blue\"\n",b);

	return(0);
}

字串搜尋 strstr
char * strstr(const char *haystack, const char *needle);
-前面haystack是要被搜尋的字串
-後面needle是關鍵字
-如果找不到關鍵字 則 returns character pointer NULL
-如果找到關鍵字 回傳關鍵字在haystack的location



02_09-strstr1
#include <stdio.h>
#include <string.h>

int main()
{
	char needle[] = "heart";
	char haystack[] = "Get to the heart of the matter";
	char *found;//char pointer variable

	found = strstr(haystack,needle);
	if(found == NULL)
		printf("The string \"%s\" was not found in \"%s\".\n",
				needle,
				haystack
			  );
	else
		printf("The string \"%s\" was found in \"%s\".\n",
				needle,
				haystack
			  );
	return(0);
}

02_09-strstr2
#include <stdio.h>
#include <string.h>

int main()
{
	char needle[] = "heart";
	char haystack[] = "Get to the heart of the matter";
	char *found;

	found = strstr(haystack,needle);
	if(found == NULL)
		printf("The string \"%s\" was not found in \"%s\".\n",
				needle,
				haystack
			  );
	else
		printf("The string \"%s\" was found at offset %ld in \"%s\".\n",
				needle,
				found-haystack,//found減haystack
				//重要 要這樣寫才會
				//was found at offset 11
				haystack
			  );
	return(0);
}

03.25.Manipulating strings

- 注意操作 string 時要引入標頭檔 string.h
- strcpy() = string copy, to copy strings
- strcat() = concact string

strcpy
char * strcpy(char * dst, const char *src);
- 前面是 destination buffer 後面是待複製的 source string
- destination buffer 必須要夠大 才裝得下複製的string

02_10-strcpy1
#include <stdio.h>
#include <string.h>

int main()
{
	char original[] = "Am I the original?";
	char duplicate[32]; //empty buffer

	printf("Here is the original string: %s\n",original);
	strcpy(duplicate,original);
	printf("Here is the duplicate: %s\n",duplicate);

	return(0);
}

02_10-strcpy2
#include <stdio.h>
#include <string.h>

int main()
{
	char original[] = "Am I the original?";
	char duplicate[] = "This is the duplicate";

	printf("Here is the original string: %s\n",original);
	printf("Here is the duplicate: %s\n",duplicate);
	strcpy(duplicate,original);
	printf("And now this is the duplicate: %s\n",duplicate);
    //Am I the original?
	//duplicate雖然比較長但還是整個複寫掉 沒有留任何原本文字
	return(0);
}

02_10-strcpy3
#include <stdio.h>
#include <string.h>

int main()
{
	char original[] = "Am I the original?";
	char duplicate[] = "Overwritten";
	//buffer太小 overflow了 這是錯誤的寫法

	printf("Here is the original string: %s\n",original);
	strcpy(duplicate,original);
	printf("Here is the duplicate: %s\n",duplicate);

	return(0);
}

strcat()
char * strcpy(char *restrict s1, const char *restrict s2);
- 前者是a string or character buffer 後者是要append上去的string
- 欲放入的string or buffer必須要有足夠的空間裝下兩個string



02_10-strcat1
#include <stdio.h>
#include <string.h>

int main()
{
	char first[16] = "George";
	char last[16] = "Washington";
	char full[32];

	strcpy(full,first);
	strcat(full,last);

	printf("Pleased to meet you, %s\n",full);

	return(0);
}

02_10-strcat2
#include <stdio.h>
#include <string.h>

int main()
{
	char first[16] = "George";
	char last[16] = "Washington";
	char full[32];

	strcpy(full,first);
	/* Append a string with a single space */
	strcat(full," ");	/* must be a string, not a single char */
	strcat(full,last);

	printf("Pleased to meet you, %s\n",full);

	return(0);
}

*****注意 使用string時
必須要考慮\0 占了一個空間
並且永遠都注意buffer要夠大
compiler不會檢查overflow
所以要自己多注意

03.26.Avoiding string problems

- 注意永遠都要加標頭 string.h
- 注意要留下足夠的buffer size_t
char string[characters+1];//+1是因為要包含\0 null character
char string[] = "hello world"//可以不定義陣列有多大

- memory allocation方法如下
char *string;
string = (char *)malloc( sizeof(char) * characters +1);
//+1是因為要包含\0 null character


02_11-longstring1
#include <stdio.h>

int main()
{
	char sonnet18[] = "Shall I compare thee to a summer's day?\
 Thou art more lovely and more temperate:\
 Rough winds do shake the darling buds of May,\
 And summer's lease hath all too short a date:\
 Sometime too hot the eye of heaven shines,\
 And often is his gold complexion dimmed;\
 And every fair from fair sometime declines,\
 By chance, or nature's changing course, untrimmed:\
 But thy eternal summer shall not fade,\
 Nor lose possession of that fair thou ow'st;\
 Nor shall Death brag thou wander'st in his shade\
 When in eternal lines to time thou grow'st:\
 So long as men can breathe or eyes can see,\
 So long lives this, and this gives life to thee.";

	puts(sonnet18);

	return(0);
}

03.27.Challenge String IO and manipulation

- Fetch string input from the user
- Process input and a string literal to generate a phrase
- Output the phrase



03.28.Solution String IO and manipulation

02_13-solution1
#include <stdio.h>
#include <string.h>

int main()
{
	char name[32];
	char buffer[64];
	char last[] = "passed the challenge!\n";
	int ch,a;

	/* fetch input */
	printf("What is your name? ");
	/* initialize a to 0, the first element of the array */
	a = 0;
	/* the test condition is the character returned from
	   the getchar() function; It ends on the newline */
	
	//用getchar()接收user input 並存進name[a] //name[32]扣掉空字元有31個空間可輸入
	//最後再補進空字元
	while( (ch=getchar()) != '\n' )
	{
		name[a] = ch;		/* store the character input */
		a++;			/* increment the array index */
		if(a==31)		/* check for buffer overflow; the 31st elemement is the last */
			break;		/* cancel on a full buffer */
	}
	name[a] = '\0';		/* cap the array (string) with a null character */

	/* process the strings */
	//依序放入name[32] " "和last字串進 buffer[64]
	strcpy(buffer,name);
	strcat(buffer," ");
	strcat(buffer,last);

	/* display the result */
	//用putchar輸出 buffer[64]
	a = 0;//記得重置a
	while( putchar(buffer[a++]) )//偵測到空字元時while停止
		;

	return(0);
}

常用的函式
scanf
fgets (佳)
puts (自動換行)
printf		

其它

getchar 一個字一個字輸入
putchar 一個字一個字輸出


04.29.Understanding pointers





04.30.Using pointers to manipulate data
















04_01-reading1
#include <stdio.h>

int main()
{
	const char filename[] = "sonnet18.txt";
	FILE *fh;

	/* open the file */
	fh = fopen(filename,"r");
	if( fh == NULL )
	{
		printf("Unable to read from file %s\n",filename);
		return(1);
	}
	
	printf("File '%s' opened\n",filename);

	/* close when you're done */
	fclose(fh);

	return(0);
}
04_01-reading2
#include <stdio.h>

int main()
{
	const char filename[] = "sonnet18.txt";
	FILE *fh;
	int ch;

	/* open the file */
	fh = fopen(filename,"r");
	if( fh == NULL )
	{
		printf("Unable to read from file %s\n",filename);
		return(1);
	}
	
	/* read the file one character at a time */
	while(1)
	{
		ch = fgetc(fh);
		if( ch == EOF )
			break;
		putchar(ch);
	}

	/* close when you're done */
	fclose(fh);

	return(0);
}

04_01-reading3
#include <stdio.h>

int main()
{
	const char filename[] = "sonnet18.txt";
	FILE *fh;
	char buffer[64];

	/* open the file */
	fh = fopen(filename,"r");
	if( fh == NULL )
	{
		printf("Unable to read from file %s\n",filename);
		return(1);
	}
	
	/* read the file 64 characters at a time */
	while( fgets(buffer,64,fh) )
		printf("%s",buffer);

	/* close when you're done */
	fclose(fh);

	return(0);
}
04_02-writing1
#include <stdio.h>

int main()
{
	FILE *fh;

	/* open/create the file */
	fh = fopen("output.txt","w");
	if( fh == NULL )
	{
		puts("Failed to create file");
		return(1);
	}

	/* output a line of text */
	fprintf(fh,"Hello there, file!\n");

	/* close the file */
	fclose(fh);

	return(0);
}

04_02-writing2
#include <stdio.h>

int main()
{
	FILE *fh;
	int a;

	/* open/create the file */
	fh = fopen("alphabet.txt","w");
	if( fh == NULL )
	{
		puts("Failed to create file");
		return(1);
	}

	/* output */
	for(a='A';a<='Z';a++)
		fputc(a,fh);

	/* close the file */
	fclose(fh);

	return(0);
}

04_02-writing3
#include <stdio.h>

int main()
{
	FILE *fh;

	/* open the file for appending */
	fh = fopen("alphabet.txt","a");
	if( fh == NULL )
	{
		puts("Failed to open file");
		return(1);
	}

	/* output */
	fputc('\n',fh);

	/* close the file */
	fclose(fh);

	return(0);
}

04_03-readf1
#include <stdio.h>

int main()
{
	const char filename[] = "integers.dat";
	FILE *fp;
	int x,a;

	/* open the file for reading */
	fp = fopen(filename,"r");
	if( fp == NULL )
	{
		printf("Unable to create %s\n",filename);
		return(1);
	}

	/* read integers */
	for(x=0;x<10;x++)
	{
		fread(&a, sizeof(int), 1, fp );
		printf("%d\n",a);
	}

	/* close */
	fclose(fp);

	return(0);
}


04_03-readf2
#include <stdio.h>

int main()
{
	const char filename[] = "integers.dat";
	FILE *fp;
	int x,a[10];

	/* open the file for reading */
	fp = fopen(filename,"r");
	if( fp == NULL )
	{
		printf("Unable to create %s\n",filename);
		return(1);
	}

	/* read integers */
	fread(&a, sizeof(int), 10, fp );
	for(x=0;x<10;x++)
		printf("%d\n",a[x]);

	/* close */
	fclose(fp);

	return(0);
}


04_03-writef1

#include <stdio.h>

int main()
{
	const char filename[] = "integers.dat";
	FILE *fp;
	int x,a;

	/* open and create the file */
	fp = fopen(filename,"w");
	if( fp == NULL )
	{
		printf("Unable to create %s\n",filename);
		return(1);
	}

	/* write the integers */
	a = 10;
	for(x=0;x<10;x++)
	{
		fwrite(&a, sizeof(int), 1, fp);
		a += 5;
	}

	/* and remember to close */
	fclose(fp);

	return(0);
}









