#include <stdlib.h>
#include "library.h"
#include "config.h"
#include "storage.h"
#include "stdbool.h"
#include "string.h"
#include "../lib/DL.h"
#include "../lib/utility.h"


void initialize(){
    books = (List *)malloc(sizeof(List));
    createList(books);
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



void viewBooks(){
    if(books -> size == 0){
        red();
        printf("Library is empty!!");
    }
    else{
        printList(books);
    }
     printf("\n\n");
}



void addBook(){

    s8 bookName [MAX_BOOK_NAME_LENGTH];
    s8 authName [MAX_AUTH_NAME_LENGTH];
    u32 ID;
    f32 price;

    printf("Enter an ID for your book: ");
    scanf(" %u",&ID);
    while(searchNode(books,ID)){
        red();
        printf("ID already in the library\nEnter a unique ID: ");
        blue();
        scanf(" %u",&ID);
    }
    getchar();
    printf("Enter the book name: ");
    safeInput(bookName,MAX_BOOK_NAME_LENGTH);

    printf("Enter the author name: ");
    safeInput(authName,MAX_AUTH_NAME_LENGTH);

priceInput:
    printf("Enter the book price: ");
    scanf(" %f",&price);

    if(price < 0){
        red();
        printf("Price cannot be negative\n");
        blue();
        goto priceInput;
    }
    getchar();
    printf("\n");
    green();
    printf("Book Added Successfully!!\n\n");

    ListEntry* book = (ListEntry*)malloc(sizeof(ListEntry));
    strcpy(book->bookName,bookName);
    strcpy(book->authName,authName);
    book->ID = ID;
    book->bookPrice = price;
    insertSortedNode(books,book); 
}

void deleteBook(){
    u32 ID;
    printf("Enter the ID of the book to be deleted: ");
    scanf(" %u",&ID);
    getchar();
    if(deleteNode(books,ID) == false){
        printf("ID doesn't exist\n\n");
        return;
    }

    printf("Deleted Successfully\n\n");
}




