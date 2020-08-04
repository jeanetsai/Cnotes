#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Menu()
{
	printf("=======================\n");
	printf("______1.Start game_____\n");
	printf("______0.Exit  game_____\n");
	printf("=======================\n");

	int choice = 0;

	printf("Input choice (0 or 1)¡G");
	scanf("%d", &choice);

	return choice;
}

void Game()
{
	//rand 1-100
	int random_num = rand() % 100 + 1;
	//int input_num = 0;
	while (1)
	{
		//Input an integer [1-100]
		printf("Input an integer [1-100]:");
		int input_num = 0;
		scanf("%d", &input_num);
		if (input_num < random_num)
		{
			printf("Larger!\n");
		}
		else if (input_num > random_num)
		{
			printf("Smaller!\n");
		}
		else
		{
			printf("You win!!!\n");
			break;
		}

	}


}

int main()
{

	srand((unsigned int)time(0));
	while (1)
	{
		int choice = Menu();
		if (choice == 1)
		{
			//Start game¡F
			Game();
		}
		else if (choice == 0)
		{
			//Exit¡F
			printf("Good Bye¡I\n");
			//quit();
			break;
		}
		else
		{
			printf("Input 0 or 1!");
			//int choice = Menu();
		}
	}

	system("pause");
	return 0;
}
