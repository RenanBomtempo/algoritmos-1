//==============================================================================
//                         UNIVERSITIES ADT [header]
//------------------------------------------------------------------------------
// DESCRIPTION: Header file of the abstract data type used to manipulate the 
//              UNIVERSITIES entity in the 'perfect matching' project.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef UNIV_H
#define UNIV_H

//Number of universities in the read file
int g_num_universities;

/*
 * Struct containing the university data.
 */
typedef struct University {
    int index;
    int num_vacancies;
    int min_score;
} univ;

/*
 * Create an array of type univ.
 */
univ *newUniversityArray(int n);

/*
 * Get universities from file and store them into an array of type 'cand'.
 */
univ *getUniversitiesFromFile(const char *file_name);

/*
 * Free all memory allocated for the university array
 */
void freeUniversityArray(univ *u);

#endif //UNIV_H