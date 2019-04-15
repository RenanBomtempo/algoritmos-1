//==============================================================================
//                        UTILITY FUNCTIONS [header]                   
//------------------------------------------------------------------------------
// DESCRIPTION: This file contains the implementations of all functions that 
//              might be useful in other components of the program.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void checkFilePointer(FILE *fp, const char *file_name)
{
    if (fp == NULL) 
    {
        fprintf(stderr, "ERROR - Couldn't open the file: \"%s\"\n", file_name);
        exit(EXIT_FAILURE);
    }
}

