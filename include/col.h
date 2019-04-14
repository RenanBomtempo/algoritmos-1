//==============================================================================
//                         colleges ADT [header]
//------------------------------------------------------------------------------
// DESCRIPTION: Header file of the abstract data type used to manipulate the 
//              colleges entity in the 'perfect matching' project.
//------------------------------------------------------------------------------
// AUTHOR: Renan Antunes Braga Bomtempo                    MATRICULA: 2018048524
//==============================================================================
#ifndef UNIV_H
#define UNIV_H

//Number of colleges in the read file
int g_num_colleges;

/*
 * Struct containing the college data.
 */
typedef struct college {
    //Quota of applications of the college.
    int quota;
    //Minimum score needed to apply for this college.
    int min_score;
    //Ordered list of the candidates that got into the college.
    int *selected_candidates;
    //Waiting list for the candidates that applied to this college.
    list *waiting_list;
} col;

/*
 * Create an array of type col.
 */
col *newCollegeArray(int n);

/*
 * Get colleges from file and store them into an array of type 'cand'.
 */
col *getCollegesFromFile(const char *file_name);

/*
 * Free all memmory allocated for the college array
 */
void freeCollegeArray(col *u);

#endif //UNIV_H