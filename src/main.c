//==============================================================================
//                                MAIN FILE
//------------------------------------------------------------------------------
// DESCRIPTION: This is the main file for the program. It only contains the main
//              the main function. 
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "univ.h"
#include "cand.h"
#include "process.h"

int main(int argc, char const *argv[])
{
    univ *universities = getUniversitiesFromFile();
    cand *candidates = getCandidatesFromFile(argv[1], universities);
    //Store all universities in an array
    //Store all canddates in an array
    //Run Gale-Shapley algortihm

    return 0;
}
