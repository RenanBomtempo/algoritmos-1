//==============================================================================
//                        CANDIDATES ADT (implementation)
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

typedef struct Candidate {
    int num_applications;
    int score;
    univ **priority_list;
} cand;

cand *newCandidate(void)
{
    //Allocate memory
    cand *ptr = (cand*)malloc(sizeof(cand));

    //Check memory
    if(ptr == NULL) {
        perror("ERROR - Could not allocate memory for 'cand' struct.");
        exit(EXIT_FAILURE);
    }

    //Set default values
    ptr->num_applications = -1;
    ptr->score = -1;

    return ptr;
}

void clearCandidate(cand *c)
{
    free(c);
}

int getNumApplications(cand c)
{
    return c.num_applications;
}

void setNumApplications(cand *c, int num)
{
    c->num_applications = num;
}

int getScore(cand c)
{
    return c.score;
}

void setScore(cand *c, int sc)
{
    c->score = sc;
}
