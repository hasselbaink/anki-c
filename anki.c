#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"

FILE *fptr;
char fileName[1024];

void startGame(char *path);
void createFile(char *path);
void getstr(char *str);
char *getpath();

int main()
{
	char choice[8];
	fptr = fopen("words.txt", "r");
	if (!fptr)
	{
		puts("Error");
		exit(1);
	}
	while (strcmp(choice, "exit") != 0)
	{
		printf("What are you doing?(play|create|replace|change|exit): ");
		fgets(choice, 8, stdin);
		getstr(choice);
		if (strcmp(choice, "play") == 0)
		{	
			startGame(getpath());
		}
		else if (strcmp(choice, "create") == 0)
		{

			createFile(getpath());
		}
	}
	return 0;
}
void startGame(char *path)
{
	int countNL = 0;
	char word[50];
	fptr = fopen(path, "r");
	while (!feof(fptr))
	{
		fgets(word, 50, fptr);
		if (word[(strlen(word)-1)] == '\n')
			countNL++;
	}
	countNL -= 1;
	fseek(fptr, 0, SEEK_SET);
	struct card *cards[countNL];
	for (int i = 0; i < countNL; i++)
	{
		cards[i] = (struct card *)malloc(sizeof(struct card));
		fgets(word, 50, fptr);
		for (int j = 0; j < strlen(word); j++)
		{
			if (word[j] == ':')
			{
				for (int k = 0; k < j; k++)
				{
					int m = strlen(cards[i]->word1);
					cards[i]->word1[m] = word[k];
				}
				//for (int k = j+1; k < strlen(word); k++)
				//{
					strcat(cards[i]->word2, &word[j+1]);
					//break;
				//}
				printf("%s:%s\n", 
						cards[i]->word1, 
						cards[i]->word2);
				break;
			}
			/*else
			{
				puts("Incorrect file type.");
				exit(1);
			}*/
		}
	}
	printf("Total count of words is %d.\n", countNL);
	/*
	while (*word != 'q')
	{
		getWords(path);
		fgets(word, 50, stdin);
	}*/
	putchar('\n');
}
void createFile(char *path)
{
	fptr = fopen(path, "w");
	if (fptr == 0)
	{
		puts("File wasn't created.");
		exit(1);
	}
	puts("File was be created successful.");
	fclose(fptr);
		
}
void getstr(char *str)
{
	if (str[strlen(str)-1] == '\n')
		str[strlen(str)-1] = '\0';
}
char *getpath()
{
	printf("File name(default: words.txt): ");
	fgets(fileName, 1024, stdin);
	getstr(fileName);
	if (strlen(fileName) == 0)
		strcpy(fileName, "words.txt");
	return fileName;
}
