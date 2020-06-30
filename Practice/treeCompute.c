//
//  treeCompute.c
//  Practice
//
//  Created by Prokash Sinha on 4/18/20.
//  Copyright © 2020 Prokash Sinha. All rights reserved.
//

#include "treeCompute.h"

#define max(a, b)  ( (a) > (b) ? (a) : (b))
int height ( PNODE root)
{
    if (!root)
        return 0;
    
    return ( 1 + max ( height( root->l), height(root->r )) );
}

int isbalenced ( PNODE root)
{
    // empty tree is balenced
    if (!root)
        return 0;
    
    if (root->l && root->r) {
        
        int hl = height(root->l);
        int hr = height(root->r);
        int diff = abs ( hl - hr);
        return ( diff > 1 ? 0:1);
    }
    
    return 0;
    
}
