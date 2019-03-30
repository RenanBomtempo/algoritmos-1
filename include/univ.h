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
typedef struct University univ;

/*
 * Allocate memory for a new 'univ' entity.
 */
univ *newUniversity(void);

/*
 * Free memory previously allocated to a 'univ' entity.
 */
void clearUniversity(univ *u);

/*
 * GET the number of vacancies of the given university.
 */
int getNumVacancies(univ u);

/*
 * SET the number of vacancies of the given university.
 */
void setNumVacancies(univ *u, int num);

/*
 * GET the minimum score to enter the given university.
 */
int getMinScore(univ u);

/*
 * SET the minimum score to enter the given university.
 */
void setMinScore(univ *u, int min);

#endif