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
    bool hasPathSum(TreeNode* root, int targetSum) {
    	if (!root) {
    		return false;
    	}

    	targetSum -= root->val;
    	if (targetSum == 0 && !root->left && !root->right) {
    		return true;
    	}

    	return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};


int main() {

	TreeNode node_3_l(15);
	TreeNode node_3_r(7);
	TreeNode node_2_r(20, &node_3_l, &node_3_r);
	TreeNode node_2_l(9);
	TreeNode node_1(3, &node_2_l, &node_2_r);

	Solution solution;
	cout << solution.hasPathSum(&node_1, 38) << "\n";

	return 0;
}
