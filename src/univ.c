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
    ptr->min_score = -1;
    ptr->num_vacancies = -1;

    return ptr;
}

univ *getUniversitiesFromFile(const char *file_name)
{   
    //Open file
    FILE *fp = fopen(file_name, "r");
    checkFilePointer(fp, file_name);

    //Number of universities
    int num_universities;
    fscanf(fp, "%d", &num_universities);

    //University array
    univ *universities = newUniversityArray(num_universities);

    //Populate 'universities' with data
    for (int i = 0; i < num_universities; i++)
    {   
        fscanf(fp, "%d %d", &universities[i].num_vacancies, &universities[i].min_score);
    }

    //========================BEGIN-TEST-BLOCK==========================
    printf("\nThe file \'%s\' contains data from %d universities:\n", 
           file_name, num_universities);

    for (int i = 0; i < num_universities; i++)
    {
        printf("    University [%d]:\n"      
               "        vacancies.......%d\n"
               "        minimum score...%d\n", 
               i, universities[i].num_vacancies, universities[i].min_score);
    }
    //=========================END-TEST-BLOCK===========================

    //Close file
    fclose(fp);

    return universities;
}

