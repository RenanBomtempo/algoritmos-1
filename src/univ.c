//==============================================================================
//                        UNIVERSITIES ADT (implementation)
//------------------------------------------------------------------------------
// DESCRIPTION: Implementation of all functions related to the abstract data 
//              type used to manipulate the UNIVERSITIES entity in the 'perfect
//              matching' project.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "univ.h"

typedef struct University {
    int num_vacancies;
    int min_score;
} univ;

univ *newUniversity(void)
{   
    //Allocate memory
    univ *ptr = (univ*)malloc(sizeof(univ));

    //Check memory
    if(ptr == NULL) {
        perror("ERROR - Could not allocate memory for 'univ' struct.");
        exit(EXIT_FAILURE);
    }

    //Set default values
    ptr->min_score = -1;
    ptr->num_vacancies = -1;

    return ptr;
}

void clearUniversity(univ *u)
{
   free(u);
}

int getNumVacancies(univ u)
{
    return u.num_vacancies;
}

void setNumVacancies(univ *u, const int num)
{
    u->num_vacancies = num;
}

int getMinScore(univ u)
{
    return u.min_score;
}

void setMinScore(univ *u, const int min)
{
    u->min_score = min;
}
