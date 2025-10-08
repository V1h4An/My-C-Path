#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
/*char compchoice1()
{
    time_t t;
    time(&t);
    
if(t % 2 == 0)
{
  return 'r';
  }
else if(t % 3 == 0)
 { 
    return 'p';
 }
else
 {
   return 's';
 }
}*/
int game(char you, char comp)
{
    if(you == comp)
        return 0;
    if(you == 'r' && comp == 'p')
        return -1;
      else if (you == 'p' && comp == 'r')
        return 1;
    if(you == 'p' && comp == 's')
        return -1;
      else if (you == 's' && comp == 'p')
        return 1;
    if(you == 's' && comp == 'r')
        return -1;
      else if (you == 'r' && comp == 's')
        return 1;      
}
char compchoice()
{
 int n;
 char comp;
  srand(time(NULL));
  n = rand() %100;

    if (n<33)
        comp = 'r';
    else if (n>33 && n<66)
        comp = 'p';
    else
        comp = 's';

    return comp;
}

int result (int re)
{
 if (re == 0)
 {
  printf("\n\t\t\tGame Draw\n");
 }
else if (re == 1)
 {
  printf("\n\t\t\tYou won\n");
 }
else
 {
  printf("\n\t\t\tyou Lost\n");
 }
}    
int main()
{
//Step 1: Take choice from user and store in local variable
char you;
printf ("\n\t\t\tEnter r for Rock, p for Paper, s for Scissors\n");
scanf("%s",&you);

//Step 2: Generate computer choice by calling compchoice() and store in a local variable
char choice = compchoice();

//Step 3: Compare the two choices and capture result by calling result(), in a local variable
int re = game(you, choice);    //by calling game
 

//Step 4: Print the Outcome 
result(re);
printf ("\t\tYou entered %c and computer entered %c\n",you,choice);


return 0;
}