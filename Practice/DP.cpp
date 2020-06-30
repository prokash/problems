//
//  DP.cpp
//  Practice
//
//  Created by Prokash Sinha on 2/2/20.
//  Copyright © 2020 Prokash Sinha. All rights reserved.
//

#include "DP.hpp"
// A Naive recursive C++ program to find minimum of coins
// to make a given change V
//#include<bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
// base case
if (V == 0) return 0;

// Initialize result
int res = INT_MAX;

// Try every coin that has smaller value than V
for (int i=0; i<m; i++)
{
    if (coins[i] <= V)
    {
        int sub_res = minCoins(coins, m, V-coins[i]);

        // Check for INT_MAX to avoid overflow and see if
        // result can minimized
        if (sub_res != INT_MAX && sub_res + 1 < res)
            res = sub_res + 1;
    }
}
return res;
}

// Driver program to test above function
int minNbCoinsmain()
{
    int coins[] = {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "
        << minCoins(coins, m, V);
    return 0;
}


/* All possbile changes (of coins) to make the Total Sum from a set of coins
 coins[] is array of coin values; {1,5,10,25,50} penny, nickle, dime, quarter, half-dollar
 
 Analysis --
 1) Coins that total upto Sum does not include a specific coin, say no 5 cents
 2) Coins that total upto Sum includes at least one specific coin, say one or more pennyies
 
 In general either no ith coin added, or at least one ith coin added
 
 Recursively --
 Let count(S[], m, n) be the function to count the number of solutions, then it can be written as sum of count(S[], m-1, n) and count(S[], m, n-Sm).
 
    count(S[], m, n) = count(S[], m-1, n) + count( S[], m, n - S[m] )
 */

// Recursive C program for
// coin change problem.
#include<stdio.h>

// Returns the count of ways we can
// sum S[0...m-1] coins to get sum n
int count( int S[], int m, int n )
{
    // If n is 0 then there is 1 solution
    // (do not include any coin)
    if (n == 0)
        return 1;
    
    // If n is less than 0 then no
    // solution exists
    if (n < 0)
        return 0;

    // If there are no coins and n
    // is greater than 0, then no
    // solution exist
    if (m <=0 && n >= 1)
        return 0;

    // count is sum of solutions
    // (i)including S[m-1]       (ii) excluding S[m-1]
    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}

// Driver program to test above function
int countways2getchangesmain()
{
    int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", count(arr, m, 4));
    getchar();
    return 0;
}



