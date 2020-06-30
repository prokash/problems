//
//  string.c
//  Practice
//
//  Created by Prokash Sinha on 3/23/19.
//  Copyright © 2019 Prokash Sinha. All rights reserved.
//

#include "string.h"

/*
 * c string related --
 * Given a string , count the number of characters ( frequency ) of each char
 */

/* assume just ascii char string. i.e. a...z and A...Z => 26 * 2 elements needed for the array */
void charFreqinStr( char *str)
{
    unsigned int charFreq[52] = {0};
    
    while ( *str != '\0'){
        charFreq[*str - '0']++;
        str++;
    }
    //print charFreq[] array
    return;
}

/*
 Steve has a string of lowercase characters in range ascii[‘a’..’z’]. He wants to reduce the string to its shortest length by doing a series of operations. In each operation he selects a pair of adjacent lowercase letters that match, and he deletes them. For instance, the string aab could be shortened to b in one operation.
 Steve’s task is to delete as many characters as possible using this method and print the resulting string. If the final string is empty, print Empty String
 
 aaabccddd → abccddd → abddd → abd
 
 baab → bb → Empty String
 */

char * superReducedString(char * str)
{
    char *s = str;
    bool found = false;
    if (!s){
        printf("Empty String");
    }
    
    unsigned long len = strlen(s);
    char *A = (char *) malloc(len+1);
    memset ( A, 0, len);
    
    while (1){
        
        int j = 0;
        
        for ( int i =0; i < len -1; i++){
            if (s[i] == s[i+1]){
                found = true;
                continue;
            }else {
                A[j++] = A[i];
            }
        }
        
        A[j] = '\0';
        memcpy(s, A, j);
        if (!found) {
            // no more successive dup
            break;
        }
            
        
    }
    return s;
}
    


