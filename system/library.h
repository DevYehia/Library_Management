#include "stdbool.h"
#include "../lib/stdTypes.h"
#ifndef LIBRARY_H
#define LIBRARY_H


void initialize();     //initialize all arrays with default values
bool setPassword();
bool checkPassFormat();    //check if password matches desired format or not
bool confirmPassword();      //compare input password with stored password



void displayInfo();
void addBook();
void deleteBook();
void viewBooks();


#endif // LIBRARY_H



