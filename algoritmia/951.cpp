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


bool flipEquiv(TreeNode* root1, TreeNode* root2) {

	 if(root1==NULL && root2==NULL)
        return true;
        if(root1==NULL || root2==NULL)
        return false;
        if(root1->val!=root2->val)
        return false;
        bool b= flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
        bool c= flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);
        return b || c;  

}

int main(){


	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	TreeNode e(5);
	TreeNode f(6);
	TreeNode g(7);
	TreeNode h(8);

	TreeNode i(1);
	TreeNode j(2);
	TreeNode k(3);
	TreeNode l(4);
	TreeNode m(5);
	TreeNode n(6);
	TreeNode o(7);
	TreeNode p(8);

	a.left = &b;
	a.right= &c;
	b.left = &d;
	b.right = &e;
	e.left = &g;
	e.right = &h;
	c.left = &f;

	i.left = &k;
	k.right = &n;

	i.right = &j;
	j.left = &l;
	j.right = &m;
	m.left = &p;
	m.right = &o;


	if(flipEquiv(&a,&i)) {
		cout << "true";
	}
	else 
		cout << "false";

	return 0;
}