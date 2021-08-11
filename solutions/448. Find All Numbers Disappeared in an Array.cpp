#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v);

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

    	size_t i = 0;
    	while (i < nums.size()) {
    		int true_positional = nums[i] - 1;
    		if (nums[true_positional] != nums[i]) {
    			swap(nums[true_positional], nums[i]);
    		}
    		else {
    			i++;
    		}
    	}
    	cout << nums << endl;

    	vector<int> disappeared_nums;
    	for (size_t i = 0; i < nums.size(); i++) {
    		if (nums[i] != i + 1) {
    			disappeared_nums.push_back(i + 1);
    		}
    	}

    	return disappeared_nums;
    }
};

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "{";
	bool flag = false;
	for (auto n : v) {
		if (flag)
			os << ", ";
		os << n;
		flag = true;
	}
	return os << "}";
}


int main() {

	vector<int> v1 = {4, 3, 2, 7, 8, 2, 3, 1};
	vector<int> v2 = {1, 1};
	vector<int> v3 = {2, 3, 4, 2, 3, 6, 9, 7, 8};

	Solution solution;
	cout << "v1 = " << solution.findDisappearedNumbers(v1) << endl;
	cout << "v2 = " << solution.findDisappearedNumbers(v2) << endl;
	cout << "v3 = " << solution.findDisappearedNumbers(v3) << endl;

	return 0;
}
