#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

    	if (begin(nums) == end(nums))
    		return 0;

    	vector<int>::iterator first = begin(nums);
    	vector<int>::iterator second = begin(nums);

    	while ((second + 1) != end(nums)) {
    		if (*first == *(second + 1)) {
    			second++;
    		}
    		else {
    			first++;
    			second++;
    			*first = *second;
    		}
    	}

    	return first + 1 - nums.begin();
    }
};

void print_vector(const vector<int>& v) {
	for (auto n : v) {
		cout << n << " ";
	}
	cout << "\n";
}


int main() {

	vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	print_vector(v);

	Solution solution;
	cout << solution.removeDuplicates(v) << endl;
	print_vector(v);

	return 0;
}
