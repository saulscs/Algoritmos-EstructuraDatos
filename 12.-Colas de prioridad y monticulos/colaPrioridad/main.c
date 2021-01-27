
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PQ_func.h"

#define NUM_OF_ELEMENT 20

void print_PQ(PrioQ *);

int main(int argc, const char * argv[]) {
    PrioQ *myPrioQ;
    myPrioQ = PQ_create();
    
    double myKey = 0;
    double myData;
    
    
    /* call srand() and use time as the seed */
    srand((unsigned int)time(0));
    
    /* create a priority queue of 20 elements and print */
    for (int i = 0; i < NUM_OF_ELEMENT; ++i) {
        myKey = (rand() % 201) * 0.1;
        myData = 2.0;
        PQ_insert(myPrioQ, myKey, &myData);
    }
    print_PQ(myPrioQ);
    
    /* count the number of elements in priority queue */
    printf("there are %d elements in current priority queue\n\n", PQ_count(myPrioQ));
    
    /* delete elements and print */
    printf("delete item key     current length\n");
    for (int i = 0; i < NUM_OF_ELEMENT; ++i) {
        PQ_delete(myPrioQ, &myKey);
        printf("%5.2f                 %d\n", myKey, PQ_count(myPrioQ));
    }
    
    
    /* free the priority queue */
    PQ_free(myPrioQ);
    
    return 0;
}


/**
 *  function to print the whole priority queue
 */
void print_PQ(PrioQ *PQ) {
    double data = 0;
    
    if (PQ -> qNext == NULL) {
        printf("the priority queue is currently empty!\n");
    }
    
    printf("  KEY          DATA\n---------------------\n");
    while (PQ -> qNext != NULL) {
        data = *(double*) (PQ -> qNext -> qData);
        printf("%5.2f          %4.2f\n", PQ -> qNext -> qKey, data);
        PQ = PQ -> qNext;
    }
    printf("\n");
    return;
}