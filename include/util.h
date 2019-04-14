//==============================================================================
//                        UTILITY FUNCTIONS [header]                   
//------------------------------------------------------------------------------
// DESCRIPTION: This file contains all declarations of functions that might be
//              useful in other components of the program.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <stdlib.h>

/*
 * Chech if the desired file was opened correctly.
 */
void checkFilePointer(FILE *fp, const char *file_name);

#endif //UTIL_H