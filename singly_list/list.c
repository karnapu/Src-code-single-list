#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node *freed(node *head)
{
    // node *t = head;
    // while (head)
    // {
    //     t = head;
    //     head = head->next;
    //     free(t);
    //     //t=head;
    // }
    // free(head);
    node *curr = NULL;
    while ((curr = head) != NULL)
    {                      // set curr to head, stop if list empty.
        head = head->next; // moving head to next element.
        free(curr);        // delete saved pointer.
    }
    head = NULL;
    return head;
}
//order may not like even one should always appear after odd
// 1->2->2->4->5->6
//even number 2->4->6->1->3->5
node* separate_odd_even(node *list)
{
    /*    if (head->next == NULL)
        return head;
    if (head == NULL)
        return NULL;
    node *temp = head;
    while (temp != NULL)
    {
        //if its even continue
        if (temp->data % 2 == 0)
        {
            temp = temp->next;
        }
        if (temp->data % 2 != 0)
        {
            //remove the current node and append to the last node
            node *r_node = temp;

            int data=temp->data;
            temp = temp->next;
            free(r_node);
            temp=append(temp,data);
        }
    }
    return head;

    */
    // this is used have link to head node
    node *evenhead = NULL, *oddhead = NULL, *temp;
    node *reven, *rodd;//this is used to store the link in between node's, In case of morethan one node 
    while (list != NULL)
    {
        //every time temp points to newnode at each iteration
        temp = malloc(sizeof(node));
        temp->data = list->data;
        temp->next = NULL;
        if (list->data % 2 == 0)
        {
            if (evenhead == NULL)
            {
                evenhead = temp;
            }
            else
            {
               // if more than one even node's
                //setting up reven link to point new node 
                reven->next = temp;
            }
            //at each iteration reven pointer to node is updated with linked to new
            reven = temp;
        }
        else
        {
            if (oddhead == NULL)
            {
                oddhead = temp;
            }
            else
            {
                rodd->next = temp;
            }
            rodd = temp;
        }
        list = list->next;
    }
    reven->next = oddhead;
    list = evenhead;
    return list;
}


node *append(node *head, int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    //check if the is node no node
    if (head == NULL)
    {
        //   head=new;
        return new;
    };
    //traverse till the last but one to append new node
    //should not modify the head
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = new;
    return head;
}
//finding the middle element in list if there are two middle return 2nd
int middle(node *head)
{  // slow pointer moves 1 node at each time
// fast pointer moves by 2 node at each time
    node *slow, *fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
node *add_front(node *head, int data)
{
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = head;
    head = new;
    return head;
}
node *recursiveReverseLL(node *first)
{

    if (first == NULL)
        return NULL; // list does not exist.

    if (first->next == NULL)
        return first; // list with only one node.

    node *rest = recursiveReverseLL(first->next); // recursive call on rest.

    first->next->next = first; // make first; link to the last node in the reversed rest.

    first->next = NULL; // since first is the new last, make its link NULL.

    return rest; // rest now points to the head of the reversed list.
}
// node* recursive_rev(node*head){
//     if (head==NULL)return;

// }
//reverse linkedlist using two pointers
// the idea is to make head as NULL and last node as head
node *reverse(node *head)
{
    // previous is used to make head->next as NULL and last node as head
    // if (head->next == NULL)
    // {
    //     //handle corner case if there is only one node in list
    //     return head ;
    // }
    node *previous = NULL;
    while (head)
    {
        node *next_node = head->next; //points to second node in list
        head->next = previous;
        previous = head;
        head = next_node; //moving forward by next node
    }

    return previous;
}
void printlist(node *t)
{
    if (t == NULL)
    {
        printf("empty list");
    }
    for (; t; t = t->next)
        printf("%d->", t->data);
}
