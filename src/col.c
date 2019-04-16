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
        ptr[i].index = i;
        ptr[i].min_score = -1;
        ptr[i].quota = -1;
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

    /*//========================BEGIN-LOG-BLOCK==========================
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
    //=========================END-LOG-BLOCK===========================*/

    //Close file
    fclose(fp);

    return colleges;
}

void freeCollegeArray(col *c)
{    
    //Free college array
    free(c);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * The following functions are designed to manipulate the waiting list of each *
 * college.                                                                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void addToWaitingList(list **l, cand *c)
{
    list *ptr = *l;
    
    //Allocate memory
    list *new_item = (list*)malloc(sizeof(list));
    if (new_item == NULL) 
    {
        perror("ERROR - Could not allocate memory for an item on the waiting list!");
        exit(EXIT_FAILURE);
    }

    //Set item values
    new_item->candidate = c;
    new_item->next = NULL;
    
    //Replace next pointer to be to the new item created
    if (ptr == NULL) 
    {
        *l = new_item;
    } 
    else 
    {
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_item;
    }   
}

void resetWaitingList(list **l)
{
    if (*l != NULL)
    {
        list *cur;
        while((*l)->next != NULL)
        {
            cur = *l;
            *l = (*l)->next;
            free(cur);
        }
        free(*l);
    }

    *l = NULL;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * The following functions are designed to order the waiting list according to *
 * each candidates score (from highest to lowest) using Quicksort.             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void orderWaitingList(list **waiting_list) 
{ 
    (*waiting_list) = quickSortRecursion(*waiting_list, getLastCandidate(*waiting_list));
} 

list *quickSortRecursion(list *l, list *end) 
{ 
    // base condition 
    if (l == NULL || l == end) 
        return l; 
  
    list *new_head = NULL;
    list *new_end = NULL; 
  
    // Partition the list
    list *pivot = partition(l, end, &new_head, &new_end); 
  
    // If pivot doesn't have the greatest score
    if (new_head != pivot) 
    { 
        // Set the item before the pivot item as NULL 
        list *temp = new_head; 
        while (temp->next != pivot) 
            temp = temp->next; 
        temp->next = NULL; 
  
        // Recur for the list before pivot 
        new_head = quickSortRecursion(new_head, temp); 
  
        // Change next of last item of the left half to pivot 
        temp = getLastCandidate(new_head); 
        temp->next =  pivot; 
    } 
  
    // Recur for the list after the pivot 
    pivot->next = quickSortRecursion(pivot->next, new_end); 
  
    return new_head; 
} 

list *getLastCandidate(list *ptr) 
{ 
    while (ptr != NULL && ptr->next != NULL) 
        ptr = ptr->next; 
    return ptr; 
} 
  
list *partition(list *l, list *end, list **new_head, list **new_end) 
{ 
    list *pivot = end; 
    list *tail = pivot; 
    //Previous candidate
    list *prev = NULL;
    //Current candidate
    list *ptr = l;

    while (ptr != pivot) 
    { 
        if (ptr->candidate->score >= pivot->candidate->score) 
        { 
            //Candidate with higher score becomes the head of partition
            if ((*new_head) == NULL) 
                (*new_head) = ptr; 
  
            prev = ptr;   
            ptr = ptr->next; 
        } 
        else //If ptr candidate has a lower score than pivot, move it to the end
        {
            list *temp = ptr->next; 
            
            if (prev != NULL) 
                prev->next = ptr->next; 
            
            ptr->next = NULL;
            tail->next = ptr; 
            tail = ptr; 
            ptr = temp; 
        } 
    } 
  
    // If the pivot candidate score is the higher in the current list it becomes the head
    if ((*new_head) == NULL) 
        (*new_head) = pivot; 
  
    // Update new_end to the current last candidate 
    (*new_end) = tail; 
  
    return pivot; 
} 