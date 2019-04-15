//==============================================================================
//                        STABLE MATCHING [header]                   
//------------------------------------------------------------------------------
// DESCRIPTION: This file contains all declarations of funtions that will be 
//              used for executing the Gale-Shapley stable matching algorithm.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef  STBLM_H   
#define  STBLM_H   
#include "col.h"
#include "cand.h"
#include "util.h"

/*
 * Execute the Gale-Shapley algorithm for stable matching.
 */
void runGaleShapley(col *colleges, cand *candidates);

/*
 *
 */
int everyoneApplied(cand *candidates);

/*
 *
 */
int *initializeUnallocatedCandidates(int n);

/*
 *
 */
void candidateIsNowAllocated(int *list, int candidate);

/*
 *
 */
void applyToCollege(cand *candidate, col *college);


#endif //STBLM_H   