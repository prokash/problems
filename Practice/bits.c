//
//  bits.c
//  Practice
//
//  Created by Prokash Sinha on 11/28/19.
//  Copyright © 2019 Prokash Sinha. All rights reserved.
//

#include "bits.h"

/*
get rightmost set bit,

x & -x
// or
x & (~x + 1)
*/


/*
 unset rightmost set bit,
 
 x &= x - 1
 // or
 x -= x & -x  // rhs is rightmost set bit
 */


// worst case = O(n). Avg = O(n)
int countBitsBrut1 ( int K)
{
    int n = sizeof (int) * 8 ;
    int numbits = 0;
    for ( int i = 0; i < n; i++ )
    {
        if ( K & 1 ){
            numbits++;
        }
        K >>= 1; // K = K >> 1
    }
    return numbits ;
}

// worst case = O(n). Avg = O(n/2)
int countBitsBrut2 ( int K )
{
    //int n = sizeof (int) * 8 ;
    int numbits = 0;
    while ( K )
    {
        numbits += K & 1;
        K >>= 1; // K = K >> 1
    }
    return numbits ;
}

// Only for the number of bits

// worst case = O(#of bits in K ). Avg = O(#of bits in K)
int countBitsOptimize1 ( int K )
{
    //int n = sizeof (int) * 8 ;
    int numbits = 0;
    while ( K )
    {
        numbits += 1;
        K = K & (K-1);
    }
    return numbits ;
}

// worst case = O(n). Avg = O(n/2)
int countBitsOptimize2 ( int K )
{
    //int n = sizeof (int) * 8 ;
    int numbits = 0;
    while ( K )
    {
        numbits += K & 1;
        K >>= 1; // K = K >> 1
    }
    return numbits ;
}

// ~ operator is 1's complement

int onescomplement ( int K)
{
    return ~K;
}

int binaryRep = 0b10101010;

int twoscomplement ( int K )
{
    int twoscomp = onescomplement ( K ) + 1;
    //
    //check
    if ( (twoscomp - K ) == 0)
        printf( " Correct twos complement... \n");
    
    return onescomplement ( K ) + 1;
    
}

// No bit operation, addition, substraction TWOSCOMPLEMENT

/*
 Step by step descriptive logic to find twos complement of a binary string.
 
 Input a binary string from user. Store it in a variable say binary.
 Find ones complement of the binary string. Store the result in some variable say onesComp.
 Declare and initialize another binary string variable to store twos complement, say twosComp = "".
 Initialize a variable to store carry bit during addition, say carry = 1.
 You may think now, why initialize carry to 1, why not 0? Since, we need to add only 1 to the binary string hence, I have initially assumed carry bit as the bit to be added.
 
 Run a loop from length of binary string to 1, decrement 1 in each iteration. The loop structure should look like for(i=SIZE-1; i>=1; i--) (where SIZE is length of the binary string).
 You may think, why iterating in reverse order? Because addition is carried out in right to left order.
 
 Inside the loop there can be three cases.
 If both current binary bit and carry bit are 1 then, put 0 to twos complement. Which is if(onesComp[i]=='1' && carry==1) then, twosComp[i] = '0', carry is still preserved to 1.
 If current binary bit is 0 and carry bit is 1 then, put 1 to twos complement and set carry bit to 0. Which is if(onesComp[i]=='0' && carry==1) then, twosComp[i] = '1' and carry = 0.
 If carry bit is 0, then assign the value of onesComp to twosComp.
 
 */

#define SIZE 8

int towsComplementWithout_OPS()
{
    char binary[SIZE + 1], onesComp[SIZE + 1], twosComp[SIZE + 1];
    int i, carry=1; // we need to add one, so carry plays that role first
    
    printf("Enter %d bit binary value: ", SIZE);
    
    /* Input 8-bit binary string */
    gets(binary);
    
    /* Find ones complement of the binary number */
    for(i=0; i<SIZE; i++)
    {
        if(binary[i] == '1')
        {
            onesComp[i] = '0';
        }
        else if(binary[i] == '0')
        {
            onesComp[i] = '1';
        }
    }
    onesComp[SIZE] = '\0';
    
    /*
     * Add 1 to the ones complement
     */
    for(i=SIZE-1; i>=0; i--)
    {
        if(onesComp[i] == '1' && carry == 1)
        {
            twosComp[i] = '0';
        }
        else if(onesComp[i] == '0' && carry == 1)
        {
            twosComp[i] = '1';
            carry = 0;
        }
        else
        {
            twosComp[i] = onesComp[i];
        }
    }
    twosComp[SIZE] = '\0';
    
    printf("Original binary = %s\n", binary);
    printf("Ones complement = %s\n", onesComp);
    printf("Twos complement = %s\n", twosComp);
    
    return 0;
}

int countmaxsetbits ( int n)
{
    int max =0, curmax =0;
    
    while ( n ){
        
        if ( n & 1){
            curmax ++;
            
        }else {
            if (curmax > max){
                max = curmax;
                curmax = 0;
            }
        }
        n = n >> 1;
        
    }
    if (curmax > max){
        max = curmax;
    }
    return max;
}

void main_countmaxsetbits ()
{
    printf( "n = %d, bits = %d\n", 222, countmaxsetbits(222) );
    printf( "n = %d, bits = %d\n", 15, countmaxsetbits(15) );
    printf( "n = %d, bits = %d\n", 13, countmaxsetbits(13) );
}
