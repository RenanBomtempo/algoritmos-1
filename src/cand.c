//==============================================================================
//                        CANDIDATES ADT [implementation]
//------------------------------------------------------------------------------
// DESCRIPTION: Implementation of all functions related to the abstract data 
//              type used to manipulate the CANDIDATES entity in the 'perfect
//              matching' project.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "univ.h"
#include "cand.h"
#include "utilities.h"
#define MAX_BUFF_SIZE 128

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
        ptr[i].num_applications = -1;
        ptr[i].score = -1;
        ptr[i].priority_list = NULL;
    }

    return ptr;
}

void freeCandidateArray(cand *c)
{
    free(c);
}

cand *getCandidatesFromFile(char *file_name, univ *universities) 
{
    //Open file
    FILE *fp = fopen(file_name, "R");
    checkFilePointer(fp, file_name);

    //Number of candidates in the file
    int num_candidates;
    fscanf(fp, "%d", &num_candidates);

    //Array of candidates
    cand *candidates = newCandidateArray(num_candidates);

    //Buffer for priority list 
    char buffer[MAX_BUFF_SIZE];

    //Read all candidates
    for (int i=0; i<num_candidates; i++)
    {
        fscanf(fp, "%d%d", &candidates[i].num_applications, &candidates[i].score);
        fscanf(fp, "%s", buffer);
        candidates[i].priority_list = processPriorityList(buffer, universities);
    }

    //Close file
    fclose(fp);

    return NULL;
}


univ **processPriorityList(char *str, univ *universities) 
{/*
    //read each number between spaces in the string 
    //get number of universisitesin the priority list
    int num_univs;
    int univ_index[num_univs];
    
    //create priority list
    univ **priority_list = (univ**)malloc(num_univs * sizeof(univ*));

    //associate each number with the respective university
    for (int i=0; i<num_univs; i++)
    {
        priority_list[i] = universities + univ_index[i];
    }

    //return array
    return priority_list;
 */
}

