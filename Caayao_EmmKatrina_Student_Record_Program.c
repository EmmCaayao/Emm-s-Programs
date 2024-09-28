#include<stdio.h>
#include<stdlib.h>

struct student
{
    char name[50];
    int grade;
};

struct student *class;
int ClassSize;

void create()
{
    system("cls");
    printf("\n\tEnter Class Size: ");
    scanf("%d", &ClassSize);
    class = (struct student*) malloc(ClassSize * sizeof(struct student));
}

void input()
{
    system("cls");
    for (int i = 0; i < ClassSize; i++)
    {
        printf("\n\tEnter The Student's Name: ");
        scanf("%s", class[i].name);
        printf("\tEnter The Student's Grade: ");
        scanf("%d", &class[i].grade);
    }
}

void display()
{
    printf("\n\t==List of Student Names and Grades Entered==\n\n");
    system("cls");
    for (int i = 0; i < ClassSize; i++) {
    printf("\n\tName: %s\n\tGrade: %d\n\n", class[i].name, class[i].grade);
    }
}

void edit()
{
    system("cls");
    char name[50];
    printf("Enter the Name of the Student to Edit: ");
    scanf("%s", name);
    for (int i = 0; i < ClassSize; i++)
    {
        if (strcmp(class[i].name, name) == 0)
        {
            printf("Enter New Name: ");
            scanf("%s", class[i].name);
            printf("Enter New Grade: ");
            scanf("%d", &class[i].grade);
            break;
        }
    }
}

void save()
{
    system("cls");
    FILE *fp;
    fp = fopen("StudentGrades.txt", "w");
    for (int i = 0; i < ClassSize; i++)
    {
        fprintf(fp, "Name: %s\nGrade: %d\n", class[i].name, class[i].grade);
    }
    fclose(fp);
}

int main()
{
    int choice;
    do {
        system("cls");
        printf("\t======================================\n");
        printf("\t=====LETS ORGANIZE OUR CLASS FILE=====\n");
        printf("\t======================================\n");
        printf("\tPress 1: Create Class Size\n");
        printf("\tPress 2: Input Student Name and Grades\n");
        printf("\tPress 3: Display List of Students\n");
        printf("\tPress 4: Edit File\n");
        printf("\tPress 5: Save File\n");
        printf("\tPress 6: Exit\n");
        printf("\tEnter Your Choice:\n");
        printf("\t======================================\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: create();
                break;
            case 2: input();
                break;
            case 3: display();
                break;
            case 4: edit();
                break;
            case 5: save();
                break;
            case 6: exit(0);
                break;
            default: printf("Invalid choice, try again please!"); break;
        }
    }while(choice != 6);

    return 0;
}

