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
typedef struct Candidate cand;

/*
 * Allocate memory for a new 'candidate' entity.
 */
cand *newCandidate(void);

/*
 * Free memory previously allocated to a 'candidate' entity.
 */
void clearCandidate(cand *c);

/*
 * GET the number of applications made by the given candidate.
 */
int getNumApplications(cand c);

/*
 * SET the number of applications made by the given candidate.
 */
void setNumApplications(cand *c, int num);

/*
 * GET the score of  the given candidate.
 */
int getScore(cand c);

/*
 * SET the score of  the given candidate.
 */
void setScore(cand *c, int sc);

#endif