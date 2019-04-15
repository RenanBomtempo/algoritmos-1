//==============================================================================
//                          CANDIDATES ADT [header]
//------------------------------------------------------------------------------
// DESCRIPTION: Header file of the abstract data type used to manipulate the 
//              CANDIDATES entity in the 'perfect matching' project.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef CAND_H
#define CAND_H
#include "util.h"

/*
 * Create an array of 'candidate' entity.
 */
cand *newCandidateArray(int n);

/*
 * Get candidates from file and store them into an array of type 'cand'.
 */
cand *getCandidatesFromFile(const char *file_name, col *colleges);

/*
 * Free all memmory allocated for the candidate array
 */
void freeCandidateArray(cand *c, int n);

#endif //CAND_H