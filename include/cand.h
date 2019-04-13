//==============================================================================
//                          CANDIDATES ADT [header]
//------------------------------------------------------------------------------
// DESCRIPTION: Header file of the abstract data type used to manipulate the 
//              CANDIDATES entity in the 'perfect matching' project.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef CAND_H
#define CAND_H

//Number of candidates in the read file
int g_num_candidates; 

/*
 * Struct containing all candidate data.
 */
typedef struct Candidate {
    int index;
    int num_applications;
    int score;
    univ *allocated_university;
    univ **priority_list;
} cand;

/*
 * Create an array of 'candidate' entity.
 */
cand *newCandidateArray(int n);

/*
 * Get candidates from file and store them into an array of type 'cand'.
 */
cand *getCandidatesFromFile(const char *file_name, univ *universities);

/*
 * Free all memory allocated for the candidate array
 */
void freeCandidateArray(cand *c, int n);

#endif //CAND_H