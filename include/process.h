//==============================================================================
//                           PROOCESS INPUT FILES
//------------------------------------------------------------------------------
// DESCRIPTION: Process all input files and store their data into the program's 
//              data structure. This includes a check for the input formatting 
//              validity.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "univ.h"
#include "cand.h"


/*
 * Get candidates from file and store them into an array of type 'cand'
 */
cand *getCandidatesFromFile(char const *file_name);

/*
 * Chech if the desired file was opened correctly
 */
void checkFilePointer(FILE *fp, char *file_name);

