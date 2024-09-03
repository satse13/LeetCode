#include<iostream>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

int main(){


	return 0;
}

pair<TreeNode*,int>f(TreeNode* a)
    {
        if(!a) return {nullptr,0};

        pair<TreeNode*,int> l=f(a->left);
        pair<TreeNode*,int> r=f(a->right);

        if(r.second>l.second) return {r.first,r.second+1};
        else if(l.second>r.second) return {l.first,l.second+1};
        else return {a,l.second+1};
    }
TreeNode* subtreeWithAllDeepest(TreeNode* a) {
		return f(a).first;
}