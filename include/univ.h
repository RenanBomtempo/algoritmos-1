//==============================================================================
//                        UNIVERSITIES ADT (interface)
//------------------------------------------------------------------------------
// DESCRIPTION: Header file of the abstract data type used to manipulate the 
//              UNIVERSITIES entity in the 'perfect matching' project.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef UNIV_H
#define UNIV_H

/*
 * Struct containing the university data.
 */
typedef struct University {
    int num_vacancies;
    int min_score;
} univ;

#endif