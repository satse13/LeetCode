#include <iostream>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* flatten2(TreeNode* root){

	

	if(!root->left && !root->right)
		return root;

	TreeNode* lastLeft = nullptr;
	TreeNode* right = nullptr;

	if(root->left)
		lastLeft = flatten2(root->left);
	if(root->right)
		right = flatten2(root->right);

	if(lastLeft)
		{lastLeft->right = root->right;
	root->right = root->left;
	root->left = nullptr;}

	if(right)
		return right;
	else 
		return lastLeft;
}
void flatten(TreeNode* root) {	
	if(!root) return;
	flatten2(root);
}


int main(){


	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	TreeNode e(5);
	TreeNode f(6);

	a.left = &b;
	a.right = &e;
	b.left = &c;
	b.right = &d;
	e.right = &f;

	flatten(&a);

	return 0;
}

