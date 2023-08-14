#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

 bool suma(struct TreeNode* root, int targetSum,int acum){

    if(!root)
        return false;
    acum += root->val;

    if(!root->left && !root->right)
        return acum == targetSum;

    bool iz = false;
    bool der = false;

    if (root->left)
        iz = suma(root->left, targetSum, acum);
    if(root->right)
        der = suma(root->right, targetSum, acum);

    return iz || der;
 }

 bool hasPathSum(struct TreeNode* root, int targetSum){

     return suma(root, targetSum,0);
 }

