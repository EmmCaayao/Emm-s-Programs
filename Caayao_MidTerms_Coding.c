#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int main()
{
    char again;
	int number[MAX], i, j, max=0;
	printf("Good day User!\n");
	printf("Please input 5 integers: \n");
	for(i = 0; i < MAX; i++) {
    scanf(" %d", &number[i]);
	}
	for(j = 0; j < MAX; j++)
	{
    if(number[j] > max) {
    max = number[j];
    }
	}
	{
	printf("The highest value is: %d\n", max);
	printf("This code is developed by Emm Katrina L. Caayao\n");
	return 0;
	{
    {
    printf("\n\n\tDo you want to try again? [Press Y if Yes and N if No]: \n");
    again = getch();
    if(again == 'n' || again == 'N')
        break;
    }
    }while(again == 'y' || again == 'Y'); return 0;
}
