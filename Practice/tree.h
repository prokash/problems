//
//  tree.h
//  Practice
//
//  Created by Prokash Sinha on 11/28/19.
//  Copyright © 2019 Prokash Sinha. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _NODE_
{
    int value;
    struct _NODE_   *l;
    struct _NODE_   *r;
}NODE, *PNODE;

extern
void initTree ( PNODE *root, int value);

#endif /* tree_h */
