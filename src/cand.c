//==============================================================================
//                        candidates ADT [implementation]
//------------------------------------------------------------------------------
// DESCRIPTION: Implementation of all functions related to the abstract data 
//              type used to manipulate the candidates entity in the 'perfect
//              matching' project.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "univ.h"
#include "cand.h"
#include "util.h"

cand *newCandidateArray(int n)
{
    //Allocate memory
    cand *ptr = (cand*)malloc(n * sizeof(cand));

    //Check memory
    if(ptr == NULL) {
        perror("ERROR - Could not allocate memory for 'cand' struct.");
        exit(EXIT_FAILURE);
    }

    //Set default values
    for (int i=0; i<n; i++)
    {
        ptr[i].index = i+1;
        ptr[i].num_applications = -1;
        ptr[i].score = -1;
        ptr[i].priority_list = NULL;
        ptr[i].allocated_university = NULL;
    }

    return ptr;
}

cand *getCandidatesFromFile(const char *file_name, univ *universities) 
{
    //Open file
    FILE *fp = fopen(file_name, "r");
    checkFilePointer(fp, file_name);

    //Number of candidates in the file
    fscanf(fp, "%d", &g_num_candidates);
    printf("All collected data from %d candidates:\n", g_num_candidates);

    //Array of candidates
    cand *candidates = newCandidateArray(g_num_candidates);

    //Read all candidates
    for (int i=0; i<g_num_candidates; i++)
    {   
        //Read 'num_applications' and 'score'
        fscanf(fp, "%d %d", &candidates[i].num_applications, &candidates[i].score);

        //Allocate memory for the priority list
        candidates[i].priority_list = (univ**)malloc(candidates[i].num_applications * sizeof(univ*));
        if (candidates[i].priority_list == NULL) 
        {
            perror("ERROR - Could not allocate memory for priority list\n"); 
            exit(EXIT_FAILURE);
        }
            
        //Index of a given university in the priority list
        int univ_index;

        //Read priority list
        for (int j=0; j<candidates[i].num_applications; j++)
        {
            fscanf(fp, "%d", &univ_index); 
            candidates[i].priority_list[j] = &universities[univ_index-1];
            /*The '-1' compensates for the fact that the indices given in 
             *the file start at 1.*/
        }

        //========================BEGIN-LOG-BLOCK==========================
        printf("    Candidate [%d]:\n"      
               "        applications....%d\n"
               "        score...........%d\n"
               "        priority list...", 
               candidates[i].index, candidates[i].num_applications, candidates[i].score);
        
        for (int j=0; j<candidates[i].num_applications; j++)
            printf("%d ", candidates[i].priority_list[j]->index);
        
        printf("\n");
        //=========================END-LOG-BLOCK=========================== 
    }

    //Close file
    fclose(fp);

    return candidates;
}

void freeCandidateArray(cand *c, int n)
{   
    //Free each candidates priority list
    for (int i=0; i<n; i++)
        free(c[i].priority_list);
    
    //Free candidate array
    free(c);

    printf("Candidate array freed\n");
}