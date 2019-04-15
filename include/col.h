//==============================================================================
//                         colleges ADT [header]
//------------------------------------------------------------------------------
// DESCRIPTION: Header file of the abstract data type used to manipulate the 
//              colleges entity in the 'perfect matching' project.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef UNIV_H
#define UNIV_H
#include "util.h"

/*
 * Create an array of type col.
 */
col *newCollegeArray(int n);

/*
 * Get colleges from file and store them into an array of type 'cand'.
 */
col *getCollegesFromFile(const char *file_name);

/*
 * Free all memmory allocated for the college array
 */
void freeCollegeArray(col *u);

/*
 * Add candidate to the waiting list.
 */
void addToList(list **l, cand *c);

/*
 * Free all memory allocated in a list.
 */
void freeList(list *l);

/*
 * Remove candidate from the waiting list.
 */
void removeFromList(list *l, int key);

/*
 * Order the waiting list 
 */
void orderList(list *l);

#endif //UNIV_H