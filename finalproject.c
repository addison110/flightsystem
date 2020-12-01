/*
Title: Flight Management system (How long until you see my comment? -Evan)
Desc: This program contains information about flights and lets users book flights
Name: Addison Wenzel, Zac Chen, Andy Lin, Chris DeMuyt, Evan Michael Harding
Email: wenzela@purdue.edu, lin1019@purdue.edu, chen2946@purdue.edu, cdemuyt@purdue.edu, hardine@purdue.edu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void header()
{
    printf("\nFlight                Price   Seating Capacity    Available Seats\n");
}
void option1() //one way trip aug 10
{
    printf("\nFlight                               Price   Seating Capacity    Available Seats\n");
    printf("1. West Lafayette To Indianapolis      50      10          6\n");
    printf("2. West Lafayette To New York          200     75          0\n");
    printf("3. West Lafayette To Atlanta           300     100         24\n");
}
void option2() //one way trip aug 11
{
    printf("\nFlight                               Price   Seating Capacity    Available Seats\n");
    printf("4. West Lafayette To Indianapolis      60       10          8\n");
    printf("5. West Lafayette To New York          200      15          14\n");
    printf("6. West Lafayette To Atlanta           400      30          15\n");
}
void option3() //one way trip aug 12
{
    printf("\nFlight                              Price   Seating Capacity    Available Seats\n");
    printf("7. West Lafayette To Indianapolis       70      10          7\n");
    printf("8. West Lafayette To New York           150     75          16\n");
    printf("9. West Lafayette To Atlanta            500     60          35\n");
}
struct flight{
    int ticket;
    int price;
};
int main() {
    struct flight book[10]; //creates flight
    char user[50], pw[50], adminu[50]="jon", adminpw[50]="snow"; //username and password
    int trip; //1. round trip or 2. one way
    int date; //date of trip (aug 10, 11, 12)
    int date2; //return date
    int a;
    int x; //number of tickets
    int y;
    float total = 0; //total price of ticket
    char repeat;
    int choice; //if user wants to continue
	
	//TIME USAGE
	
	time_t current_time;
    char* c_time_string;

    /* Obtain current time. */
    current_time = time(NULL);

    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }
	
	
    int i = 1; //loop variable
    while(i == 1){ //big loop
        //prompts user to enter login info
        printf("\nEnter username: ");
        scanf("%s", &user);
        printf("\nEnter password: ");
        scanf("%s", &pw);
        //checks if username and password are valid
        if (strcmp(user, adminu)==0 && strcmp(pw, adminpw)==0)
        {
            printf("\nWelcome");
            printf("\nChoose if one way trip or roundtrip: ");
            printf("\n1. One way trip \n2. Roundtrip\n");
            scanf("\n%d", &trip);
            printf("\nDate: ");
            printf("\n1. August 10, 2021 \n2. August 11, 2021\n3. August 12, 2021\n");
            scanf("%d", &date);
            switch (trip) //round trip or one way trip
            {
            case 1: //one way trip
            {
                if (date==1) //one way trip date: aug 10
                {
                    printf("\nAugust 10, 2021\n");
                    option1(); //displays flight info for aug 10
                    printf("\nHow many tickets will you get?:");
                    scanf("%d", &x);
		    //loops for each ticket
                    for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                        scanf("%d", &book[a].ticket);
                    }
                }
                else if (date==2) //one way trip date: aug 11
                {
                printf("\nAugust 11, 2021\n");
                option2(); //shows flight data
                printf("\nHow many tickets will you get?:  ");
                scanf("%d", &x);
		//loops for each ticket
                for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                        scanf("%d", &book[a].ticket);
                    }
                }
                else if (date==3) //one way trip date: aug 12
                {
                    printf("\nAugust 12, 2021\n");
                    option3(); //prints fight data
                    printf("\nHow many tickets will you get?: ");
                    scanf("%d", &x);
		    //loops for each ticket
                    for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                        scanf("%d", &book[a].ticket);
                    }
                }
                else printf("\nInvalid"); //invalid choice
                break;
            }
            case 2: //round trip
                {
                if (date==1) //round trip date: aug 10
                {
                    printf("\nAugust 10, 2021\n");
                    option1();
                    printf("\nChoose date of return: \n1. August 11, 2021\n2. August 12, 2021\n");
                    scanf("%d", &date2);
                    printf("\nHow many tickets will you get (excluding the return trip)?: ");
                    scanf("%d", &x);
		    //loop for amount of tickets
                    for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                        scanf("%d", &book[a].ticket);
                        if (date2==1) //round trip return date: aug 11
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
                        else if (date2==2) //return date round trip: aug 12
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
                        else //invalid round trip return date
                        {
                        printf("\nInvalid"); 
                        return 0;
                        }
                    }
                }
                else if (date==2) //round trip date: aug 11
                {
                printf("\nAugust 11, 2021\n");
                option2();
                printf("\nHow many tickets will you get?: ");
                scanf("%d", &x);
                for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                        scanf("%d", &book[a].ticket);
                    }
                }
                else if (date==3) //round trip date: aug 12
                {
                    printf("\nAugust 12, 2021\n");
                    option3();
                    printf("\nHow many tickets will you get?: ");
                    scanf("%d", &x);
                    for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                        scanf("%d", &book[a].ticket);
                    }
                }
                else printf("\nInvalid"); //invalid round trip date
                break;
                    break;
                }
                default:
                 break;
            }
            printf("\n");
            printf("\nSummary: ");
            for (a=1; a<=x; a++)
            {
            printf("\nDetails of Ticket no. [%d]", a);
            printf("\nFlight no. [%d]\n", book[a].ticket);
            }
            total=book[a].price;
            printf("\nTotal number of tickets: %d\n", x);
            printf("\nTotal Price: %0.2f", total);
	    printf("\nCurrent time for ticket verification is %s", c_time_string);
	    //asking user if they want to keep running the program
	    printf("\n----------------------------------------------------");
	    printf("\nWould you like to keep running the program? (1 for yes | 0 for no): ");
	    scanf("%d", &choice);
	    if (choice == 0){ //stops the program
	    	exit(1);
	    }
        }
        else 
        {
        printf("\nInvalid login, please try again");
        }
    }
    return 0;
}

