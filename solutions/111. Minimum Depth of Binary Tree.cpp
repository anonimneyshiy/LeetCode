#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
    	if (!root) {
    		return 0;
    	}
    	queue<TreeNode*> levels_of_tree;
    	levels_of_tree.push(root);

    	int min_depth = 0;
    	while (!levels_of_tree.empty()) {
    		int n = levels_of_tree.size();
    		min_depth++;
    		for (int i = 0; i < n; i++) {
    			if (!levels_of_tree.front()->right && !levels_of_tree.front()->left) {
    				return min_depth;
    			}
    			if (levels_of_tree.front()->left) {
    				levels_of_tree.push(levels_of_tree.front()->left);
    			}
    			if (levels_of_tree.front()->right) {
    				levels_of_tree.push(levels_of_tree.front()->right);
    			}
    			levels_of_tree.pop();
    		}
    	}
    }
    /* Recursive
	int minDepth(TreeNode* root) {
		if (!root) {
			return 0;
		}

        int left_height = minDepth(root->left);
        int right_height = minDepth(root->right);

        if(min(left_height, right_height) == 0) {
        	return max(left_height, right_height) + 1;
        }

        return min(left_height, right_height) + 1;
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
	cout << solution.minDepth(&node_1) << "\n";

	return 0;
}
