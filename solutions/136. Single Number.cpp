#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	/*  XOR
	int singleNumber(vector<int>& nums) {
		int mask = 0;

		for (auto n : nums) {
			mask ^= n;
		}

		return mask;
	}
	*/
    int singleNumber(vector<int>& nums) {

    	int current_num = 0;
    	for (auto n : nums) {
    		if (unique_nums.find(n) != end(unique_nums)) {
    			current_num -= n;
    		}
    		else {
    			current_num += n;
    			unique_nums.insert(n);
    		}
    		cerr << current_num << " ";
    	}

    	cout << "\n";
    	return current_num;
    }

private:
    set<int> unique_nums;
};


int main() {

	vector<int> v = {4, 4, 3, 1, 2, 1, 2};

	Solution solution;
 	cout << solution.singleNumber(v) << endl;

	return 0;
}
