#include "config.h"
#ifndef STORAGE_H
#define STORAGE_H

//Our Mini DataBase :)
s8  password [MAX_PASS_LENGTH+1]; //+1 due to the need of \0 at the end
s8  bookNames [MAX_BOOKS][MAX_BOOK_NAME_LENGTH+1]; //+1 due to the need of \0 at the end
s8  authNames [MAX_BOOKS][MAX_AUTH_NAME_LENGTH+1]; //+1 due to the need of \0 at the end
u32 IDs [MAX_BOOKS];
f32 bookPrices [MAX_BOOKS] ;

#endif // STORAGE_H
