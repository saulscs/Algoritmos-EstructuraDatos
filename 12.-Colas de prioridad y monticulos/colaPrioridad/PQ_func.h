#ifndef PQ_func_h
#define PQ_func_h

typedef struct PrioQ{
    double qKey;
    void *qData;
    struct PrioQ *qNext;
}PrioQ;

PrioQ *PQ_create(void);

int PQ_insert(PrioQ *PQ, double key, void *data);

void *PQ_delete(PrioQ *PQ, double *key);

unsigned int PQ_count(PrioQ *PQ);

void *PQ_free(struct PrioQ *PQ);


#endif /* PQ_func_h */