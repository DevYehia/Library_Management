#include "stdbool.h"
#include "../lib/stdTypes.h"
#ifndef LIBRARY_H
#define LIBRARY_H


void initialize();     //initialize all arrays with default values
bool setPassword();
bool checkPassFormat();    //check if password matches desired format or not
bool confirmPassword();      //compare input password with stored password

s32 findEmptySlot();   //find unoccupied space in the array to store an added book
s32 getBookIndex(u32 ID);   //find index of book in the array by ID

void displayInfo();
void addBook();
void deleteBook();
void viewBooks();


#endif // LIBRARY_H



