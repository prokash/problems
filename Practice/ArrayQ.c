//
//  ArrayQ.c
//  Practice
//
//  Created by Prokash Sinha on 5/13/19.
//  Copyright © 2019 Prokash Sinha. All rights reserved.
//
#include <string.h>
#include <mach/i386/boolean.h>
#include "ArrayQ.h"

unsigned Length, Start;
unsigned MaxLen = 10;

void
InitQ( int Q[], int size)
{
    memset(Q, 0, size);
    
    return;
}

boolean_t
EmptyQ(int len)
{
    return ( len == 0 ? 1 : 0);
}

// -- don't need to indicate success or error for now
void
Enqueue( int Q[], int elmnt)
{
    //  Length <= MaxLen, Otherwise elmt loss
    if ( Length < MaxLen){
        Q[(Start + Length) % MaxLen] = elmnt;
        Length++;
    }
}

int
Dequeue ( int Q[])
{
    int temp = Q[Start];
    Start = (Start + 1)  % MaxLen;
    Length--;
    return temp;
}
