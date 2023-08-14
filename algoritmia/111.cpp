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


int altura(struct TreeNode* root, int alturaArbol){

    if(!root){
        return alturaArbol;
    }

    int iz = altura(root->left, alturaArbol+1);
    int der = altura(root->right, alturaArbol+1);

    if(iz == alturaArbol+1 && der != alturaArbol+1)
        return der;
    if(iz != alturaArbol+1 && der == alturaArbol+1)
        return iz;

    if(iz <= der) return iz;
        return der;
}

int minDepth(struct TreeNode* root){

     return altura(root, 0);
}
