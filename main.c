#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int countWords( FILE *file)
{
  char c;
  int count = 0;
  while ((c = fgetc(file)) != EOF)
  {
    if (c == ' ') count++;
  }

  return count;
}

char* getWord(FILE *file, int number)
{

  rewind(file);
  int count = 0;
  char *word = malloc (sizeof(char) * 50);

  while (fscanf(file, " %49s", word) != EOF)
  {
    if (++count == number)
    {
      strcat(word, " ");
      return word;
    }
  }
  free(word);
  return "";
}

int getBlessingSize(int size)
{
  int total = 0;
  int current;

  for (int i = 0; i < 100; i++)
  {
    total += rand() % (30 + size);
  }

  return total/100;
}

int main (int argc, char *argv [])
{
  srand(time(NULL));
  FILE *sacredText;
  char wordsOfGod[1000] = {0};

  sacredText = fopen("god.txt", "r");
  int numberOfWordsInFile = countWords(sacredText);

  int offering = (rand() % 20) - 10;

  for (int i = 0; i < getBlessingSize(offering); i++)
  {
    char *word = getWord(sacredText, rand() % numberOfWordsInFile);
    strcat(wordsOfGod, word);
    free(word);
  }

  fclose(sacredText);
  printf("GOD SAYS:\n %s\n", wordsOfGod);

  return 0;
}
