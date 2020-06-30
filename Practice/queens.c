//
//  queens.c
//  Practice
//
//  Created by Prokash Sinha on 2/5/20.
//  Copyright © 2020 Prokash Sinha. All rights reserved.
//

#include "queens.h"

/*
 

PlaceQueens(Q[1 .. n], r):
 if r = n + 1
    print Q[1 .. n]
 else
    for j ← 1 to n   --- loop over all the position in the r row
        legal ← True
        for i ← 1 to r − 1 ---- loop over what we placed so far
            if(Q[i]= j) or (Q[i]= j+r−i) or (Q[i]= j−r+i)
                legal ← False
 
        if legal
            Q[r] ← j
 
        PlaceQueens(Q[1 .. n], r + 1) 〈Recursion!〉〉
 end
*/
void Print(int A[], int dim)
{
    for ( int i = 0 ; i < dim; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");
}
void PlaceQueens ( int Q[], int dim, int r)
{
    if ( r == dim +1 ) {
        Print(Q, dim);
        return;
    }
    int recurse = 0;
    // -- search for column to place rth queen
    for ( int j = 0; j < dim; j++){
        int legal = 1;
        for ( int i = 0; i < r -1 ; i++){
            if ( ( Q[i] == j ) // jth colm is occupied
                || ( Q[i] == j + r -i ) //
                || (Q[i] == j + i -r) ){
                legal = 0;
                break;  // this colmn j is not good
            }
        }
        if ( legal){
            Q[r] = j;
            recurse = 1;
            break;
            
        }
    }
    
    if ( recurse )
        PlaceQueens(Q, dim,  r + 1 );
    
}


