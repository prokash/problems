//
//  Array.c
//  Practice
//
//  Created by Prokash Sinha on 3/23/19.
//  Copyright © 2019 Prokash Sinha. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#include "Array.h"
/* A[]
 * Max, Min
 * Duplicate
 * Array Product- P[i] == P[0 ... i-1] * P[i ... N-1] So P[i] = products of all elements except A[i]
 *
 */
int MaxArr ( int A[], int len)
{
    assert(len > 0 );
    int currentMax = -1;
    for (int i = 0; i < len; i++){
        if ( currentMax < A[i])
            currentMax = A[i];
    }
    return currentMax;
}

// reverse an int
int reverse ( int n)
{
    //reverse the int
    int rev = 0;
    while ( n > 0){
        int res = n % 10;
        rev = rev * 10 + res;
        n = n / 10;
    }
    return rev;
}
//finding if a number is palindrom
int intPalindrom ( int n)
{
    int rev = reverse(n);
    
    if (rev == n){
        printf(" %d is a plaindrom\n", n);
    }else{
        printf(" %d is NOT a palindrom\n", n);
    }
               
               return 0;
}
// -- check/print/find if an array A[] has a+b = Sum, where a and b are elements of A[]

// --- If we sort, then we can check moving from both end to check for the sum
/*
 * left = 0; right = n-1;
 * while ( left < right ){
 *    if ( A[left] + Aright] == sum ) {
          found a pair that adds to sum
      }else if ( A[left] + A[right] < sum ) {
          left++;
      }else right--;
   }
 
 */

// -- O(n) time, O(???) space - can we reduce the size of
#define MAX 1000000
void
findElmSum(  int Sum, int A[], int len)
{
    int Hash[1000000] = {0};
    
    
    for (int i =0; i < len; i++){
        int temp = Sum - A[i];
        if ( temp >= 0 && temp < MAX && Hash[temp] == 1){
            printf("Found Sum=%d %d + %d\n", Sum, A[i], temp);
            
        }
        Hash[ A[i] ] = 1;
    }
    
}

void
findElmSumMem(  int Sum, int A[], int len)
{
    int Hash[Sum+1];
    
    
    for (int i =0; i < len; i++){
        int temp = Sum - A[i];
        if ( temp >= 0 && temp < Sum + 1 && Hash[temp] == 1){
            printf("Found Sum=%d %d + %d\n", Sum, A[i], temp);
            
        }
        Hash[ A[i] ] = 1;
    }
    
}
int maxOfArray(int A[], int i, int j)
{
    int maxIdx = j;
    int curmax = A[j];
    
    for (int idx = i; idx < j; idx++){
        
        if ( A[idx] > curmax){
            maxIdx = idx;
            curmax = A[idx];
        }
        
    }
    
    return maxIdx;
}

int minOfArray(int A[], int i, int j)
{
    int minIdx = i;
    int curmin = A[i];
    for (int idx = i+1; idx <= j; idx++){
        
        if ( A[idx] < curmin){
            minIdx = idx;
            curmin = A[idx];
        }
    }
    
    return minIdx;
}
//--
//-- Given an unsorted array, find the subarray needs sorting to make the Array sorted
//
void findMinIndexToSort( int A[], int length)
{
    unsigned i =0, j= 0;
    
    for ( i = 0; i < length - 1; i++)
    {
        if ( A[i] > A[i+1])
            break;
    }
    
    if ( i == length -1){
        printf("A[] sorted...\n");
    }
    
    for ( j = length-1; j>0; j--){
        if ( A[j] <  A[j-1])
            break;
        
    }
    printf("i=%d, j=%d\n", i, j);
    
    int minIdx = minOfArray(A, i, j);
    int maxIdx = maxOfArray(A, i, j);
    
    // i <= minIdx <= j
    for (int k = 0; k <= i; k++)
    {
        if ( A[minIdx] < A[k]){
            i = k;
            break;
        }
            
    }
    // j >= maxIdx >= i
    for (int k = length -1; k >= j; k--){
        
        if ( A[maxIdx] > A[k]){
            j = k;
            break;
        }
    }
    
    printf("Final --- i=%d, j=%d\n", i, j);
    
    
}

void main_findIndicesToSort ()
{
    int A[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int n = sizeof(A)/sizeof(A[0]);
    findMinIndexToSort(A, n);
}

void main_findSum ()
{
    int A[] = {1, 4, 45, 6, 10, 8};

    int n = sizeof(A)/sizeof(A[0]);
    //
    findElmSumMem(55 , A, n);
}

void array_main(void)
{
   // main_findSum ();
    main_findIndicesToSort();
}
