//==============================================================================
//                        STABLE MATCHING [implementation]                   
//------------------------------------------------------------------------------
// DESCRIPTION: Implementation of functions used for executing the Gale-Shapley
//              stable matching algorithm.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "stblm.h"
#include "col.h"
#include "cand.h"
#include "util.h"

void runGaleShapley(col *colleges, int num_col, cand *candidates, int num_cand)
{   
    //List conaining all candidates that are not allocated
    int *unallocated_candidates = initializeUnallocatedCandidates(num_cand);

    while(!everyoneApplied(candidates, num_cand))
    {
        //For all candidates that are not yet allocated but can still be
        for (int i = 0; i < num_cand; i++)
        {   
            //Current candidate to apply
            cand *applying_cand = NULL;

            //College to which the candidate will apply
            col  *college_to_apply = NULL;

            
            if (unallocated_candidates[i] == 1) 
            {   
                //If the given candidate is not yet allocated, select it
                applying_cand = &candidates[i];
            } 
            else //If the candidate is already allocated go to the next one
            {
                continue;
            }

            //Check if there is a college which it can still apply to and select it
            for (int j=0; j<applying_cand->num_applications; j++)
            {
                //Index of the college to which the candidate will apply to
                int col_ind = applying_cand->priority_list[j];
                
                if (col_ind > 0) 
                {
                    //If he has not yet been rejected by that college, select it
                    college_to_apply = colleges[col_ind];
                    break;
                }
            }

            //Apply the 'applying_candidate' to the 'college_to_apply'
            applyToCollege(applying_cand, college_to_apply);

        }
        
    }
    
    //Free mallocs
    free(unallocated_candidates);
}

int everyoneApplied(cand *candidates, int n)
{
    //Did everyone applied yet?
    int bool = 0;

    //For each candidate check if there is still a college on its list
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < candidates[i].num_applications; j++)
        {
            if (candidates[i].priority_list[j] >= 0) bool++;
        } 
    }
    
    return bool;
}

int *initializeUnallocatedCandidates(int n)
{
    //Allocate memmory 
    int *ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) 
    {
        perror("ERROR - Could not allocate memmory for the 'Unalocated Candidates List'!");
        exit(EXIT_FAILURE);
    }

    //Initially all candidates are unallocated
    for (int i = 0; i < n; i++) ptr[i] = 1;
    
    return ptr;
}

void candidateIsNowAllocated(int *list, int candidate)
{
    list[candidate] = -1;
}

void applyToCollege(cand *candidate, col *college)
{
    
}