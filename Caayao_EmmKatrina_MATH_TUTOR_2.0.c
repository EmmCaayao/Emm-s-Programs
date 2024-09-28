#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main (){

        int choice;
        char again;
        int i, array[100];

        printf("\n\t\t Good day! Welcome to MATH TUTOR 2.0!\n\n");
        printf("\tPress 1. For Addition Problem\n");
        printf("\tPress 2. For Subtraction Problem\n");
        printf("\tPress 3. For Multiplication Problem\n");
        printf("\tPress 4. For Division Problem\n");
        printf("\tPress 5. Exit\n");
        printf("\tPick your poison!: ");
        scanf("%i", &choice);

    if(choice == 1)

{
    int a, max, num1, num2, result, answer, score = 0;
    char again;
    srand(time(NULL));
    int i, j, array[100];
    srand(0);
    for (i = 0; i < 100; i++)
    {
        array[i] = rand();
    }

    do{
        printf("How many addition problems do you want?: ");
        scanf("%i", &max);
        for(a=1; a<=max; a++)
        {
            num1 = array[0]%10;
            num2 = array[1]%10;

  for (int j =0; j<2; j++)
  array[j] = rand();

            result = num1 + num2;
            printf("\nWhat is the sum of %i + %i = ?: ", num1, num2);
            scanf("%i",&answer);
            if(result == answer)
            {
                printf("\n\tCorrect!\n");
                score = score + 1;
            }
            else
                printf("Wrong! The correct answer is %i\n", result);
            }
             printf("\n\tYour score is %i/%i", score, max);
            {
        printf("\n\n\tDo you want to try again? [Press Y if Yes and N if No]: \n");
        again = getch();
        if(again == 'n' || again == 'N')
            break;
            }
            }while(again == 'y' || again == 'Y');
            return 0;
}

    if(choice == 2)

        {
    int a, max, num1, num2, result, answer, score = 0;
    char again;
    srand(time(NULL));
    int i, j, array[100];
    srand(0);
    for (i = 0; i < 100; i++)
    {
        array[i] = rand();
    }

    do{
        printf("How many subtraction problems do you want?: ");
        scanf("%i", &max);
        for(a=1; a<=max; a++)
        {
            num1 = array[0]%10;
            num2 = array[1]%10;

  for (int j =0; j<2; j++)
  array[j] = rand();

            result = num1 - num2;
            printf("\nWhat is the difference of %i - %i = ?: ", num1, num2);
            scanf("%i",&answer);
            if(result == answer)
            {
                printf("\n\tCorrect!\n");
                score = score + 1;
            }
            else
                printf("Wrong! The correct answer is %i\n", result);
        }
        printf("\n\tYour score is %i/%i", score, max);
         {
        printf("\n\n\tDo you want to try again? [Press Y if Yes and N if No]: \n");
        again = getch();
        if(again == 'n' || again == 'N')
            break;
            }
            }while(again == 'y' || again == 'Y');
            return 0;
        }

    if(choice == 3)

        {
    int a, max, num1, num2, result, answer, score = 0;
    char again;
    srand(time(NULL));
    int i, j,array[100];
    srand(0);
    for (i = 0; i < 100; i++)
    {
        array[i] = rand();
    }

    do{
        printf("How many multiplication problems do you want?: ");
        scanf("%i", &max);
        for(a=1; a<=max; a++)
        {
            num1 = array[0]%10;
            num2 = array[1]%10;

  for (int j =0; j<2; j++)
  array[j] = rand();

            result = num1 * num2;
            printf("\nWhat is the multiplication of %i * %i = ?: ", num1, num2);
            scanf("%i",&answer);
            if(result == answer)
            {
                printf("\n\tCorrect!\n");
                score = score + 1;
            }
            else
                printf("Wrong! The correct answer is %i\n", result);
        }
        printf("\n\tYour score is %i/%i", score, max);
        {
        printf("\n\n\tDo you want to try again? [Press Y if Yes and N if No]: \n");
        again = getch();
        if(again == 'n' || again == 'N')
            break;
            }
            }while(again == 'y' || again == 'Y');
            return 0;
        }

    if(choice == 4)

        {
    int a, max, num1, num2, result, answer, remainder, score = 0;
    int ans, uans;
    int remain, uremain;
    char again;
    srand(time(NULL));
    int i, j, array[100];
    srand(0);
    for (i = 0; i < 100; i++)
    {
        array[i] = rand();
    }

    do{
        printf("How many division problems do you want?: ");
        scanf("%i", &max);
        for(a=1; a<=max; a++)
        {

  for (int j =0; j<2; j++)
  array[j] = rand();

        num1 = array[0]%(10-1+1)+1;
        num2 = array[1]%(10-1+1)+1;
            result = num1 / num2;
            remainder = num1 % num2;

            printf("\nWhat is the division of %i / %i = ?: ", num1, num2);
            scanf("%i",&answer);
            scanf("%d",&uans);

            printf("Remainder = ");
            scanf("%d",&uremain);
            if(result == answer)
            {
                printf("\n\tCorrect!\n");
                score = score + 1;
            }
            else
                printf("Wrong! The correct answer is %i\n", result);
        }
        printf("\n\tYour score is %i/%i", score, max);
        {
        printf("\n\n\tDo you want to try again? [Press Y if Yes and N if No]: \n");
        again = getch();
        if(again == 'n' || again == 'N')
            break;
            }
            }while(again == 'y' || again == 'Y');
            return 0;
        }

    if(choice == 5)

    {
        printf("\n\tSee you next time!\n");
    }
    }
