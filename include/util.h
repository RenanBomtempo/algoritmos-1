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
#include "col.h"
#include "cand.h"

/*
 * Struct for the waiting list of the colleges.
 */
typedef struct List{
    cand *candidate;
    struct list *next;
} list;

/*
 * Add candidate to the waiting list.
 */
void addToList(list *l, int key);

/*
 * Remove candidate from the waiting list.
 */
void removeFromList(list *l, int key);

/*
 * Order the waiting list 
 */
void orderList(list *l);

/*
 * Chech if the desired file was opened correctly.
 */
void checkFilePointer(FILE *fp, const char *file_name);

#endif //UTIL_H