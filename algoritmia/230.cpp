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


int kthSmallest(TreeNode* root, int k);
int dfs(TreeNode* root, int k, int cont, bool& sol);
int main(){


	


	return 0;
}

int dfs(TreeNode* root, int k, int cont, bool& sol){

	if(!root) return cont;

	if(root->left){
		cont = dfs(root->left, k, cont, sol);
	}

	if(sol) return cont;

	cont++;

	if(cont == k) {
		sol = true;
		return root->val;
	}


	if(root->right){
		cont = dfs(root->right, k, cont, sol);
	}

	return cont;

}

int kthSmallest(TreeNode* root, int k) {
	
	int sol = 0;
	bool solved = false;

	return dfs(root, k, sol, solved);

	

}