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
void freeCollegeArray(col *c);

/*
 * Add candidate to the waiting list.
 */
void addToWaitingList(list **l, cand *c);

/*
 * Free all memory allocated in a list.
 */
void resetWaitingList(list **l);

/*
 * (Quicksort)
 * Returns the last candidate of the waiting list.
 */
list *getLastCandidate(list *l); 

/*
 *(Quicksort)
 * Creates a partition of the list with the last element as the pivot.
 */
list *partition(list *l, list *end, list **new_head, list **new_end);

/*
 *(Quicksort)
 * Recursion function of quicksort.
 */
list *quickSortRecursion(list *l, list *end);

/*
 * Quicksort the waiting list.
 */
void orderWaitingList(list **l);


#endif //UNIV_H