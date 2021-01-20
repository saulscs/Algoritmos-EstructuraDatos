/*
 * Cola implementado una lista enlazada
 *    
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE  256

struct element {
    char *name;
    struct element *next;
};

struct element *tail;

void init_queue (void);
void enqueue (char *name);
int dequeue (char *name);
void print_queue (void);
void error (char *msg);

int main (int argc, char **argv)
{
    char buf [BUFSIZE];

    init_queue ();

    while (1) {
        printf ("\n1: Enqueue\n2: Dequeue\n3: Print queue\n0: Quit\n\nEnter your choice: ");
        if (fgets (buf, BUFSIZE, stdin) == NULL)
            break;
        if (buf [0] == '1') {
           // Enqueue
           // Get name
           printf ("Name: ");
           if (fgets (buf, BUFSIZE, stdin) == NULL) 
               break;
           int len = strlen (buf);
           if (buf [len - 1] == '\n')
               buf [len - 1] = '\0';
           enqueue (buf);
        } else if (buf [0] == '2') {
           // Dequeue
           if (dequeue (buf) != -1)
               printf ("%s dequeued\n", buf);
        } else if (buf [0] == '3')
           print_queue ();
        else if (buf [0] == '0')
           break;
        else
            fprintf (stderr, "Error in input\n");
    }
    
    exit (0);
}

void init_queue (void)
{
    tail = NULL;
}

void enqueue (char *name)
{
    struct element *ptr;
    char *cp;

    if ((ptr = (struct element *) malloc (sizeof (struct element))) == NULL)
        error ("malloc");
    if ((cp = (char *) malloc (strlen (name) + 1)) == NULL)
        error ("malloc");

    strcpy (cp, name);
    ptr -> name = cp;

    if (tail == NULL) {
        ptr -> next = ptr;
    }
    else
    {
        ptr -> next = tail -> next;
        tail -> next = ptr;
    }
    tail = ptr;
}

int dequeue (char *name) // returns -1 on error
{
    struct element *ptr;
    char *cp;

    if (!tail) {
        fprintf (stderr, "Queue is empty\n");
        return -1;
    }
    // get the head
    ptr = tail -> next;
    cp = ptr -> name;

    if (ptr == tail)
        tail = NULL;
    else
        tail -> next = ptr -> next;
    free (ptr);
    strcpy (name, cp);
    free (cp);
    return 0;
}

void print_queue (void)
{

    struct element *ptr, *head;

    if (!tail) {
        fprintf (stderr, "Queue is empty\n");
        return;
    }

    printf ("Queue: \n");

    // get the head
    head = ptr = tail -> next;
    int i = 1;

    do {
        printf ("%d. %s\n", i, ptr -> name);
        ptr = ptr -> next;
        i++;
    } while (ptr != head);
}

void error (char *msg)
{
    perror (msg);
    exit (1);
}
