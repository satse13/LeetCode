#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidBST(TreeNode* root);
bool isValidBSTAux(TreeNode* root, long long min, long long max);

int main(){

	TreeNode a(5);
	TreeNode b(4);
	TreeNode c(6);
	TreeNode d(3);
	TreeNode e(7);

	a.left = &b;
	a.right = &c;	
	c.left = &d;
	c.right = &e;



	bool y = isValidBST(&a);

	return 0;
}

bool isValidBST(TreeNode* root) {
    if(!root) return true;

	return isValidBSTAux(root->left, LONG_LONG_MIN, root->val) && isValidBSTAux(root->right, root->val,LONG_LONG_MAX);
}

bool isValidBSTAux(TreeNode* root, long long min, long long max) {

	if(!root) return true;

	if(root->val <= min || root->val >= max) return false;

	return isValidBSTAux(root->left, min, root->val) && isValidBSTAux(root->right, root->val, max);
}

// al arbol derecho le paso un minimo y al izuierdo un maximo