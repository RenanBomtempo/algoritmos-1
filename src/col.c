//==============================================================================
//                        COLLEGES ADT [implementation]
//------------------------------------------------------------------------------
// DESCRIPTION: Implementation of all functions related to the abstract data 
//              type used to manipulate the colleges entity in the 'perfect
//              matching' project.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "col.h"
#include "util.h"

col *newCollegeArray(int n)
{   
    //Allocate memmory
    col *ptr = (col*)malloc(n * sizeof(col));

    //Check memmory
    if(ptr == NULL) {
        perror("ERROR - Could not allocate memmory for 'col' struct.");
        exit(EXIT_FAILURE);
    }

    //Set default values
    for (int i=0; i<n; i++)
    {
        ptr[i].min_score = -1;
        ptr[i].quota = -1;
        ptr[i].selected_candidates = NULL;
        ptr[i].waiting_list = NULL;
    }

    return ptr;
}

col *getCollegesFromFile(const char *file_name)
{   
    //Open file
    FILE *fp = fopen(file_name, "r");
    checkFilePointer(fp, file_name);

    //Number of colleges
    fscanf(fp, "%d", &g_num_colleges);

    //college array
    col *colleges = newCollegeArray(g_num_colleges);

    //Populate 'colleges' with data
    for (int i = 0; i < g_num_colleges; i++)
    {   
        //Read 'quota' and 'min_score'
        fscanf(fp, "%d %d", &colleges[i].quota, 
                            &colleges[i].min_score);
    }

    //========================BEGIN-LOG-BLOCK==========================
    printf("All collected data from %d colleges:\n", g_num_colleges);

    for (int i = 0; i < g_num_colleges; i++)
    {
        printf("    college [%d]:\n"      
               "        quota.......%d\n"
               "        minimum score...%d\n", 
               i, 
               colleges[i].quota, 
               colleges[i].min_score);
    }
    //=========================END-LOG-BLOCK===========================

    //Close file
    fclose(fp);

    return colleges;
}

void freeCollegeArray(col *u)
{
    //Free college array
    free(u);
}
