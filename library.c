#include "library.h"
#include "config.h"
#include "storage.h"
#include "stdbool.h"
#include "string.h"
#include "utility.h"


void initialize(){
    for(u32 i = 0 ; i < MAX_BOOKS ; i++){
        IDs[i] = -1;
        bookPrices[i] = -1;
    }
}

bool setPassword(){
    printf("Please Create a password (MAX LENGTH is %d characters): ",MAX_PASS_LENGTH);
    safeInput(password,MAX_PASS_LENGTH); //declared in utility.h
    return checkPassFormat(password);
}

bool checkPassFormat(s8 password []){
    u32 i;
    bool NoNumbers = true;
    for(i = 0 ; password[i] != '\0' ; i++){
        if(password[i] == ' '){
            printf("Password shouldn't contain spaces\n\n");
            return 0;
        }
        if(password[i] >= '0' && password[i] <= '9'){
            NoNumbers = false;
        }
    }
    if(NoNumbers){
        printf("Password Must Contain At least one number\n\n");
        return 0;
    }
    if(i <= 5){
        printf("Password must have at least 6 characters\n\n");
        return 0;
    }
    return 1;
}


bool confirmPassword(){
    s8 input[MAX_PASS_LENGTH] ;
    printf("Please Enter your password: ");
    safeInput(input,MAX_PASS_LENGTH);
    if(strcmp(input,password) == 0)
        return 1;
    else
        return 0;
}


s32 findEmptySlot(){
    for(u32 i = 0 ; i < MAX_BOOKS ; i++){
        if(IDs[i] == -1)
            return i;
    }
    return -1;

}

s32 getBookIndex(u32 ID){
    for(u32 i = 0 ; i < MAX_BOOKS ; i++){
        if(ID == IDs[i]){
            return i;
        }
    }
    return -1;
}

void viewBooks(){
    bool empty = true;
    for(u32 i = 0 ; i < MAX_BOOKS ; i++){
        if(IDs[i] != -1)
        {
            empty = false;
            displayInfo(i);

        }
    }
    if(empty){
        red();
        printf("Library is empty!!");
    }
     printf("\n\n");

}

void displayInfo(u32 bookIndex){
    printf("-------------------------------------\n");
    printf("Book Name: %s\n", bookNames[bookIndex]);
    printf("Author Name: %s\n", authNames[bookIndex]);
    printf("Book ID: %u\n", IDs[bookIndex]);
    printf("Book Price: %.2f$\n", bookPrices[bookIndex]);
    printf("-------------------------------------\n");

}

void addBook(){

    s8 bookName [MAX_BOOK_NAME_LENGTH];
    s8 authName [MAX_AUTH_NAME_LENGTH];
    u32 ID;
    f32 price;
    s32 slot = findEmptySlot();


    if(slot == -1){
        red();
        printf("Library is full, can't add any more books!!\n\n");
        return;
    }
    printf("Enter an ID for your book: ");
    scanf("%u",&ID);
    fflush(stdin);
    while(getBookIndex(ID) != -1){
        red();
        printf("ID already in the library\nEnter a unique ID: ");
        blue();
        scanf("%u",&ID);
        fflush(stdin);
    }
    printf("Enter the book name: ");
    safeInput(bookName,MAX_BOOK_NAME_LENGTH);

    printf("Enter the author name: ");
    safeInput(authName,MAX_AUTH_NAME_LENGTH);

priceInput:
    printf("Enter the book price: ");
    scanf("%f",&price);
    fflush(stdin);
    if(price < 0){
        red();
        printf("Price cannot be negative\n");
        blue();
        goto priceInput;
    }
    printf("\n");
    green();
    printf("Book Added Successfully!!\n\n");

    strcpy(bookNames[slot] , bookName);
    strcpy(authNames[slot] , authName);
    IDs[slot] = ID;
    bookPrices[slot] = price;
}

void deleteBook(){
    u32 ID;
    printf("Enter the ID of the book to be deleted: ");
    scanf("%u",&ID);
    fflush(stdin);
    s32 index = getBookIndex(ID);
    if(index == -1){
        printf("ID doesn't exist\n\n");
        return;
    }
    strcpy(bookNames[index] , "\0");
    strcpy(authNames[index] , "\0");
    IDs[index] = -1;
    bookPrices[index] = -1;
    printf("Deleted Successfully\n\n");
}




