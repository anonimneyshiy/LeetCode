#include <iostream>
#include <vector>

using namespace std;


using iter = vector<int>::iterator;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	iter start = begin(nums);
    	iter finish = end(nums) - 1;

    	while (start <= finish) {
    		iter middle = start + (finish - start) / 2;

    		if (*middle == target) {
    			return middle - begin(nums);
    		}
    		if (*middle > target) {
    			finish = middle - 1;
    		}
    		if (*middle < target) {
    			start = middle + 1;
    		}
    	}

    	return -1;
    }
};


int main() {

	vector<int> v1 = {1, 2, 3, 4, 5, 6};
	vector<int> v2 = {-1, 0, 3, 5, 9, 12};

	Solution solution;
	cout << "1 in v1 -> " << solution.search(v1, 1) << "\n";
	cout << "5 in v1 -> " << solution.search(v1, 5) << "\n";
	cout << "9 in v1 -> " << solution.search(v1, 9) << "\n";
	cout << "-3 in v2 -> " << solution.search(v2, -3) << "\n";
	cout << "-1 in v2 -> " << solution.search(v2, -1) << "\n";
	cout << "5 in v2 -> " << solution.search(v2, 5) << "\n";
	cout << "12 in v2 -> " << solution.search(v2, 12) << "\n";

	cout << "----" << "\n";
	vector<int> v3 = {-1, 0, 5};
	cout << "2 in v3 -> " << solution.search(v3, 2) << "\n";

	return 0;
}
