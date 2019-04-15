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

void runGaleShapley(col *colleges, cand *candidates)
{   
    //List conaining all candidates that are not allocated
    int *unallocated_candidates = initializeUnallocatedCandidates(g_num_candidates);
    
    //While there are still candidates that can apply to a college
    while(!everyoneApplied(candidates))
    {
        //For all candidates that are not yet allocated but can still be
        for (int i = 0; i < g_num_candidates; i++)
        {   
            //Current candidate to apply
            cand *applying_cand = NULL;

            //Index of the college to which the candidate will apply to
            int col_ind;
            
            if (unallocated_candidates[i] == 1) 
            {   
                //If the given candidate is not yet allocated, select it
                applying_cand = &candidates[i];

                //Check if there is a college which it can still apply to and select it
                for (int j=0; j<applying_cand->num_applications; j++)
                {
                    col_ind = applying_cand->priority_list[j];
                    
                    if (col_ind >= 0) 
                    {
                        //If he has not yet been rejected by that college, apply to it
                        applyToCollege(applying_cand, &colleges[col_ind]);

                        //Set this college status to 'already applied to' (assign -1)
                        applying_cand->priority_list[j] = -1;
                        
                        //and go to next candidate
                        break;
                    }
                }
            } 
            else //If the candidate is already allocated go to the next one
            {
                continue;
            }
        }
        //Order the waiting list before selecting the candidates
        for (int i = 0; i < g_num_colleges; i++)
        { 
            printf("\nBefore ordering:\n");
            printWaitingList(colleges[i].waiting_list, i);
            
            orderWaitingList(&colleges[i].waiting_list);
            
            printf("After ordering:\n");
            printWaitingList(colleges[i].waiting_list, i);
        }
    }

    //Free mallocs
    for (int i = 0; i < g_num_colleges; i++)
        freeWaitingList(colleges[i].waiting_list);
    
    free(unallocated_candidates);
}

void applyToCollege(cand *candidate, col *college)
{
    if (candidate->score >= college->min_score)
    {
        addToWaitingList(&college->waiting_list, candidate);
        printf("Candidate %d applied to college %d\n", candidate->index, college->index);
    }
}

int everyoneApplied(cand *candidates)
{
    //For each candidate check if there is still a college on its list
    for (int i = 0; i < g_num_candidates; i++)
    {
        for (int j = 0; j < candidates[i].num_applications; j++)
        {
            if (candidates[i].priority_list[j] >= 0) return 0;
        } 
    }

    return 1;
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

