//==============================================================================
//                               UTILITY [header]                   
//------------------------------------------------------------------------------
// DESCRIPTION: This file contains all declarations of structs, functions and 
//              global variables that might be used in other components of the 
//              program.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef UTIL_H
#define UTIL_H

//Number of candidates in the read file
int g_num_candidates; 

//Number of colleges in the read file
int g_num_colleges;

/*
 * Struct containing all candidate data.
 */
typedef struct Candidate {
    //Cnadidate index;
    int index;
    //Number of applications made by the candidate.
    int num_applications;
    //Score of the candidate.
    int score;
    //Index of the college the candidate was allocated to.
    int allocated_college_index;
    //List of college indices to which the candidate will apply to.
    int *priority_list;
} cand;

/*
 * Struct for the waiting list of the colleges.
 */
typedef struct List {
    cand *candidate;
    struct List *next;
} list;

/*
 * Struct containing the college data.
 */
typedef struct college {
    //College index
    int index;
    //Quota of applications of the college.
    int quota;
    //Minimum score needed to apply for this college.
    int min_score;
    //Ordered list of the candidates that got into the college.
    int *selected_candidates;
    //Waiting list for the candidates that applied to this college.
    list *waiting_list;
} col;

/*
 * Chech if the desired file was opened correctly.
 */
void checkFilePointer(FILE *fp, const char *file_name);

#endif //UTIL_H