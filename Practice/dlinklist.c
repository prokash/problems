//
//  dlinklist.c
//  Practice
//
//  Created by Prokash Sinha on 4/8/20.
//  Copyright © 2020 Prokash Sinha. All rights reserved.
//

#include "dlinklist.h"
#include <stdlib.h>

pdlink *head;


int dlnkInit ( pdlink *head)
{
    //sanity
    *head = malloc ( sizeof ( dlink ));
    
    if (*head != NULL)
        return -1;
    
    return 0;
}

int dlnkInsert ( pdlink elm, pdlink head)
{
    
    return 0;
}

int dlnkRemove ( pdlink elm, pdlink head)
{
    
    return 0;
}


