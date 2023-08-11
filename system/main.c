#include <stdlib.h>
#include "../lib/stdTypes.h"
#include "library.h"
#include "../lib/utility.h"
#include "stdbool.h"
s32 main()
{
    while(setPassword() == 0){
        //keep asking user for password until format is matched
        //Must have at least have one number
        //Must be no less than six characters
        //Must not contain spaces
    }
    
    initialize();

    printf("\nWelcome to your ");
    magenta(); //functions to color text found in utility.h
    printf("VERY ");
    white();
    printf("smart library management system :)\n\n");

    short int choice = -1;

    while(true){
    white();
    printf("Please Choose Your Desired Operation:\n");

    green();
    printf("1- View all Books\n");

    blue();
    printf("2- Add a Book\n");

    red();
    printf("3- Delete a Book\n");

    yellow();
    printf("4- Log Out\n");

    white();
    printf("Your Choice: ");
    scanf(" %d",&choice);
    getchar();
    printf("\n");

    if(choice == 4) //Log out selected
    {
        yellow();
        break;
    }
    while(confirmPassword() == 0){
        //break from loop when user enters correct password
        //could have added max number of retries but i am lazy :)
        printf("Invalid Password. Try again\n\n");
    }
    printf("\n");
    switch(choice){
    case 1:
        green();
        viewBooks();
        break;
    case 2:
        blue();
        addBook();
        break;
    case 3:
        red();
        deleteBook();
        break;
    default:
        printf("Invalid Choice\n\n");
    }
    }
    printf("GoodBye [INSERT USER NAME HERE], See you soon");
    white();
    return 0;
}
