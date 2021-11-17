
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main()
{
    node *head = NULL;
    head = append(head, 21);
    head = add_front(head, 23);
    head = append(head, 24);
    head = append(head, 22);
    head = add_front(head, 1);
    head = append(head, 12);
   // head = recursiveReverseLL(head);
  // head=separate_odd_even(head);
    // head = freed(head);
    int mid=middle(head);
    printf("middle is %d\n",mid);
    printlist(head);
    head = freed(head);
}