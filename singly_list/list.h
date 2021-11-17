#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;
node *freed(node *head);
node *separate_odd_even(node *head);
node *append(node *head, int data);
node *add_front(node *head, int data);
node *recursiveReverseLL(node *first);
node *reverse(node *head);
void printlist(node *t);
int middle(node *head);
