//==============================================================================
//                          CANDIDATES ADT (interface)
//------------------------------------------------------------------------------
// DESCRIPTION: Header file of the abstract data type used to manipulate the 
//              CANDIDATES entity in the 'perfect matching' project.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef CAND_H
#define CAND_H

/*
 * Struct containing all candidate data.
 */
typedef struct Candidate {
    int num_applications;
    int score;
    char is_allocated;
    univ **priority_list;
} cand;

/*
 * Create an array of 'candidate' entity.
 */
cand *newCandidateArray(int n);

/*
 * Get the string containing the priority list and convert it into an array of 
 * universities.
 */
univ **processPriorityList(char *str, univ *universities);

#endif