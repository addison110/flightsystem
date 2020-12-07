
/*
Title: Flight Management System
Desc: This program contains information about flights and lets users book flights
Name: Addison Wenzel, Zac Chen, Andy Lin, Chris DeMuyt, Evan Michael Harding
Email: wenzela@purdue.edu, lin1019@purdue.edu, chen2946@purdue.edu, cdemuyt@purdue.edu, hardine@purdue.edu
*/

#define _GNU_SOURCE /* for tm_gmtoff and tm_zone */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void header()
{
    printf("\nFlight               [Price]   [Seating Capacity]    [Available Seats]\n");
}
void option1() //One way trip Aug 10
{
    printf("\nFlight                              [Price]   [Seating Capacity]    [Available Seats]\n");
    printf("1. West Lafayette To Indianapolis      50        10                     6\n");
    printf("2. West Lafayette To New York          200       75                     0\n");
    printf("3. West Lafayette To Atlanta           300       100                    24\n");
}
void option2() //One way trip Aug 11
{
    printf("\nFlight                              [Price]   [Seating Capacity]    [Available Seats]\n");
    printf("4. West Lafayette To Indianapolis      60        10                    8\n");
    printf("5. West Lafayette To New York          200       15                    14\n");
    printf("6. West Lafayette To Atlanta           400       30                    15\n");
}
void option3() //One way trip Aug 12
{
    printf("\nFlight                              [Price]   [Seating Capacity]    [Available Seats]\n");
    printf("7. West Lafayette To Indianapolis       70       10                    7\n");
    printf("8. West Lafayette To New York           150      75                    16\n");
    printf("9. West Lafayette To Atlanta            500      60                    35\n");
}
struct flight{
    int ticket;
    int price;
};
int main() {
    struct flight book[10]; //Creates Flight Structure
    char user[50], pw[50], adminu[50]="John", adminpw[50]="Doe"; //Username and password
    int trip; //Option 1 for  round trip option 2 for one way
    int date; //Date of trip (Aug 10, 11, 12)
    int date2; //Return date
    int a; //Loop variable
    int x; //Number of tickets
    int y;
    float total = 0.0; //Total price of ticket
    char repeat;
    int choice; //If user wants to continue
    int loggedin = 0; //Changes if the user has already logged in

    //API for the time
    char buffer[150];
    time_t curtime;
    struct tm *loctime;
    curtime = time(NULL);
    loctime = localtime(&curtime);
    fputs (asctime (loctime),stdout);
    time_t t = times(NULL);
    struct tm lt = {0};
    localtime_r(&t, &lt);

    int i = 1; //Loop variable
    while(i == 1){ //Big loop
	if (loggedin == 0)
	{
		//Prompts user to enter login info
	        printf("---------- [Flight Management System] ----------\n");
        	printf("                  User Login\n");
	        printf("\nEnter Username: ");
        	scanf("%s", &user);
	        printf("\nEnter Password: ");
       		scanf("%s", &pw);
        	printf("\n----------                            ----------\n");
	}
	//checks if user entered correct login or has previously logged in
        if ((strcmp(user, adminu)==0 && strcmp(pw, adminpw)==0 )|| loggedin == 1)
        {
            printf("            Welcome, %s", &user);
	    loggedin = 1; //records that the user has previously logged in
            //Validating that user input is valid between numbers 1-2
            do {
            printf("\nPlease select one of the follow choices: ");
            printf("\n1. One way trip \n\n2. Roundtrip\n\n");
            scanf("\n%d", &trip);
              if (trip < 1 || trip > 2)
              {
                printf("\n1. One way trip \n\n2. Roundtrip\n\n");
                printf("Invalid Entry- Please Enter 1 Or 2");
              }
            }while (trip < 1 || trip > 2);

            //Validating that user input is valid between numbers 1-3
            do {
            printf("----------                          ----------");
            printf("\nSelect one of the corresponding date listed below:\n ");
            printf("\n1. August 10, 2021 \n2. August 11, 2021\n3. August 12, 2021\n");
            scanf("%d", &date);
            if (date < 1 || date > 3)
              {
                  printf("\nInvalid Entry- Please Enter 1, 2 or 3:\n");
                  scanf("%d", &date);
              }
            } while (date < 1 || date > 3);

            switch (trip) //Round trip or one way trip
            {
            case 1: //One way trip
            {
                if (date==1) //One way trip date: Aug 10
                {
                    printf("\nAugust 10, 2021\n");
                    option1(); //Displays flight info for Aug 10
                    do {//Making sure an individual does place more than 10 tickets at once 
                     {
                      printf("\nRestriction: Max of 10 Tickets may be placed at once\n");
                      printf("\nHow many tickets will you get? (0-10): ");
                      scanf("%d", &x);
                     }
                    } while (x > 10);
		    //Loops for each ticket
                    for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                  
                        do // Validating that user is inputting the correct value between 1 to 3
                        {
                          if (book[a].ticket < 1 || book[a].ticket > 3)
                          {
                          printf("\nPlease Select Choices 1, 2, or 3: ");
                           scanf("%d", &book[a].ticket); 
                          }
                        } while (book[a].ticket < 1 || book[a].ticket > 3);
                    }
                }
                else if (date==2) //one way trip date: Aug 11
                {
                printf("\nAugust 11, 2021\n");
                option2(); //shows flight data
                 do {//Making sure an individual does place more than 10 tickets at once 
                     {
                      printf("\nRestriction: Max of 10 Tickets may be placed at once\n");
                      printf("\nHow many tickets will you get? (0-10): ");
                      scanf("%d", &x);
                     }
                    } while (x > 10);

		    //Loops for each ticket
                for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                  
                         do // Validating that user is inputting the correct value between 4 to 6
                        {
                          if (book[a].ticket < 1 || book[a].ticket > 3)
                          {
                          printf("\nPlease Select Choices 4, 5, or 6: ");
                           scanf("%d", &book[a].ticket); 
                          }
                        } while (book[a].ticket < 4 || book[a].ticket > 6);
                        
                    }
                }
                else if (date==3) //One way trip date: Aug 12
                {
                    printf("\nAugust 12, 2021\n");
                    option3(); //Prints fight data
                    do {//Making sure an individual does place more than 10 tickets at once 
                    {
                     	printf("\nRestriction: Max of 10 Tickets may be placed at once\n");
                    	printf("\nHow many tickets will you get? (0-10): ");
                     	scanf("%d", &x);
                    }
                    } while (x > 10);

		    //Loops for each ticket
                    for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                       
                         do // Validating that user is inputting the correct value between 7 to 9
                        {
                          if (book[a].ticket < 1 || book[a].ticket > 3)
                          {
                          printf("\nPlease Select Choices 7, 8, or 9: ");
                           scanf("%d", &book[a].ticket); 
                          }
                        } while (book[a].ticket < 7 || book[a].ticket > 9);
                    }
                }
                else printf("\nInvalid"); //Invalid choice
                break;
            }
            case 2: //Round trip
                {
                if (date==1) //Round trip date: Aug 10
                {
                    printf("\nAugust 10, 2021\n");
                    option1();
                    do// Validating that the user can only select the corresponding options of 1 or 2
                    {
                      printf("\nInvalid Entry- Please select date 1 or 2\n");
                      printf("\nChoose date of return: \n1. August 11, 2021\n2. August 12, 2021\n");
                      scanf("%d", &date2);
                    } while (date2 < 1 || date2 > 2);
                    do // Making sure an individual can only place 20 tickets
                  {
                    printf("\nRestriction: Max of 20 Tickets may be placed\n");
                    printf("\nHow many tickets will you get? (0-20) (excluding the return trip): ");
                    scanf("%d", &x); 
                  } while (x > 20);

		    //Loop for amount of tickets
                    for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                       
                         do // Validating that user is inputting the correct value between 1 and 3
                        {
                          if (book[a].ticket < 1 || book[a].ticket > 3)
                          {
                          printf("\nPlease Select Choices 1, 2, or 3: ");
                           scanf("%d", &book[a].ticket); 
                          }
                        } while (book[a].ticket < 1 || book[a].ticket > 3);
                        if (date2==1) //Round trip return date: Aug 11
                        {
                        switch (book[a].ticket)
                        {
                            case 1:
                            {
                                printf("\nDetails for return trip");
                                header();
                                printf("Indianapolis To West Lafayette     2,000   100         45\n"); break;
                            }
                            case 2:
                            {
                                printf("\nDetails for return trip");
                                header();
                                printf("New York To West Lafayette      1,500   75          67\n"); break;
                            }
                            case 3:
                            {
                                printf("\nDetails for return trip");
                                header();
                                printf("Atlanta To West Lafayette     4,000   100         46\n"); break;
                            }
                            default: break;
                        }
                        }
                        else if (date2==2) //Return date round trip: Aug 12
                        {
                            switch (book[a].ticket)
                        {
                            case 1:
                            {
                                header();
                                printf("\nIndianapolis To West Lafayette       2,000   100         45"); break;
                            }
                            case 2:
                            {
                                header();
                                printf("\nNew York To West Lafayette        1,500   75          67"); break;
                            }
                            case 3:
                            {
                                header();
                                printf("\nAtlanta To West Lafayette       4,000   100         46"); break;
                            }
                            default: break;
                        }
                        }
                        else //Invalid round trip return date
                        {
                        printf("\nInvalid");
                        return 0;
                        }
                    }
                }
                else if (date==2) //Round trip date: Aug 11
                {
                printf("\nAugust 11, 2021\n");
                option2();
                do // Making sure an individual can only place 20 tickets
                  {
                    printf("\nRestriction: Max of 20 Tickets may be placed\n");
                    printf("\nHow many tickets will you get? (0-20): ");
                    scanf("%d", &x); 
                  } while (x > 20);

                for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                   
                         do // Validating that user is inputting the correct value between 4 to 6
                        {
                          if (book[a].ticket < 1 || book[a].ticket > 3)
                          {
                          printf("\nPlease Select Choices 4, 5, or 6: ");
                           scanf("%d", &book[a].ticket); 
                          }
                        } while (book[a].ticket < 4 || book[a].ticket > 6);
                    }
                }
                else if (date==3) //Round trip date: Aug 12
                {
                    printf("\nAugust 12, 2021\n");
                    option3();
                    do // Making sure an individual can only place 20 tickets
                  {
                    printf("\nRestriction: Max of 20 Tickets may be placed\n");
                    printf("\nHow many tickets will you get? (0-20): ");
                    scanf("%d", &x); 
                  } while (x > 20);

                    for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
          
                        do // Validating that user is inputting the correct value between 7 to 9
                        {
                          if (book[a].ticket < 1 || book[a].ticket > 3)
                          {
                          printf("\nPlease Select Choices 7, 8, or 9: ");
                           scanf("%d", &book[a].ticket); 
                          }
                        } while (book[a].ticket < 7 || book[a].ticket > 9);
                    }
                }
                else printf("\nInvalid"); //Invalid round trip date
                break;
                    break;
                }
                default:
                 break;
            }
	    //Summary output
            printf("\n****************************************************");
            printf("\nSummary: ");
            for (a=1; a<=x; a++)
            {
            printf("\nDetails of Ticket no. [%d]", a);
            printf("\nFlight no. [%d]\n", book[a].ticket);
            printf("\n****************************************************");

	    //Adding up the price based on the flight number
	    if (book[a].ticket == 1)
	    	total = total + 50;
	    else if (book[a].ticket == 2)
		total = total + 200;
	    else if (book[a].ticket == 3)
		total = total + 300;
	    else if (book[a].ticket == 4)
		total = total + 60;
            else if (book[a].ticket == 5)
                total = total + 200;
            else if (book[a].ticket == 6)
                total = total + 400;
            else if (book[a].ticket == 7)
                total = total + 70;
            else if (book[a].ticket == 8)
                total = total + 150;
            else if (book[a].ticket == 9)
                total = total + 500;
	    }
            printf("\nTotal number of tickets: %d\n", x);
            printf("\nTotal Price: $%0.2f \n", total);
	    //Outputtubg time from api
	    strftime (buffer, 150, "\nToday is %A, %B %d.\n", loctime);
            fputs (buffer, stdout);
            strftime (buffer, 150, "The time of ticket purchase is %I:%M %p.\n", loctime);
            fputs (buffer, stdout);
	    printf("Offset to GMT is %lds.\n", lt.tm_gmtoff);
            printf("The time zone is '%s'.\n", lt.tm_zone);

	    //Asking user if they want to keep running the program
	    printf("\n--------------------------------------------------------------------");
	    printf("\nWould you like to keep running the program? (1 for Yes | 0 for No): ");
	    scanf("%d", &choice);
	    if (choice == 0){ //Exits the program
	    	exit(1);
	    }
	    total = 0;
        }
        else
        {
        printf("\nInvalid login, please try again\n\n");
        }
    }
    return 0;
}
