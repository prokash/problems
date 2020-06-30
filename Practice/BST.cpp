//
//  BST.cpp
//  Practice
//
//  Created by Prokash Sinha on 1/13/20.
//  Copyright © 2020 Prokash Sinha. All rights reserved.
//

#include "BST.hpp"

// #define ACTIVE
#ifdef ACTIVE
using std:: ;

bool isBSTCore_Solution1(BinaryTreeNode* pRoot, int min, int max) {
     if(pRoot == NULL)
         return true;

if(pRoot->nValue < min || pRoot->nValue > max)
         return false;
     return isBSTCore_Solution1(pRoot->pLeft, min, pRoot->nValue)
         && isBSTCore_Solution1(pRoot->pRight, pRoot->nValue, max);
 }


bool isBST_Solution1(BinaryTreeNode* pRoot) {
     int min = numeric_limits<int>::min();
     int max = numeric_limits<int>::max();
     return isBSTCore_Solution1(pRoot, min, max);
 }
 
#endif
