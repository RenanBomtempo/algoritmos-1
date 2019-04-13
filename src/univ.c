//==============================================================================
//                        UNIVERSITIES ADT [implementation]
//------------------------------------------------------------------------------
// DESCRIPTION: Implementation of all functions related to the abstract data 
//              type used to manipulate the UNIVERSITIES entity in the 'perfect
//              matching' project.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "univ.h"
#include "utilities.h"

univ *newUniversityArray(int n)
{   
    //Allocate memory
    univ *ptr = (univ*)malloc(n * sizeof(univ));

    //Check memory
    if(ptr == NULL) {
        perror("ERROR - Could not allocate memory for 'univ' struct.");
        exit(EXIT_FAILURE);
    }

    //Set default values
    for (int i=0; i<n; i++)
    {
        ptr[i].index = i+1;
        ptr[i].min_score = -1;
        ptr[i].num_vacancies = -1;
    }

    return ptr;
}

univ *getUniversitiesFromFile(const char *file_name)
{   
    //Open file
    FILE *fp = fopen(file_name, "r");
    checkFilePointer(fp, file_name);

    //Number of universities
    fscanf(fp, "%d", &g_num_universities);

    //University array
    univ *universities = newUniversityArray(g_num_universities);

    //Populate 'universities' with data
    for (int i = 0; i < g_num_universities; i++)
    {   
        //Read 'num_vacancies' and 'min_score'
        fscanf(fp, "%d %d", &universities[i].num_vacancies, 
                            &universities[i].min_score);
    }

    //========================BEGIN-LOG-BLOCK==========================
    printf("All collected data from %d universities:\n", g_num_universities);

    for (int i = 0; i < g_num_universities; i++)
    {
        printf("    University [%d]:\n"      
               "        vacancies.......%d\n"
               "        minimum score...%d\n", 
               universities[i].index, 
               universities[i].num_vacancies, 
               universities[i].min_score);
    }
    //=========================END-LOG-BLOCK===========================

    //Close file
    fclose(fp);

    return universities;
}

void freeUniversityArray(univ *u)
{
    //Free university array
    free(u);

    printf("University array freed\n");

}
