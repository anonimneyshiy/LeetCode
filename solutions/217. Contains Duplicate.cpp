#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

    	for (auto n : nums)
    	{
    		if (unique_nums.find(n) != end(unique_nums))
    			return true;
    		unique_nums.insert(n);
    	}
    	return false;
    }

private:
    set<int> unique_nums;
};


int main() {

	vector<int> v1 = {1, 2, 3, 1};
	vector<int> v2 = {1, 2, 3, 4};
	vector<int> v3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
	Solution solution1;
	Solution solution2;
	Solution solution3;

	cout << solution1.containsDuplicate(v1) << endl;
	cout << solution2.containsDuplicate(v2) << endl;
	cout << solution3.containsDuplicate(v3) << endl;


	return 0;
}
