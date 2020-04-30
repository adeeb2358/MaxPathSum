//
//  main.cpp
//  MaxPathSum
//
//  Created by adeeb mohammed on 30/04/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//  program to obtain max path in a binary tree
//  time complexity is o(n) space complecity is o(d)

#include <iostream>
#include <vector>


class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(std::vector<int> values, int i = 0);
};


std::vector<int> maxSums(BinaryTree *tree){
    if(tree == NULL){
        return std::vector<int>{0,0};
    }
    
    std::vector<int> leftMaxSumArray = maxSums(tree->left);
    int leftMaxSumAsBranch           = leftMaxSumArray.at(0);
    int leftMaxPathSum               = leftMaxSumArray.at(1);
    
    std::vector<int> rightMaxSumArray = maxSums(tree->right);
    // branch sum
    int rightMaxSumAsBranch = rightMaxSumArray.at(0);
    // path sum
    int rightMaxPathSum     = rightMaxSumArray.at(1);
        
    // child sum
    int childMaxSumAsBranch = std::max(rightMaxSumAsBranch, leftMaxSumAsBranch);
    // max Sum as branch
    int maxSumAsBranch = std::max(childMaxSumAsBranch+tree->value,tree->value);
    // sum as triangle
    int maxSumAsRoot = std::max(leftMaxSumAsBranch+tree->value+rightMaxSumAsBranch,maxSumAsBranch);
    // running path sum
    int maxPathSum = std::max(leftMaxPathSum, std::max(rightMaxPathSum, maxSumAsRoot));
    
    return std::vector<int>{maxSumAsBranch,maxPathSum};
}

int maxPathSum(BinaryTree tree) {
    std::vector<int> sumArray = maxSums(&tree);
    return sumArray.at(1);
}


int main(int argc, const char * argv[]) {
    std::cout << "Program for max path sum" << std::endl;
    return 0;
}
