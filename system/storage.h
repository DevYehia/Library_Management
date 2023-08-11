#include "config.h"
#include "../lib/DL.h"
#ifndef STORAGE_H
#define STORAGE_H

//Our Mini DataBase :)
List* books;
s8  password [MAX_PASS_LENGTH+1]; //+1 due to the need of \0 at the end
#endif // STORAGE_H
