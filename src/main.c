//==============================================================================
//                                MAIN FILE
//------------------------------------------------------------------------------
// DESCRIPTION: This is the main file for the program. It only contains the main
//              the main function in which all others are called. 
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "univ.h"
#include "cand.h"
#include "utilities.h"

int main(int argc, const char *argv[])
{
    /***************************************************************************
     * The arguments passed through the CLI are in the following order:        *
     *                                                                         *
     * $ [executable_name] [universities_data] [candidates_data]               *
     *           ^                  ^                  ^                       *
     *        argv[0]            argv[1]            argv[2]                    *
     **************************************************************************/   

    //Array of universities
    char *file_name_buffer = argv[1];
    univ *universities = getUniversitiesFromFile(file_name_buffer);

    //Array of candidates
    file_name_buffer = argv[2];
    cand *candidates = getCandidatesFromFile(file_name_buffer, universities);

    //Run Gale-Shapley algortihm

    //Free all arrays
    freeUniversityArray(universities);
    freeCandidateArray(candidates, g_num_candidates);
    return 0;
}
