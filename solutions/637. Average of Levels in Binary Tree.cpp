#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <numeric>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
    					: val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result_sum;

        queue<TreeNode*> levels;
        levels.push(root);

        while (!levels.empty()) {
        	int n = levels.size();
        	double current_sum = 0;
        	for (int i = 0; i < n; i++) {
        		current_sum += levels.front()->val;
        		if (levels.front()->left) {
        			levels.push(levels.front()->left);
        		}
        		if (levels.front()->right) {
        			levels.push(levels.front()->right);
        		}
        		levels.pop();
        	}
        	result_sum.push_back(current_sum / n);
        }

        return result_sum;
    }
};

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "{";
	bool flag = false;
	for (T n : v) {
		if (flag) {
			os << ", ";
		}
		os << n;
		flag = true;
	}
	return os << "}";
}


int main() {

	TreeNode node_3_l(15);
	TreeNode node_3_r(7);
	TreeNode node_2_r(20, &node_3_l, &node_3_r);
	TreeNode node_2_l(9);
	TreeNode node_1(3, &node_2_l, &node_2_r);

	Solution solution;
	cout << solution.averageOfLevels(&node_1) << "\n";

	return 0;
}





