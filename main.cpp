#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#define X 15

using namespace std;

struct searchedWord{
	int id;
	char* word;
	int wordLength;
};

void fillmyarr(char* myArray)
{
	FILE *puzzle;
	puzzle = fopen("puzzle.txt", "r");
	int i = 0;
	while (!feof(puzzle))
	{
		fscanf(puzzle, "%s", &*(myArray+i));
	}
}

void fillsearcharr(searchedWord myWord[])
{
	FILE *searchingWords;
	searchingWords = fopen("searchedwords.txt", "r");
	int counter = 0;
	while (!feof(searchingWords))
	{
		fscanf(searchingWords, "%d%s",&myWord[counter].id,myWord[counter].word);
		counter++;
	}
	fclose(searchingWords);
}
bool horizontalSearch(char** puzzleArray, searchedWord* word)
{
	int counter = 0;
	int k = 0;
	while(k < sizeof(word))
	{
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < X; j++)
			{
				if (strcmp((*(puzzleArray + i) + j), ((word + k)->word + j)) == 0)
				{
					counter++;
					for (int z = 1; z <((word + k)->wordLength); z++)
					{
						if (strcmp((*(puzzleArray + i) + j + z), ((word + k)->word + j + z)) == 0)
						{
							counter++;
						}
					}
					if (counter == (word + k)->wordLength)
					{
						cout << (word + k)->word + j << endl;
						k++;
					}
				}
			}
		}
		return true;
	}
	
}
int main()
{	
	char myArray[226];
	char **puzzleArray;
	fillmyarr(myArray);
	
	int ROWS = X;
	int COLS = X;
	int k = 0;
	
	puzzleArray = new char *[ROWS];	
	for (int i = 0; i < ROWS; i++)
	{
		puzzleArray[i] = new char[COLS];
		for (int j = 0; j < COLS; j++)
		{
			puzzleArray[i][j] = myArray[k];
			cout << puzzleArray[i][j];
			k++;
		}
		cout << endl;
	}

	//Bu kýsma kadar 1. soru yapýldý//
	searchedWord myWord[10];
	fillsearcharr (myWord);
	horizontalSearch(puzzleArray, myWord);




	







	
	
	getchar();
}