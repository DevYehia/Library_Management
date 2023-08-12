#include "stdbool.h"
#include "../lib/stdTypes.h"
#ifndef LIBRARY_H
#define LIBRARY_H


void initialize();     //create the linked list
bool setPassword();
bool checkPassFormat();    //check if password matches desired format or not.
/* Desired Format
    //Must have at least have one number
    //Must be no less than six characters
    //Must not contain spaces
*/
bool confirmPassword();      //compare input password with stored password
void viewBooks();
void addBook();
void deleteBook();



#endif // LIBRARY_H



