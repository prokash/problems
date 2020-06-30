//
//  list.c
//  Practice
//
//  Created by Prokash Sinha on 11/28/19.
//  Copyright © 2019 Prokash Sinha. All rights reserved.
//

#include "list.h"
//#include <memory.h>
#include <stdlib.h>
typedef struct _node *pnode;

int listsum ( pnode head)
{
    int Sum = 0;
    pnode h = head;
    while(h){
        Sum = Sum + h->value;
        h = h->next;
    }
    
    return Sum;
}


// root: head node. list is sorted
//
pnode  removeDuplicates(pnode root)
{
 // your code goes here
 pnode r = root;
 while (r && r->next){
     if ( r->value == r->next->value){
         pnode tmp = r->next;
         r->next = r->next->next;
         free(tmp);
     } else {
         r = r->next;
     }
      
 }
    
 return root;
    
}
 
// -- In place
pnode listreverse ( pnode head)
{
    pnode h = head;
    pnode tail = NULL;
    
    while (h){
        pnode tmp = h;
        h = h->next;
        tmp->next = NULL;
        tail = tmp;
        tail = tail->next;
        
    }
    return head;
}
