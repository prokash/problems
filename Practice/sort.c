//
//  sort.c
//  Practice
//
//  Created by Prokash Sinha on 11/28/19.
//  Copyright © 2019 Prokash Sinha. All rights reserved.
//

#include "sort.h"
#include <stdio.h>
#include <stdlib.h>



// Helper function to print given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

// Helper function to insert new Node in the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Takes two lists sorted in increasing order, and merge their nodes
// together to make one big sorted list which is returned
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    // Base cases
    if (a == NULL)
        return b;

    else if (b == NULL)
        return a;

    struct Node* result = NULL;

    // Pick either a or b, and recur
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

/*
Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
It uses the fast/slow pointer strategy
*/
void FrontBackSplit(struct Node* source, struct Node** frontRef,
                    struct Node** backRef)
{
    // if length is less than 2, handle separately
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    struct Node* slow = source;
    struct Node* fast = source->next;

    // Advance 'fast' two nodes, and advance 'slow' one node
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' is before the midpoint in the list, so split it in two
    // at that point.
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Sort given linked list using Merge sort algorithm
void MergeSort(struct Node** head)
{
    // Base case -- length 0 or 1
    if (*head == NULL || (*head)->next == NULL)
        return;

    struct Node* a;
    struct Node* b;

    // Split head into 'a' and 'b' sublists
    FrontBackSplit(*head, &a, &b);

    // Recursively sort the sublists
    MergeSort(&a);
    MergeSort(&b);

    // answer = merge the two sorted lists together
    *head = SortedMerge(a, b);
}

// Sort given linked list using Merge sort algorithm
int mergesortmain(void)
{
    // input keys
    int keys[] = { 6, 8, 4, 3, 1, 9 };
    int n = sizeof(keys)/sizeof(keys[0]);

    struct Node *head = NULL;
    for (int i = 0; i < n; i++)
        push(&head, keys[i]);

    // sort the list
    MergeSort(&head);

    // print the sorted list
    printList(head);

    return 0;
}
