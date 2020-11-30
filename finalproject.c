/*
Title: Flight Management system (How long until you see my comment? -Evan)
Desc: This program contains information about flights and lets users book flights
Name: Addison Wenzel, Zac Chen, Andy Lin, Chris DeMuyt, Evan Michael Harding
Email: wenzela@purdue.edu, lin1019@purdue.edu, chen2946@purdue.edu, cdemuyt@purdue.edu, hardine@purdue.edu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void header()
{
    printf("\nFlight                Price   Seating Capacity    Available Seats\n");
}
void option1()
{
    printf("\nFlight                               Price   Seating Capacity    Available Seats\n");
    printf("1. West Lafayette To Indianapolis      50      10          6\n");
    printf("2. West Lafayette To New York          200     75          0\n");
    printf("3. West Lafayette To Atlanta           300     100         24\n");
}
void option2()
{
    printf("\nFlight                               Price   Seating Capacity    Available Seats\n");
    printf("4. West Lafayette To Indianapolis      60       10          8\n");
    printf("5. West Lafayette To New York          200      15          14\n");
    printf("6. West Lafayette To Atlanta           400      30          15\n");
}
void option3()
{
    printf("\nFlight                              Price   Seating Capacity    Available Seats\n");
    printf("7. West Lafayette To Indianapolis       70      10          7\n");
    printf("8. West Lafayette To New York           150     75          16\n");
    printf("9. West Lafayette To Atlanta            500     60          35\n");
}
int choice()
{
}
struct flight{
    int ticket;
    int price;
};
int main() {
    struct flight book[10];
    char user[50], pw[50], adminu[50]="jon", adminpw[50]="snow"; //username and password
    int trip, date, date2, a, x, y;
    float total;
    char repeat;
    int i = 1; //loop variable
    while(i == 1){
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
            printf("\n1. August 10, 2021 \n2. August 11, 2021\n3. August 12, 2021(not applicable for round trip)\n");
            scanf("%d", &date);
            switch (trip)
            {
            case 1: 
            {
                if (date==1)
                {
                    printf("\nAugust 10, 2017\n");
                    option1();
                    printf("\nHow many tickets will you get?:");
                    scanf("%d", &x);
                    for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                        scanf("%d", &book[a].ticket);
                    }
                }
                else if (date==2)
                {
                printf("\nAugust 11, 2017\n");
                option2();
                printf("\nHow many tickets will you get?:  ");
                scanf("%d", &x);
                for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                        scanf("%d", &book[a].ticket);
                    }
                }
                else if (date==3)
                {
                    printf("\nAugust 12, 2017\n");
                    option3();
                    printf("\nHow many tickets will you get?: ");
                    scanf("%d", &x);
                    for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                        scanf("%d", &book[a].ticket);
                    }
                }
                else printf("\nInvalid");
                break;
            }
            case 2:
                {
                if (date==1)
                {
                    printf("\nAugust 10, 2017\n");
                    option1();
                    printf("\nChoose date of return: \n1. August 11, 2017\n2. August 12, 2017\n");
                    scanf("%d", &date2);
                    printf("\nHow many tickets will you get (excluding the return trip)?: ");
                    scanf("%d", &x);
                    for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                        scanf("%d", &book[a].ticket);
                        if (date2==1)
                        {
                        switch (book[a].ticket)
                        {
                            case 1: 
                            {
                                printf("\nDetails for return trip");
                                header();
                                printf("Hong Kong to Manila     2,000   100         45\n"); break;
                            }
                            case 2: 
                            {
                                printf("\nDetails for return trip");
                                header();
                                printf("Caticlan to Manila      1,500   75          67\n"); break;
                            }
                            case 3: 
                            {
                                printf("\nDetails for return trip");
                                header();
                                printf("Singapore to Manila     4,000   100         46\n"); break;
                            }
                            default: break;
                        }
                        }
                        else if (date2==2)
                        {
                            switch (book[a].ticket)
                        {
                            case 1: 
                            {
                                header();
                                printf("\nHong Kong to Manila       2,000   100         45"); break;
                            }
                            case 2: 
                            {
                                header();
                                printf("\nCaticlan to Manila        1,500   75          67"); break;
                            }
                            case 3: 
                            {
                                header();
                                printf("\nSingapore to Manila       4,000   100         46"); break;
                            }
                            default: break;
                        }
                        }
                        else 
                        {
                        printf("\nInvalid"); 
                        return 0;
                        }
                    }
                }
                else if (date==2)
                {
                printf("\nAugust 11, 2017\n");
                option2();
                printf("\nHow many tickets will you get?: ");
                scanf("%d", &x);
                for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                        scanf("%d", &book[a].ticket);
                    }
                }
                else if (date==3)
                {
                    printf("\nAugust 12, 2017\n");
                    option3();
                    printf("\nHow many tickets will you get?: ");
                    scanf("%d", &x);
                    for (a=1; a<=x; a++)
                    {
                        printf("\nPlease select which flight you will book: ");
                        scanf("%d", &book[a].ticket);
                    }
                }
                else printf("\nInvalid");
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
        }
        else 
        {
        printf("\nInvalid login");
        }
    }
    return 0;
}

