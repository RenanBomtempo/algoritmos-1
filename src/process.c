//==============================================================================
//                           PROOCESS INPUT FILES
//------------------------------------------------------------------------------
// DESCRIPTION: Process all input files and store their data into the programs 
//              data structure. This includes a check for the input formatting 
//              validity.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "univ.h"
#include "cand.h"
#include "process.h"
#define MAX_BUFF_SIZE 128

univ *getUniversitiesFromFile(char *file_name)
{
    //Open file
    FILE *fp = fopen(file_name, "R");
    checkFilePointer(fp, file_name);

    //CLose file
    fclose(fp)

    return;
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

    //Buffer for priority list reading
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

void checkFilePointer(FILE *fp, char *file_name)
{
    if (fp == NULL) 
    {
        fprintf(stderr, "ERROR - There is no file \"%s\" in this directory!", file_name);
        exit(EXIT_FAILURE);
    }
}

