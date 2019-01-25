#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ASCII_START 33
#define ASCII_END 126
#define MIN_LEN 6
#define MAX_LEN 24
#define FALSE 0
#define TRUE !FALSE
#define LOWER_CASE_A 97
#define LOWER_CASE_Z 122
#define UPPER_CASE_A 65
#define UPPER_CASE_Z 90
#define SYMBOLS_START_A 33
#define SYMBOLS_END_A 47
#define SYMBOLS_START_B 91
#define SYMBOLS_END_B 96
#define SYMBOLS_START_C 123
#define SYMBOLS_END_C 126
#define NUMBERS_END 57
#define NUMBERS_START 48

int printMenu(void);

void generatePassword(char password[], int len);

int main(void)
{
  char password[MAX_LEN + 1] = {0};
  int userSelection = 0;
  char flag = 'a';
  srand(time(NULL));

  do
  {
    userSelection = printMenu();
    generatePassword(password, userSelection);
    printf("Your new password is: %s\n", password);
    printf("\nDo you want to generate another password (y/n)? ");
    scanf("%c", &flag);
  }
  while(flag != 'n');

  return 0;
}

int printMenu(void)
{
  int selection = 0;

  printf("Welcome to Urlord's Password Generator!\n");
  do
  {
    printf("Please enter the length of the password you want (between 6 and 24): ");
    scanf("%d", &selection);
    if(selection > MAX_LEN || selection < MIN_LEN)
    {
      printf("\nInvalid Input! Enter a number between 6 and 24.\n");
    }
  }
  while(selection > MAX_LEN || selection < MIN_LEN);

  return selection;
}

void generatePassword(char password[], int len)
{
  int i = 0;
  int validity = FALSE;
  int lowerCaseCounter = 0;
  int upperCaseCounter = 0;
  int numberCounter = 0;
  int symbolCounter = 0;

  do
  {
    validity = FALSE;
    lowerCaseCounter = 0;
    upperCaseCounter = 0;
    numberCounter = 0;
    symbolCounter = 0;
    for(i = 0; i < len; i++)
    {
      password[i] = rand() % (ASCII_END - ASCII_START + 1) + ASCII_START;
    }
    for(i = 0; i < len; i++)
    {
      if(password[i] >= LOWER_CASE_A && password[i] <= LOWER_CASE_Z)
      {
        printf("lower case %c\n", password[i]);
        lowerCaseCounter++;
      }
      if(password[i] >= UPPER_CASE_A && password[i] <= UPPER_CASE_Z)
      {
        printf("upper case %c\n", password[i]);
        upperCaseCounter++;
      }
      if(password[i] >= NUMBERS_START && password[i] <= NUMBERS_END)
      {
        printf("number %c\n", password[i]);
        numberCounter++;
      }
      if((password[i] >= SYMBOLS_START_A && password[i] <= SYMBOLS_END_A) || (password[i] >= SYMBOLS_START_B && password[i] <= SYMBOLS_END_B) || (password[i] >= SYMBOLS_START_C && password[i] <= SYMBOLS_END_C))
      {
        printf("symbol %c\n", password[i]);
        symbolCounter++;
      }
      //if(password[i] == password[i+1])
      {
        //validity = TRUE;
            //printf("%d\n", validity);
      }
    }
    if(lowerCaseCounter < 1 || upperCaseCounter < 1 || numberCounter < 1 || symbolCounter < 1)
    {
      validity = TRUE;
          //printf("%d\n", validity);
    }
  }
  while(!validity);
}
