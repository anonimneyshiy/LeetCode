#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
        	current_sum = max(current_sum + nums[i], nums[i]);
        	max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};

ostream& operator<<(ostream& os, const vector<int>& v) {
	os << "{";
	bool flag = false;
	for (auto n : v) {
		if (flag) {
			os << ", ";
		}
		os << n;
		flag = true;
	}
	return os << "}";
}


int main() {

	vector<int> v1 = {-2, 1, -3, 4, 5, 6};
	vector<int> v2 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> v3 = {-2, -1, -3, -4, -5, -6};
	vector<int> v4 = {5, 4, -1, 7, 8};

	Solution solution;
	cout << "max subArray for v1 =" << v1 << "   with the sum = " << solution.maxSubArray(v1) << "\n";
	cout << "max subArray for v2 =" << v2 << "   with the sum = " << solution.maxSubArray(v2) << "\n";
	cout << "max subArray for v3 =" << v3 << "   with the sum = "  << solution.maxSubArray(v3) << "\n";
	cout << "max subArray for v4 =" << v4 << "   with the sum = " << solution.maxSubArray(v4) << "\n";

	return 0;
}
