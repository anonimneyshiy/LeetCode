#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
   bool isSameTree(TreeNode* p, TreeNode* q) {
	   if (!p && !q) {
		   return true;
	   }
	   if (!p || !q) {
		   return false;
	   }

	   queue<TreeNode*> levels_of_tree_p, levels_of_tree_q;
	   levels_of_tree_p.push(p);
	   levels_of_tree_q.push(q);

	   while (!levels_of_tree_p.empty() && !levels_of_tree_q.empty()) {
		   int n_p = levels_of_tree_p.size(), n_q = levels_of_tree_q.size();
		   if (n_p != n_q) {
			   return false;
		   }

		   for (int i = 0; i < n_p; i++) {
			   if (levels_of_tree_p.front()->val != levels_of_tree_q.front()->val) {
				   return false;
			   }
			   if (levels_of_tree_p.front()->left && levels_of_tree_q.front()->left) {
				   levels_of_tree_p.push(levels_of_tree_p.front()->left);
				   levels_of_tree_q.push(levels_of_tree_q.front()->left);
			   }
			   if ((!levels_of_tree_p.front()->left && levels_of_tree_q.front()->left)
					   || (levels_of_tree_p.front()->left && !levels_of_tree_q.front()->left)) {
				   return false;
			   }
			   if (levels_of_tree_p.front()->right && levels_of_tree_q.front()->right) {
				   levels_of_tree_p.push(levels_of_tree_p.front()->right);
				   levels_of_tree_q.push(levels_of_tree_q.front()->right);
			   }
			   if ((!levels_of_tree_p.front()->right && levels_of_tree_q.front()->right)
					   || (levels_of_tree_p.front()->right && !levels_of_tree_q.front()->right)) {
				   return false;
			   }
			   levels_of_tree_p.pop();
			   levels_of_tree_q.pop();
		   }
	   }

	   return true;
   }

    /* Recursive solution
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q) {
			return true;
		}
		if (!p || !q) {
			return false;
		}
		if (p->val != q->val) {
			return false;
		}

		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
	*/
};


int main() {

	TreeNode node_3_l(15);
	TreeNode node_3_r(7);
	TreeNode node_2_r(20, &node_3_l, &node_3_r);
	TreeNode node_2_l(9);
	TreeNode node_1(3, &node_2_l, &node_2_r);

	Solution solution;
	cout << solution.isSameTree(&node_1, &node_1) << "\n";

	return 0;
}

