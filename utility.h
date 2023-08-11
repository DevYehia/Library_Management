#include "stdTypes.h"
#include <stdio.h>
#ifndef UTILITY_H
#define UTILITY_H


void safeInput(s8 inp[], u32 maxLimit); //function needed to prevent overflow of input

//coloring functions
void red();
void blue();
void yellow();
void green();
void white();
void magenta();
#endif // UTILITY_H
