#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 1000
#define MAX_RESERVATIONS 10000
#define YEAR 2023

// Structure to store user information
typedef struct
{
    char firstName[50];
    char lastName[50];
    char phoneNumber[20];
    char email[50];
    char password[50];
} User;

// Structure for the admin log in information
typedef struct
{
    char email[50];
    char password[50];
} Admin;

Admin admin1 = {"admin123", "password"};

// Structure to store reservation information
typedef struct
{
    char email[50];
    char roomType[50];
    char roomNumber[50];
    char checkInMonth[50];
    char checkInDay[50];
    char checkOutMonth[50];
    char checkOutDay[50];
    int price;
    int downpayment;
} Reservation;

User users[MAX_USERS];
Reservation reservations[MAX_RESERVATIONS];
int userCount = 0;
int reservationCount = 0;
int userId;

void loadUsersFromFile()
{
    FILE *file = fopen("Hotel Users Accounts.txt", "r");
    if (file != NULL)
    {
        char line[256];
        while (fgets(line, sizeof(line), file) != NULL)
        {
            if (sscanf(line, "First Name: %s", users[userCount].firstName) == 1)
            {
                fgets(line, sizeof(line), file);
                sscanf(line, "Last Name: %s", users[userCount].lastName);

                fgets(line, sizeof(line), file);
                sscanf(line, "Phone Number: %s", users[userCount].phoneNumber);

                fgets(line, sizeof(line), file);
                sscanf(line, "Email: %s", users[userCount].email);

                fgets(line, sizeof(line), file);
                sscanf(line, "Password: %s", users[userCount].password);


                userCount++;
            }
        }
        fclose(file);
    }
}

void saveUsersToFile()
{
    FILE *file = fopen("Hotel Users Accounts.txt", "w");
    if (file != NULL)
    {
        for (int i = 0; i < userCount; i++)
        {
            fprintf(file, "First Name: %s\n", users[i].firstName);
            fprintf(file, "Last Name: %s\n", users[i].lastName);
            fprintf(file, "Phone Number: %s\n", users[i].phoneNumber);
            fprintf(file, "Email: %s\n", users[i].email);
            fprintf(file, "Password: %s\n\n", users[i].password);
        }
        fclose(file);
    }
}

void loadReservationsFromFile()
{
    FILE *file = fopen("Hotel Reservation.txt", "r");
    if (file != NULL)
    {
        char line[256];
        while (fgets(line, sizeof(line), file) != NULL)
        {
            if (sscanf(line, "Email: %s", reservations[reservationCount].email) == 1)
            {
                fgets(line, sizeof(line), file);
                sscanf(line, "Room Type: %s", reservations[reservationCount].roomType);

                fgets(line, sizeof(line), file);
                sscanf(line, "Room Number: %s", reservations[reservationCount].roomNumber);

                fgets(line, sizeof(line), file);
                sscanf(line, "Check-in date: %s - %s", reservations[reservationCount].checkInMonth, reservations[reservationCount].checkInDay);

                fgets(line, sizeof(line), file);
                sscanf(line, "Check-out date: %s - %s", reservations[reservationCount].checkOutMonth, reservations[reservationCount].checkOutDay);

                fgets(line, sizeof(line), file);
                sscanf(line, "Price: %d", &reservations[reservationCount].price);

                fgets(line, sizeof(line), file);
                sscanf(line, "Downpayment: %d", &reservations[reservationCount].downpayment);

                reservationCount++;
            }
        }
        fclose(file);
    }
}

void saveReservationsToFile()
{
    FILE *file = fopen("Hotel Reservation.txt", "w");
    if (file != NULL)
        {
            for (int i = 0; i < reservationCount; i++)
            {
                fprintf(file, "Email: %s\n", reservations[i].email);
                fprintf(file, "Room Type: %s\n", reservations[i].roomType);
                fprintf(file, "Room Number: %s\n", reservations[i].roomNumber);
                fprintf(file, "Check-in date: %s - %s\n", reservations[i].checkInMonth, reservations[i].checkInDay);
                fprintf(file, "Check-out date: %s - %s\n", reservations[i].checkOutMonth, reservations[i].checkOutDay);
                fprintf(file, "Price: %d\n", reservations[i].price);
                fprintf(file, "Downpayment: %d\n\n", reservations[i].downpayment);
            }
    fclose(file);
       }
}

//Function to Log-in using the account
int login()
{
    system("cls");
    char email[50];
    char password[50];

    printf("-- Login --\n");
    printf("\nEnter your email: ");
    scanf("%s", &email);
    printf("Enter your password: ");
    scanf("%s", &password);


    for (int i = 0; i < userCount; i++)
        {
            if ((strcmp(email, users[i].email) == 0) && (strcmp(password, users[i].password) == 0))
             {
                 return i;
             }
        }

    if ((strcmp(email, admin1.email) == 0) && (strcmp(password, admin1.password) == 0))
            {
                return MAX_USERS+1;
            }

    return -1;
}

//Function to create an account
void signUp()
{
    system("cls");
    printf("-- Sign Up --\n");
    printf("-- Create an account --\n");

    if (userCount >= MAX_USERS)
        {
            printf("\nMaximum number of users reached!");
            return;
        }

    printf("\nEnter your first name: ");
    scanf("%s", users[userCount].firstName);
    printf("Enter your last name: ");
    scanf("%s", users[userCount].lastName);
    printf("Enter your phone number: ");
    scanf("%s", users[userCount].phoneNumber);
    printf("Enter your email: ");
    scanf("%s", users[userCount].email);
    printf("Enter your password: ");
    scanf("%s", users[userCount].password);

    userCount++;
    saveUsersToFile();

    system("cls");
    printf("Creating account..... Please wait...."); delay(3000);
    system("cls");
    printf("\nAccount is created. You can now login.\n");
    printf("\nPress any key to continue...");
    getch();
}

//Function to Make a Reservation
void makeReservation(int userId)
{
    system("cls");
    printf("-- Make Reservation --\n");

    printf("\nReservation Email: %s\n", users[userId].email);

    int roomType;
    printf("\nRESERVATION IS FOR YEAR %d ONLY!", YEAR);
    printf("\nRoom Types:");
    printf("\n1. Solo Room - Strictly for 1 person only. Rate: 1500 pesos per day");
    printf("\n2. Special Solo Room - Strictly for 1 person only. Rate: 2000 pesos per day");
    printf("\n3. Room for Two - Strictly for 2 persons only. Rate: 3000 pesos per day");
    printf("\n4. Special Room for Two - Strictly for 2 persons only. Rate: 3500 pesos per day");
    printf("\n5. Bedroom for Four - Strictly for 4 persons only. Rate: 5000 pesos per day");
    printf("\nEnter the room type number: ");
    scanf("%d", &roomType);

    if((roomType < 1) || (roomType > 5))
    {
        printf("\nInvalid room type number. Please try again"); getch(); return;
    }

    int roomNumber;
    printf("\nRoom Numbers:\n");
    switch (roomType)
    {
        case 1:
            printf("101, 102, 103, 104, 105\n");
            break;
        case 2:
            printf("201, 202, 203, 204, 205\n");
            break;
        case 3:
            printf("301, 302, 303, 304, 305\n");
            break;
        case 4:
            printf("401, 402, 403, 404, 405\n");
            break;
        case 5:
            printf("501, 502, 503, 504, 505\n");
            break;
        default:
            printf("Invalid room type!\n");
            return;
    }
    printf("\nEnter the room number: ");
    scanf("%d", &roomNumber);
    if(roomType == 1)
    {
        if((roomNumber < 101) || (roomNumber > 105))
        {
            printf("\nInvalid room number. Please try again"); getch(); return;
        }
    }
    if(roomType == 2)
    {
        if((roomNumber < 201) || (roomNumber > 205))
        {
            printf("\nInvalid room number. Please try again"); getch(); return;
        }
    }
    if(roomType == 3)
    {
        if((roomNumber < 301) || (roomNumber > 305))
        {
            printf("\nInvalid room number. Please try again"); getch(); return;
        }
    }
    if(roomType == 4)
    {
        if((roomNumber < 401) || (roomNumber > 405))
        {
            printf("\nInvalid room number. Please try again"); getch(); return;
        }
    }
    if(roomType == 5)
    {
        if((roomNumber < 501) || (roomNumber > 505))
        {
            printf("\nInvalid room number. Please try again"); getch(); return;
        }
    }

    int ciMonth, ciDay, coMonth, coDay;
    printf("\nEnter the Check-in Month (1-12): ");
    scanf("%d", &ciMonth);
    printf("\nEnter the Check-in Day (1-28/30/31): ");
    scanf("%d", &ciDay);
    printf("\nEnter the Check-out Month (1-12): ");
    scanf("%d", &coMonth);
    printf("\nEnter the Check-out Day (1-28/30/31): ");
    scanf("%d", &coDay);

    if((ciMonth < 1) || (ciMonth > 12) || (coMonth < 1) || (coMonth > 12) || (ciMonth > coMonth))
        {
            printf("\nInvalid reservation date. Please try again"); getch(); return;
        }
    if((coMonth % ciMonth == 0) && (ciMonth != 1))
    {
        if((coDay < ciDay) || (coDay == ciDay))
        {
            printf("\nInvalid reservation date. Please try again"); getch(); return;
        }
    }
    if((ciMonth == 1) || (ciMonth == 3) || (ciMonth == 5) || (ciMonth == 7) || (ciMonth == 8) || (ciMonth == 10) || (ciMonth == 12))
    {
        if((ciDay < 1) || (ciDay > 31))
        {
            printf("\nInvalid reservation date. Please try again"); getch(); return;
        }
    }
    if((ciMonth == 4) || (ciMonth == 6) || (ciMonth == 9) || (ciMonth == 11))
    {
        if((ciDay < 1) || (ciDay > 30))
        {
            printf("\nInvalid reservation date. Please try again"); getch(); return;
        }
    }
    if(ciMonth == 2)
    {
        if((ciDay < 1) || (ciDay > 28))
        {
            printf("\nInvalid reservation date. Please try again"); getch(); return;
        }
    }
    if((coMonth == 1) || (coMonth == 3) || (coMonth == 5) || (coMonth == 7) || (coMonth == 8) || (coMonth == 10) || (coMonth == 12))
    {
        if((coDay < 1) || (coDay > 31))
        {
            printf("\nInvalid reservation date. Please try again"); getch(); return;
        }
    }
    if((coMonth == 4) || (coMonth == 6) || (coMonth == 9) || (coMonth == 11))
    {
        if((coDay < 1) || (coDay > 30))
        {
            printf("\nInvalid reservation date. Please try again"); getch(); return;
        }
    }
    if(coMonth == 2)
    {
        if((coDay < 1) || (coDay > 28))
        {
            printf("\nInvalid reservation date. Please try again"); getch(); return;
        }
    }

    // Check if the room is already reserved
    for (int i = 0; i < reservationCount; i++)
        {
            if ((roomType == 1) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkInMonth) == ciMonth) && (atoi(reservations[i].checkOutMonth) == coMonth)) &&
            ((atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= ciDay) ||
            (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= coDay) ||
            (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkInDay) <= coDay) ||
            (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkInDay) <= coDay)  ||
            (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkOutDay) <= ciDay)) ||
            ((roomType == 1) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkOutMonth) == ciMonth) && (atoi(reservations[i].checkInMonth) < coMonth) && (atoi(reservations[i].checkOutDay) >= ciDay))) ||
            ((roomType == 1) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkInMonth) == coMonth) && (atoi(reservations[i].checkInMonth) > ciMonth) && (atoi(reservations[i].checkInDay) <= coDay))))
            {
                system("cls");
                printf("\nRoom is already reserved!\n");
                printf("\nPlease try another room or date!\n");
                printf("\nPress any key to continue...\n");
                getch();
                return;
            }

           if ((roomType == 2) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkInMonth) == ciMonth) && (atoi(reservations[i].checkOutMonth) == coMonth)) &&
            ((atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= ciDay) ||
            (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= coDay) ||
            (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkInDay) <= coDay) ||
            (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkInDay) <= coDay)  ||
            (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkOutDay) <= ciDay)) ||
            ((roomType == 2) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkOutMonth) == ciMonth) && (atoi(reservations[i].checkInMonth) < coMonth) && (atoi(reservations[i].checkOutDay) >= ciDay))) ||
            ((roomType == 2) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkInMonth) == coMonth) && (atoi(reservations[i].checkInMonth) > ciMonth) && (atoi(reservations[i].checkInDay) <= coDay))))
            {
                system("cls");
                printf("\nRoom is already reserved!\n");
                printf("\nPlease try another room or date!\n");
                printf("\nPress any key to continue...\n");
                getch();
                return;
            }

            if ((roomType == 3) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkInMonth) == ciMonth) && (atoi(reservations[i].checkOutMonth) == coMonth)) &&
            ((atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= ciDay) ||
            (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= coDay) ||
            (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkInDay) <= coDay) ||
            (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkInDay) <= coDay)  ||
            (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkOutDay) <= ciDay)) ||
            ((roomType == 3) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkOutMonth) == ciMonth) && (atoi(reservations[i].checkInMonth) < coMonth) && (atoi(reservations[i].checkOutDay) >= ciDay))) ||
            ((roomType == 3) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkInMonth) == coMonth) && (atoi(reservations[i].checkInMonth) > ciMonth) && (atoi(reservations[i].checkInDay) <= coDay))))
            {
                system("cls");
                printf("\nRoom is already reserved!\n");
                printf("\nPlease try another room or date!\n");
                printf("\nPress any key to continue...\n");
                getch();
                return;
            }

            if ((roomType == 4) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkInMonth) == ciMonth) && (atoi(reservations[i].checkOutMonth) == coMonth)) &&
            ((atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= ciDay) ||
            (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= coDay) ||
            (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkInDay) <= coDay) ||
            (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkInDay) <= coDay)  ||
            (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkOutDay) <= ciDay)) ||
            ((roomType == 4) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkOutMonth) == ciMonth) && (atoi(reservations[i].checkInMonth) < coMonth) && (atoi(reservations[i].checkOutDay) >= ciDay))) ||
            ((roomType == 4) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkInMonth) == coMonth) && (atoi(reservations[i].checkInMonth) > ciMonth) && (atoi(reservations[i].checkInDay) <= coDay))))
            {
                system("cls");
                printf("\nRoom is already reserved!\n");
                printf("\nPlease try another room or date!\n");
                printf("\nPress any key to continue...\n");
                getch();
                return;
            }

            if ((roomType == 5) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkInMonth) == ciMonth) && (atoi(reservations[i].checkOutMonth) == coMonth)) &&
            ((atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= ciDay) ||
            (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= coDay) ||
            (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkInDay) <= coDay) ||
            (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkInDay) <= coDay)  ||
            (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkOutDay) <= ciDay)) ||
            ((roomType == 5) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkOutMonth) == ciMonth) && (atoi(reservations[i].checkInMonth) < coMonth) && (atoi(reservations[i].checkOutDay) >= ciDay))) ||
            ((roomType == 5) && (atoi(reservations[i].roomNumber) == roomNumber) &&
            ((atoi(reservations[i].checkInMonth) == coMonth) && (atoi(reservations[i].checkInMonth) > ciMonth) && (atoi(reservations[i].checkInDay) <= coDay))))
            {
                system("cls");
                printf("\nRoom is already reserved!\n");
                printf("\nPlease try another room or date!\n");
                printf("\nPress any key to continue...\n");
                getch();
                return;
            }
    }

    // Add the reservation
    strcpy(reservations[reservationCount].email, users[userId].email);
    switch (roomType)
    {
        case 1:
            strcpy(reservations[reservationCount].roomType, "Solo_Room");
            break;
        case 2:
            strcpy(reservations[reservationCount].roomType, "Special_Solo_Room");
            break;
        case 3:
            strcpy(reservations[reservationCount].roomType, "Room_for_Two");
            break;
        case 4:
            strcpy(reservations[reservationCount].roomType, "Special_Room_for_Two");
            break;
        case 5:
            strcpy(reservations[reservationCount].roomType, "Bedroom_for_Four");
            break;
    }
    sprintf(reservations[reservationCount].roomNumber, "%d", roomNumber);
    sprintf(reservations[reservationCount].checkInMonth, "%d", ciMonth);
    sprintf(reservations[reservationCount].checkInDay, "%d", ciDay);
    sprintf(reservations[reservationCount].checkOutMonth, "%d", coMonth);
    sprintf(reservations[reservationCount].checkOutDay, "%d", coDay);

    int duration = 0;
    duration = daysStay(ciMonth, ciDay, coMonth, coDay);

    switch (roomType)
    {
        case 1:
            reservations[reservationCount].price = 1500 * duration;
            break;
        case 2:
            reservations[reservationCount].price = 2000 * duration;
            break;
        case 3:
            reservations[reservationCount].price = 3000 * duration;
            break;
        case 4:
            reservations[reservationCount].price = 3500 * duration;
            break;
        case 5:
            reservations[reservationCount].price = 5000 * duration;
            break;
    }
    reservations[reservationCount].downpayment = reservations[reservationCount].price * .5;

    reservationCount++;

    saveReservationsToFile();

    printf("\nYour Reservation Details:\n");
    printf("Room Type: %s\n", reservations[reservationCount-1].roomType);
    printf("Room Number: %s\n", reservations[reservationCount-1].roomNumber);
    printf("Check-in date: %s-%s\n", reservations[reservationCount-1].checkInMonth, reservations[reservationCount-1].checkInDay);
    printf("Check-out date: %s-%s\n", reservations[reservationCount-1].checkOutMonth, reservations[reservationCount-1].checkOutDay);
    printf("Approximate price: %d\n", reservations[reservationCount-1].price);
    printf("Downpayment to settle (50 percent of the approximate price): %d\n", reservations[reservationCount-1].downpayment);

    printf("\nDownpayment should be settled within 7 working days for the reservation to be valid or it will be canceled.");
    printf("\nThe payment method for the downpayment will be in pesos whether GCash, Maya, Paypal, or Bank Transaction will be sent to your email upon confirming the reservation.\n");

    printf("\nDo you still want to continue the reservation? \n(Press 'Y' for Yes and 'N' for No)\n");
    char sure = getch();

    if(sure == 'y' || sure == 'Y')
    {
    printf("\nReservation made successfully!\n");
    printf("\nPress any key to continue...");
    getch();
    }
    else if(sure == 'n' || sure == 'N')
    {
        reservationCount--;
        saveReservationsToFile();
        printf("\nReservation canceled successfully!\n");
        printf("\nPress any key to continue...");
        getch();
    }
}

//Function to edit Reservation
void editReservation(int userId)
{
    system("cls");
    printf("-- Edit Reservation --\n");

    printf("\nReservation Email: %s\n", users[userId].email);

    int foundReservation = 0;

    // Find the reservation
    for (int j = 0; j < reservationCount; j++)
        {
        if (strcmp(users[userId].email, reservations[j].email) == 0)
        {
            foundReservation = 1;

            for(int i = 0; i < reservationCount; i++)
            {
                if (strcmp(users[userId].email, reservations[i].email) == 0)
                {
                    printf("\nYour Current Reservation:\n");
                    printf("Room Type: %s\n", reservations[i].roomType);
                    printf("Room Number: %s\n", reservations[i].roomNumber);
                    printf("Check-in date: %s-%s\n", reservations[i].checkInMonth, reservations[i].checkInDay);
                    printf("Check-out date: %s-%s\n", reservations[i].checkOutMonth, reservations[i].checkOutDay);
                    printf("Approximate price: %d\n", reservations[i].price);
                    printf("Downpayment(50 percent of the approximate price): %d\n", reservations[i].downpayment);

                    printf("\nIs this the reservation you want to edit?\nPress 'Y' for Yes and 'N' for No\n");
                    char pick = getch();

                if(pick == 'n' || pick == 'N')
                    {
                        continue;
                    }

                else if(pick == 'y' || pick == 'Y')
                {
                        int roomType;
                        printf("\nRESERVATION IS FOR YEAR %d ONLY!", YEAR);
                        printf("\nRoom Types:");
                        printf("\n1. Solo Room - Strictly for 1 person only. Rate: 1500 pesos per day");
                        printf("\n2. Special Solo Room - Strictly for 1 person only. Rate: 2000 pesos per day");
                        printf("\n3. Room for Two - Strictly for 2 persons only. Rate: 3000 pesos per day");
                        printf("\n4. Special Room for Two - Strictly for 2 persons only. Rate: 3500 pesos per day");
                        printf("\n5. Bedroom for Four - Strictly for 4 persons only. Rate: 5000 pesos per day");
                        printf("\nEnter the room type number: ");
                        scanf("%d", &roomType);

                        if((roomType < 1) || (roomType > 5))
                        {
                            printf("\nInvalid room type number. Please try again"); getch(); return;
                        }

                        int roomNumber;
                        printf("\nRoom Numbers:\n");
                        switch (roomType)
                        {
                            case 1:
                                printf("101, 102, 103, 104, 105\n");
                                break;
                            case 2:
                                printf("201, 202, 203, 204, 205\n");
                                break;
                            case 3:
                                printf("301, 302, 303, 304, 305\n");
                                break;
                            case 4:
                                printf("401, 402, 403, 404, 405\n");
                                break;
                            case 5:
                                printf("501, 502, 503, 504, 505\n");
                                break;
                           default:
                                printf("Invalid room type!\n");
                                getch();
                                return;
                        }
                        printf("\nEnter the new room number: ");
                        scanf("%d", &roomNumber);
                        if(roomType == 1)
                        {
                            if((roomNumber < 101) || (roomNumber > 105))
                            {
                                printf("\nInvalid room number. Please try again"); getch(); return;
                            }
                        }
                        if(roomType == 2)
                        {
                            if((roomNumber < 201) || (roomNumber > 205))
                            {
                                printf("\nInvalid room number. Please try again"); getch(); return;
                            }
                        }
                        if(roomType == 3)
                        {
                            if((roomNumber < 301) || (roomNumber > 305))
                            {
                                printf("\nInvalid room number. Please try again"); getch(); return;
                            }
                        }
                        if(roomType == 4)
                        {
                            if((roomNumber < 401) || (roomNumber > 405))
                            {
                                printf("\nInvalid room number. Please try again"); getch(); return;
                            }
                        }
                        if(roomType == 5)
                        {
                            if((roomNumber < 501) || (roomNumber > 505))
                            {
                                printf("\nInvalid room number. Please try again"); getch(); return;
                            }
                        }

                        int ciMonth, ciDay, coMonth, coDay;
                        printf("\nEnter the new Check-in Month (1-12): ");
                        scanf("%d", &ciMonth);
                        printf("\nEnter the new Check-in Day (1-28/30/31): ");
                        scanf("%d", &ciDay);
                        printf("\nEnter the new Check-out Month (1-12): ");
                        scanf("%d", &coMonth);
                        printf("\nEnter the new Check-out Day (1-28/30/31): ");
                        scanf("%d", &coDay);

                        if((ciMonth < 1) || (ciMonth > 12) || (coMonth < 1) || (coMonth > 12) || (ciMonth > coMonth))
                            {
                                printf("\nInvalid reservation date. Please try again"); getch(); return;
                            }
                        if((coMonth % ciMonth == 0) && (ciMonth != 1))
                        {
                            if((coDay < ciDay) || (coDay == ciDay))
                            {
                                printf("\nInvalid reservation date. Please try again"); getch(); return;
                            }
                        }
                        if((ciMonth == 1) || (ciMonth == 3) || (ciMonth == 5) || (ciMonth == 7) || (ciMonth == 8) || (ciMonth == 10) || (ciMonth == 12))
                        {
                            if((ciDay < 1) || (ciDay > 31))
                            {
                                printf("\nInvalid reservation date. Please try again"); getch(); return;
                            }
                        }
                        if((ciMonth == 4) || (ciMonth == 6) || (ciMonth == 9) || (ciMonth == 11))
                        {
                            if((ciDay < 1) || (ciDay > 30))
                            {
                                printf("\nInvalid reservation date. Please try again"); getch(); return;
                            }
                        }
                        if(ciMonth == 2)
                        {
                            if((ciDay < 1) || (ciDay > 28))
                            {
                                printf("\nInvalid reservation date. Please try again"); getch(); return;
                            }
                        }
                        if((coMonth == 1) || (coMonth == 3) || (coMonth == 5) || (coMonth == 7) || (coMonth == 8) || (coMonth == 10) || (coMonth == 12))
                        {
                            if((coDay < 1) || (coDay > 31))
                            {
                                printf("\nInvalid reservation date. Please try again"); getch(); return;
                            }
                        }
                        if((coMonth == 4) || (coMonth == 6) || (coMonth == 9) || (coMonth == 11))
                        {
                            if((coDay < 1) || (coDay > 30))
                            {
                                printf("\nInvalid reservation date. Please try again"); getch(); return;
                            }
                        }
                        if(coMonth == 2)
                        {
                            if((coDay < 1) || (coDay > 28))
                            {
                                printf("\nInvalid reservation date. Please try again"); getch(); return;
                            }
                        }

                        // Check if the room is already reserved
                        for (int i = 0; i < reservationCount; i++)
                            {
                                if ((roomType == 1) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkInMonth) == ciMonth) && (atoi(reservations[i].checkOutMonth) == coMonth)) &&
                                ((atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= ciDay) ||
                                (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= coDay) ||
                                (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkInDay) <= coDay) ||
                                (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkInDay) <= coDay)  ||
                                (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkOutDay) <= ciDay)) ||
                                ((roomType == 1) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkOutMonth) == ciMonth) && (atoi(reservations[i].checkInMonth) < coMonth) && (atoi(reservations[i].checkOutDay) >= ciDay))) ||
                                ((roomType == 1) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkInMonth) == coMonth) && (atoi(reservations[i].checkInMonth) > ciMonth) && (atoi(reservations[i].checkInDay) <= coDay))))
                                {
                                    system("cls");
                                    printf("\nRoom is already reserved!\n");
                                    printf("\nPlease try another room or date!\n");
                                    printf("\nPress any key to continue...\n");
                                    getch();
                                    return;
                                }

                               if ((roomType == 2) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkInMonth) == ciMonth) && (atoi(reservations[i].checkOutMonth) == coMonth)) &&
                                ((atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= ciDay) ||
                                (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= coDay) ||
                                (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkInDay) <= coDay) ||
                                (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkInDay) <= coDay)  ||
                                (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkOutDay) <= ciDay)) ||
                                ((roomType == 2) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkOutMonth) == ciMonth) && (atoi(reservations[i].checkInMonth) < coMonth) && (atoi(reservations[i].checkOutDay) >= ciDay))) ||
                                ((roomType == 2) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkInMonth) == coMonth) && (atoi(reservations[i].checkInMonth) > ciMonth) && (atoi(reservations[i].checkInDay) <= coDay))))
                                {
                                    system("cls");
                                    printf("\nRoom is already reserved!\n");
                                    printf("\nPlease try another room or date!\n");
                                    printf("\nPress any key to continue...\n");
                                    getch();
                                    return;
                                }

                                if ((roomType == 3) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkInMonth) == ciMonth) && (atoi(reservations[i].checkOutMonth) == coMonth)) &&
                                ((atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= ciDay) ||
                                (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= coDay) ||
                                (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkInDay) <= coDay) ||
                                (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkInDay) <= coDay)  ||
                                (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkOutDay) <= ciDay)) ||
                                ((roomType == 3) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkOutMonth) == ciMonth) && (atoi(reservations[i].checkInMonth) < coMonth) && (atoi(reservations[i].checkOutDay) >= ciDay))) ||
                                ((roomType == 3) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkInMonth) == coMonth) && (atoi(reservations[i].checkInMonth) > ciMonth) && (atoi(reservations[i].checkInDay) <= coDay))))
                                {
                                    system("cls");
                                    printf("\nRoom is already reserved!\n");
                                    printf("\nPlease try another room or date!\n");
                                    printf("\nPress any key to continue...\n");
                                    getch();
                                    return;
                                }

                                if ((roomType == 4) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkInMonth) == ciMonth) && (atoi(reservations[i].checkOutMonth) == coMonth)) &&
                                ((atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= ciDay) ||
                                (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= coDay) ||
                                (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkInDay) <= coDay) ||
                                (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkInDay) <= coDay)  ||
                                (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkOutDay) <= ciDay)) ||
                                ((roomType == 4) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkOutMonth) == ciMonth) && (atoi(reservations[i].checkInMonth) < coMonth) && (atoi(reservations[i].checkOutDay) >= ciDay))) ||
                                ((roomType == 4) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkInMonth) == coMonth) && (atoi(reservations[i].checkInMonth) > ciMonth) && (atoi(reservations[i].checkInDay) <= coDay))))
                                {
                                    system("cls");
                                    printf("\nRoom is already reserved!\n");
                                    printf("\nPlease try another room or date!\n");
                                    printf("\nPress any key to continue...\n");
                                    getch();
                                    return;
                                }

                                if ((roomType == 5) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkInMonth) == ciMonth) && (atoi(reservations[i].checkOutMonth) == coMonth)) &&
                                ((atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= ciDay) ||
                                (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkOutDay) <= coDay) ||
                                (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkInDay) <= coDay) ||
                                (atoi(reservations[i].checkInDay) >= ciDay) && (atoi(reservations[i].checkInDay) <= coDay)  ||
                                (atoi(reservations[i].checkOutDay) >= coDay) && (atoi(reservations[i].checkOutDay) <= ciDay)) ||
                                ((roomType == 5) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkOutMonth) == ciMonth) && (atoi(reservations[i].checkInMonth) < coMonth) && (atoi(reservations[i].checkOutDay) >= ciDay))) ||
                                ((roomType == 5) && (atoi(reservations[i].roomNumber) == roomNumber) &&
                                ((atoi(reservations[i].checkInMonth) == coMonth) && (atoi(reservations[i].checkInMonth) > ciMonth) && (atoi(reservations[i].checkInDay) <= coDay))))
                                {
                                    system("cls");
                                    printf("\nRoom is already reserved!\n");
                                    printf("\nPlease try another room or date!\n");
                                    printf("\nPress any key to continue...\n");
                                    getch();
                                    return;
                                }
                        }
                            // Update the reservation
                            switch (roomType)
                            {
                                case 1:
                                    strcpy(reservations[i].roomType, "Solo_Room");
                                    break;
                                case 2:
                                    strcpy(reservations[i].roomType, "Special_Solo_Room");
                                    break;
                                case 3:
                                    strcpy(reservations[i].roomType, "Room_for_Two");
                                    break;
                                case 4:
                                    strcpy(reservations[i].roomType, "Special_Room_for_Two");
                                    break;
                                case 5:
                                    strcpy(reservations[i].roomType, "Bedroom_for_Four");
                                    break;
                            }
                            sprintf(reservations[i].roomNumber, "%d", roomNumber);
                            sprintf(reservations[i].checkInMonth, "%d", ciMonth);
                            sprintf(reservations[i].checkInDay, "%d", ciDay);
                            sprintf(reservations[i].checkOutMonth, "%d", coMonth);
                            sprintf(reservations[i].checkOutDay, "%d", coDay);

                            int duration = 0;
                            duration = daysStay(ciMonth, ciDay, coMonth, coDay);

                            reservations[i].price = 0;
                            switch (roomType)
                            {
                                case 1:
                                    reservations[i].price = 1500 * duration;
                                    break;
                                case 2:
                                    reservations[i].price = 2000 * duration;
                                    break;
                                case 3:
                                    reservations[i].price = 3000 * duration;
                                    break;
                                case 4:
                                    reservations[i].price = 3500 * duration;
                                    break;
                                case 5:
                                    reservations[i].price = 5000 * duration;
                                    break;
                            }
                            reservations[i].downpayment = reservations[i].price * .5;

                            printf("\nYour Reservation Details:\n");
                            printf("Room Type: %s\n", reservations[i].roomType);
                            printf("Room Number: %s\n", reservations[i].roomNumber);
                            printf("Check-in date: %s-%s\n", reservations[i].checkInMonth, reservations[i].checkInDay);
                            printf("Check-out date: %s-%s\n", reservations[i].checkOutMonth, reservations[i].checkOutDay);
                            printf("Approximate price: %d\n", reservations[i].price);
                            printf("Downpayment to settle (50 percent of the approximate price): %d\n", reservations[i].downpayment);

                            printf("\nDownpayment should be settled within 7 working days for the reservation to be valid or it will be canceled.");
                            printf("\nThe payment method for the downpayment will be in pesos whether GCash, Maya, Paypal, or Bank Transaction will be sent to your email upon confirming the reservation.\n");
                            printf("\nIf the edited reservation has a higher downpayment than the first one, another payment method will be sent to your email. Otherwise, the excess payment will be refunded.\n");

                            printf("\nDo you still want to continue the reservation? \n(Press 'Y' for Yes and 'N' for No)\n");
                            char sure = getch();

                            if(sure == 'y' || sure == 'Y')
                            {
                                saveReservationsToFile();
                                printf("\nReservation edited successfully!\n");
                                printf("\nPress any key to continue...");
                                getch(); return;
                            }
                            else if(sure == 'n' || sure == 'N')
                            {
                                printf("\nReservation is not edited successfully!\n");
                                printf("\nPress any key to continue...");
                                getch(); return;
                            }
                    }
                    }
                }
            }
        }

    if (!foundReservation)
        {
            system("cls");
            printf("\nNo reservation found!\n");
            printf("\nPress any key to continue...");
            getch();
        }
}

//Function to Cancel Reservation
void cancelReservation(int userId)
{
    system("cls");
    printf("-- Cancel Reservation --\n");
    printf("\nCanceling a reservation 2 weeks before the Check-In date will have a cancellation fee worth 20 percent of your downpayment to be deducted to your settled downpayment.\n");

    printf("\nReservation Email: %s\n", users[userId].email);

    int foundReservation = 0;

    // Find the reservation
    for (int j = 0; j < reservationCount; j++)
    {
        if (strcmp(users[userId].email, reservations[j].email) == 0)
        {
            foundReservation = 1;

            for(int i = 0; i < reservationCount; i++)
            {
                if (strcmp(users[userId].email, reservations[i].email) == 0)
                {
                printf("\nYour Current Reservation:\n");
                printf("Room Type: %s\n", reservations[i].roomType);
                printf("Room Number: %s\n", reservations[i].roomNumber);
                printf("Check-in date: %s-%s\n", reservations[i].checkInMonth, reservations[i].checkInDay);
                printf("Check-out date: %s-%s\n", reservations[i].checkOutMonth, reservations[i].checkOutDay);
                printf("Approximate price: %d\n", reservations[i].price);
                printf("Downpayment(50 percent of the approximate price): %d\n", reservations[i].downpayment);

                printf("\nIs this the reservation you want to cancel?\nPress 'Y' for Yes and 'N' for No\n");
                char pick = getch();

                    if(pick == 'n' || pick == 'N')
                        {
                            continue;
                        }

                    else if(pick == 'y' || pick == 'Y')
                    {
                        printf("\nDo you really want to cancel your reservation?\nPress 'Y' for Yes and 'N' for No.\n\t");
                        char sure = getch();
                        if(sure == 'y'|| sure == 'Y')
                        {
                            strcpy(reservations[i].roomType, "canceled");
                            strcpy(reservations[i].roomNumber, "canceled");
                            strcpy(reservations[i].checkInMonth, "");
                            strcpy(reservations[i].checkInDay, "");
                            strcpy(reservations[i].checkOutMonth, "");
                            strcpy(reservations[i].checkOutDay, "");
                            reservations[i].price = 0;
                            reservations[i].downpayment = 0;

                            saveReservationsToFile();

                            printf("\nReservation canceled successfully!\n");
                            printf("\nRefund will be sent back to your account if you already paid the canceled reservation.");
                            printf("\nIf you are canceling this reservation 2 weeks before the Check-In date the cancellation fee will be deducted\n");
                            printf("\nPress any key to continue...");
                            getch(); return;
                        }
                        else if(sure == 'n' || sure == 'N')
                        {
                            printf("\nWe'll be looking forward for your visit. Thank you!"); getch(); return;
                        }
                    }
                }
                }
            }
        }


    if (!foundReservation)
        {
            system("cls");
            printf("\nNo reservation found!\n");
            printf("\nPress any key to continue...");
            getch();
        }
}

//Function to find duration of the stay
int daysStay(int checkinMonth, int checkinDay, int checkoutMonth, int checkoutDay)
{
    int day = 0, tempday = 0, tempmonth = 0;
    if((checkoutMonth % checkinMonth == 0) && (checkinMonth != 1))
    {
        day = checkoutDay - checkinDay;
        return day;
    }
    else
    {
        if((checkinMonth == 1) || (checkinMonth == 3) || (checkinMonth == 5) || (checkinMonth == 7) || (checkinMonth == 8) || (checkinMonth == 10) || (checkinMonth == 12))
        {
            tempday = 31 - checkinDay;
            day = checkoutDay + tempday;
            return day;
        }
        else if((checkinMonth == 4) || (checkinMonth == 6) || (checkinMonth == 9) || (checkinMonth == 11))
        {
            tempday = 30 - checkinDay;
            day = checkoutDay + tempday;
            return day;
        }
        else if(checkinMonth == 2)
        {
            tempday = 28 - checkinDay;
            day = checkoutDay + tempday;
            return day;
        }
    }
}

// Function to display amenities
void displayAmenities()
{
    system("cls");
    printf("If you have already checked into our hotel, here are the facilities/amenities you will enjoy!\n");
    printf("\nFacilities/Amenities:\n");
    printf("1. Pool - Relax and cool off in our refreshing swimming pool. Located at the Ground floor of the building.\n");
    printf("2. Gym - Stay fit and healthy with our well-equipped fitness center. Located at the 2nd floor of the building.\n");
    printf("3. Game Room - Have fun with various games and entertainment options. Located at the 3rd floor of the building.\n");
    printf("4. Study Area - Quiet and comfortable space for studying or working. Located at the 4th floor of the building.\n");
    printf("5. TUP Restaurant - Eat delicious and healthy food just inside the hotel. Located at the Ground Floor of the building.\n");
    printf("6. Free Wifi - Stay connected with complimentary high-speed internet access. Accessible throughout the whole building.\n");
    printf("7. All rooms are equipped with Smart Television with Netflix and YouTube.\n");
    printf("8. All rooms have free hygienic kits upon check-in.\n");
    printf("9. Special rooms have a minibar/fridge and bathtubs that sets it apart from other rooms.");
}

// Function to display reviews
void displayReviews()
{
    system("cls");
    printf("In here, I hope you might find the reviews helpful!\n");
    printf("\nHotel and Staff Reviews:\n");
    // Generate and display usernames and reviews
    char usernames[8][20] = {"Spongebob_SP", "PatrickSTAR", "SquidWard_Tt", "E.H_Krabs", "Sheldon_H_Plankton", "Karen_PT", "Sandy_C", "MRS.Puff"};
    char reviews[8][200] = {
        "Great hotel! The staff was friendly and helpful throughout my stay.",
        "I loved the amenities and the comfortable rooms. Highly recommended!",
        "The hotel exceeded my expectations. The service was exceptional.",
        "Clean and spacious rooms. The staff went above and beyond to make me feel welcome.",
        "I had a wonderful experience at this hotel. The location is convenient and the staff is amazing.",
        "I really enjoyed my stay. The facilities are top-notch and the staff is attentive and friendly.",
        "Impressed with the professionalism and courtesy of the hotel staff. Will definitely stay here again.",
        "The hotel provided excellent service. The rooms were clean and well-maintained."
    };

    for (int i = 0; i < 8; i++) {
        printf("%d. %s: %s\n", i + 1, usernames[i], reviews[i]);
    };
}

// Function to display landmarks
void displayLandmarks()
{
    system("cls");
    printf("Here are some of the landmarks near the TUP hotel that are helpful and easy to find\n");
    printf("\nLandmarks near TUP Hotel:\n");
    // Display landmarks near TUP Hotel
    char landmarks[8][300] = {
        "SM Supermarket - 3km North to the hotel",
        "Robinson Supermarket - 2km West to the hotel",
        "New Kelp Park - 6km East to the hotel",
        "Bass Vegas Casino - 5km South to the hotel",
        "Chum Bucket Train Station - 3km South-East to the hotel",
        "Bikini Bottom Bus Terminal - 3km North-East to the hotel",
        "Atlantis Resort - 2km North-West to the hotel",
        "Bubbletown Airport - 7km South-West to the hotel"
    };

    for (int i = 0; i < 8; i++) {
        printf("%d. %s\n", i + 1, landmarks[i]);
    };
}


// Function to display FAQs
void displayFAQs()
{
    system("cls");
    printf("Here are the most frequently asked questions that might be helpful before you check in.\n");
    printf("\nFrequently Asked Questions:\n");
    // Display questions with answers
    char questions[9][100] = {
        "Is there a downpayment upon making a reservation?\n",
        "Is parking available at the hotel?\n",
        "What are the check-in and check-out timings?\n",
        "Are pets allowed in the hotel?\n",
        "Does the hotel have a restaurant?\n",
        "Is room service available?\n",
        "Are there any nearby shopping malls?\n",
        "Do the rooms have a minibar?\n",
        "Is airport transportation provided by the hotel?\n"
    };

    char answers[9][200] = {
        "Yes, downpayment worth of 50 percent of the approximate price of your reservation is needed to be settled when making a reservation.\n",
        "Yes, parking facilities are available for guests.\n",
        "The check-in time is at 2:00 PM and the check-out time is at 12:00 PM.\n",
        "Unfortunately, pets are not allowed in the hotel.\n",
        "Yes, the hotel has a restaurant that serves a variety of cuisines.\n",
        "Yes, room service is available 24/7 for your convenience.\n",
        "There are several shopping malls within a 4-km radius of the hotel.\n",
        "Yes, the rooms are equipped with a minibar for your enjoyment.\n",
        "Yes, airport transportation can be arranged upon request. Please contact the hotel for more information\n"
    };

    for (int i = 0; i < 9; i++) {
        printf("%d. %s: %s\n", i + 1, questions[i], answers[i]);
    };
}

void viewAllReservation()
{
    system("cls");
    printf("----- TUP Hotel Reservations -----\n");
    printf("\nTotal Reservations: %d\n", reservationCount);
    printf("This includes canceled reservations.\n");

    printf("\nThe following are the current reservations:\n");

    for(int i = 0; i < reservationCount; i++)
    {
        printf("\nEmail: %s\n", reservations[i].email);
        printf("Room Type: %s\n", reservations[i].roomType);
        printf("Room Number: %s\n", reservations[i].roomNumber);
        printf("Check-in date: %s-%s\n", reservations[i].checkInMonth, reservations[i].checkInDay);
        printf("Check-out date: %s-%s\n", reservations[i].checkOutMonth, reservations[i].checkOutDay);
        printf("Approximate price: %d\n", reservations[i].price);
        printf("Downpayment(50 percent of the approximate price): %d\n", reservations[i].downpayment);
    }
    getch(); return;

}

void displayRevenue()
{
    int totalPrice = 0;
    int totalDownpayment = 0;
    system("cls");

    for(int i = 0; i < reservationCount; i++)
    {
        totalPrice += reservations[i].price;
        totalDownpayment += reservations[i].downpayment;
    }

    printf("----- TUP Hotel Reservations -----\n");
    printf("\nProjected Total Sales/Revenue: %d pesos\n", totalPrice);
    printf("\nProjected Total Downpayment (Primary Payments): %d pesos\n", totalDownpayment);
    printf("\n\nThis projected total revenue is for the current reservations only.");

    getch(); return;
}

void loading()
{
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t TUP HOTEL RESERVATION");
    printf("\n\n\t\t\t\t\tLoading.... please wait\n\n");
    for(int i = 1; i<=120; i++)
    {
        Sleep(5);
        printf("%c", 219);
    }
    printf("\n\n\t\t\t\t      Successfully Loaded. Welcome!");
}

void delay(unsigned int secs)
{
    clock_t interval = clock() + secs;
    while(interval > clock());
}

void displayFirstMenu()
{
    system("cls");
    printf("---------- TUP Hotel Management Menu ----------\n");
    printf("1. Login\n");
    printf("2. Sign Up\n");
    printf("0. Exit\n");
    printf("-----------------------------------------------\n");
    printf("\nEnter your choice: ");
}

void displaySecondMenu()
{
    system("cls");
    printf("---------- TUP Hotel Management Menu ----------\n");
    printf("1. Make Reservation\n");
    printf("2. Edit Reservation\n");
    printf("3. Cancel Reservation\n");
    printf("4. Display Facilities/Amenities of the Hotel\n");
    printf("5. Display Hotel and Staff Reviews\n");
    printf("6. Display Landmarks near the Hotel\n");
    printf("7. Display FAQ/s\n");
    printf("8. Log-Out\n");
    printf("0. Exit\n");
    printf("-----------------------------------------------\n");
    printf("\nEnter your choice: ");
}

void displayThirdMenu()
{
    system("cls");
    printf("---------- TUP Hotel Management Admin Menu ----------\n");
    printf("1. View All Reservations\n");
    printf("2. Compute Approximate Total Revenue of Reservations and Downpayments\n");
    printf("3. Log-Out\n");
    printf("0. Exit\n");
    printf("-----------------------------------------------\n");
    printf("\nEnter your choice: ");
}


int mainmenu()
{
    char choice;

    do
    {
        displayFirstMenu();
        scanf("%s", &choice);

        switch (choice)
        {
        case '1':
            userId = login();
            if ((userId != -1) && (userId <= MAX_USERS ))
                {
                    system("cls");
                    printf("Logging in..... Please wait...."); delay(2000);
                    system("cls");
                    printf("\nLogin successful!\n"); delay(2000);

                    do
                    {
                        displaySecondMenu();
                        scanf("%s", &choice);

                        switch (choice)
                        {
                        case '1':
                            makeReservation(userId); break;
                        case '2':
                            editReservation(userId); break;
                        case '3':
                            cancelReservation(userId); break;
                        case '4':
                            displayAmenities(); getch(); break;
                        case '5':
                            displayReviews(); getch(); break;
                        case '6':
                            displayLandmarks(); getch(); break;
                        case '7':
                            displayFAQs(); getch(); break;
                        case '8':
                            system("cls");
                            printf("Logging out..... Please wait...."); delay(2000);
                            mainmenu(); break;
                        case '0':
                            printf("\nExiting...\n"); delay(2000);
                            printf("\nThank you. Hope to see you soon at TUP Hotel\n");
                            exit(0);
                        default:
                            printf("Invalid choice!\n");
                            printf("\nPress any key to continue...");
                            getch();
                        }
                    } while (choice != '0');
                    break;
                }

            else if(userId == MAX_USERS+1)
            {
                system("cls");
                printf("Logging in..... Please wait...."); delay(2000);
                system("cls");
                printf("\nLogin successful!\n"); delay(2000);

                do
                {
                    displayThirdMenu();
                    scanf("%s", &choice);

                    switch (choice)
                    {
                    case '1':
                        viewAllReservation(); break;
                    case '2':
                        displayRevenue(); break;
                    case '3':
                        system("cls");
                        printf("Logging out..... Please wait...."); delay(2000);
                        mainmenu(); break;
                    case '0':
                        printf("\nExiting...\n"); delay(2000);
                        printf("\nThank you. Hope to see you soon at TUP Hotel\n");
                        exit(0);
                    default:
                        printf("Invalid choice!\n");
                        printf("\nPress any key to continue...");
                        getch();
                    }
                } while (choice != '0');
            break;
            }

            else if(userId == -1)
                {
                    system("cls");
                    printf("Logging in..... Please wait...."); delay(2000);
                    printf("\n\nInvalid email or password!\n");
                    printf("\nPlease try again.\n");
                    printf("\nPress any key to continue...");
                    getch();
                }
                break;
        case '2':
            signUp();
            break;
        case '0':
            printf("\nExiting...\n"); delay(2000);
            printf("\nThank you. Hope to see you soon at TUP Hotel\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
            printf("\nPress any key to continue...");
            getch();
        }
    } while (choice != '0');
}

int main()
{
    loadUsersFromFile();
    loadReservationsFromFile();

    loading();
    delay(3000);
    mainmenu();
}
