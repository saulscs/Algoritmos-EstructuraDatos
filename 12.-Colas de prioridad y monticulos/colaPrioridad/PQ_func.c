#include <stdio.h>
#include <stdlib.h>
#include "PQ_func.h"


/**
 *  function to create a new priority queue and return a ptr to it
 */
PrioQ *PQ_create(void) {
    PrioQ *PQ;
    PQ = malloc(sizeof(PrioQ));
    if (PQ == NULL) {
        printf("Memory allocation error. Abort.\n");
    }
    
    PQ -> qKey = 0;
    PQ -> qData = NULL;
    PQ -> qNext = NULL;
    
    return PQ;
}


/**
 *  function to insert item to priority queue
 */
int PQ_insert(PrioQ *PQ, double key, void *data) {
    /* create a new node to store key and data */
    PrioQ *newItem;
    newItem = (PrioQ *)malloc(sizeof(PrioQ));
    /* check if memory allocation succeed */
    if (newItem == NULL) {
        printf("Memory allocation of new item error. Abort.\n");
        return 0;
    }
    /* set the input key and data to the new node */
    newItem -> qKey = key;
    newItem -> qData = data;
    
    /* create temp pointer to store the original queue */
    PrioQ *tempQueue;
    tempQueue = PQ;
    
    /* find the place to insert the new node */
    if (tempQueue -> qNext != NULL) {
        while (newItem -> qKey > tempQueue -> qNext -> qKey) {
            tempQueue = tempQueue -> qNext;
            if (tempQueue -> qNext == NULL) { break; }
        }
    }
    
    /* insert new node */
    newItem -> qNext = tempQueue -> qNext;
    tempQueue -> qNext = newItem;
    
    return 1;
}


/**
 *  function to remove the item in PrioQ with the smallest key (highest priority)
 */
void *PQ_delete(PrioQ *PQ, double *key){
    /* if priority queue is empty, return NULL */
    if (PQ ->qNext == NULL) {
        return NULL;
    }
    
    PrioQ *deletedPQ;
    void *deletedData;
    
    /* set deletedPQ as the first node in current Priority Queue */
    deletedPQ = PQ -> qNext;
    /* store data of deleted node */
    deletedData = deletedPQ -> qData;
    /* return the key of deleted node to key */
    *key = deletedPQ -> qKey;
    
    /* update the first node in PQ */
    PQ -> qNext = deletedPQ -> qNext;
    
    free(deletedPQ);
    
    
    return deletedData;
    
}


/**
 *  function to count current number of items residing in priority queue
 */
unsigned int PQ_count(PrioQ *PQ) {
    unsigned int count = 0;
    /* loop through every node in priority queue and count */
    while (PQ -> qNext != NULL) {
        PQ = PQ -> qNext;
        ++count;
    }
    
    return count;
}


/**
 *  function to delete PQ by deleting all memory used by priority queue
 */
void *PQ_free(struct PrioQ *PQ){
    
    PrioQ *temp;
    /* loop through all items in queue to release memory */
    while (PQ -> qNext != NULL) {
        temp = PQ -> qNext;
        free(PQ);
        PQ = temp;
    }
    
    /* release the last item in queue */
    free(PQ);
    return NULL;
}
