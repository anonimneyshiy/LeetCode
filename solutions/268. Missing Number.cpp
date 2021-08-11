#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int expected_sum = (1 + nums.size()) * nums.size() / 2;
        int real_sum = accumulate(nums.begin(), nums.end(), 0);
        return expected_sum - real_sum;
    }
};


int main() {

	vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};

	Solution solution;
	cout << solution.missingNumber(nums) << endl;

	return 0;
}
