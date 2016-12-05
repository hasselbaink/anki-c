#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fptr;
char ch;
char fileName[1024];

void startGame(char *path);
void createFile(char *path);
void getstr(char *str);
char *getpath();

int main()
{
	char choice[8];

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
	char word[50];
	while (*word != 'q')
	{
		fgets(word, 50, stdin);
	}
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
	{
		str[strlen(str)-1] = '\0';
	}
}
char *getpath()
{
	printf("File name(default: words.txt): ");
	fgets(fileName, 1024, stdin);
	getstr(fileName);
	if (strlen(fileName) == 0)
	{
		strcpy(fileName, "words.txt");
	}
	return fileName;
}
