//==============================================================================
//                           PROOCESS INPUT FILES
//------------------------------------------------------------------------------
// DESCRIPTION: Process all input files and store their data into the programs 
//              data structure. This includes a check for the input formatting 
//              validity.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "univ.h"
#include "cand.h"
#include "process.h"

/*
 * Get candidates from file and store them into an array of type 'cand'.
 */
cand *getCandidatesFromFile(char *file_name) {
    //Open file
    FILE *fp = fopen(file_name, "R");
    checkFilePointer(fp, file_name);

    //Close file
    fclose(fp);

    return NULL;
}

//Populate UNIVERSITIES array

/*
 * Chech if the desired file was opened correctly
 */
void checkFilePointer(FILE *fp, char *file_name) {
    if (fp == NULL) {
        fprintf(stderr, "ERROR - There is no file \"%s\" in this directory!", file_name);
        exit(EXIT_FAILURE);
    }
}

