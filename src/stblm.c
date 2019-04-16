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
#define ALREADY_APPLIED_TO -1
#define ALLOCATED 1
#define NOT_ALLOCATED 0

//List conaining all candidates that are not allocated
int *g_candidates_status;

void runGaleShapley(col *colleges, cand *candidates)
{   
    g_candidates_status = initializeCandidatesStatus(g_num_candidates);
    
    //While there are still candidates that can apply to a college
    while(!everyoneApplied(candidates))
    {
        //LOGprintf("\n=====NEW PHASE HAS BEGUN=====\n");
        //For all candidates that are not yet allocated but can still be
        for (int i = 0; i < g_num_candidates; i++)
        {   
            //Current candidate to apply
            cand *applying_cand = NULL;

            //Index of the college to which the candidate will apply to
            int col_ind;
            
            //Check if the caniddate i is already allocated
            if (g_candidates_status[i] == NOT_ALLOCATED) 
            {   
                //If the given candidate is not yet allocated, select it
                applying_cand = &candidates[i];

                //Check if there is a college which it can still apply to and select it
                for (int j=0; j<applying_cand->num_applications; j++)
                {
                    col_ind = applying_cand->priority_list[j];
                    
                    //If he has not yet been rejected by that college, apply to it
                    if (col_ind >= 0) 
                    {
                        applyToCollege(applying_cand, &colleges[col_ind]);

                        /*By subtracting the total number of colleges
                         *we don't lose the information of what college it is 
                         *and also provide control over which colleges the 
                         *candidate has already applied to.*/
                        applying_cand->priority_list[j] -= g_num_colleges;
                        
                        //and go to next candidate
                        break;
                    }
                }
            }
        }
        
        //Select all candidates within the college quota  
        acceptCandidatesOnWaintingLists(colleges);
    }

    //PROGRAM OUTPUT
    printf("Grupos com alocacao\n");
    for (int i = 0; i < g_num_candidates; i++)
    {
        if (g_candidates_status[i] == ALLOCATED)
            printf("%d %d\n", candidates[i].index+1, candidates[i].allocated_college_index+1);
    }

    printf("Candidatos nao alocados\n");
    for (int i = 0; i < g_num_candidates; i++)
    {
        if (g_candidates_status[i] == NOT_ALLOCATED)
            printf("%d\n", candidates[i].index+1);
    }

    //Free mallocs
    free(g_candidates_status);
}

void acceptCandidatesOnWaintingLists(col *colleges)
{
    for (int i = 0; i < g_num_colleges; i++)
    {
        //LOGprintf("Accepting candidates from college %d with quota %d\n", colleges[i].index, colleges[i].quota);
        if (colleges[i].quota == 0) continue;

        orderWaitingList(&colleges[i].waiting_list);
       
        //Start with the candidate at the top of the list
        list *cur = colleges[i].waiting_list;

        while (cur != NULL && colleges[i].quota > 0) 
        {
            //Insert index of college in candidate
            cur->candidate->allocated_college_index = colleges[i].index;

            //Change candidate status to allocated
            g_candidates_status[cur->candidate->index] = ALLOCATED;
            
            //Update college quota
            colleges[i].quota -= 1;
            
            //Select the next candidate in the list
            cur = cur->next;
        } 

        resetWaitingList(&colleges[i].waiting_list);
    }
}

void applyToCollege(cand *candidate, col *college)
{
    if (candidate->score >= college->min_score)
    {
        addToWaitingList(&college->waiting_list, candidate);
        //LOGprintf("Candidate %d applied to college %d\n", candidate->index, college->index);
    }
}

int everyoneApplied(cand *candidates)
{
    //For each candidate check if there is still a college on its list
    for (int i = 0; i < g_num_candidates; i++)
    {
        //Only check the priority list if the candidate has not yet been allocated
        if (g_candidates_status[i] == NOT_ALLOCATED)
        {
            for (int j = 0; j < candidates[i].num_applications; j++)
            {
                if (candidates[i].priority_list[j] >= 0) return 0;
            } 
        }
    }

    return 1;
}

int *initializeCandidatesStatus(int n)
{
    //Allocate memmory 
    int *ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) 
    {
        perror("ERROR - Could not allocate memmory for the 'Unalocated Candidates List'!");
        exit(EXIT_FAILURE);
    }

    //Initially all candidates are unallocated
    for (int i = 0; i < n; i++) ptr[i] = 0;
    
    return ptr;
}

