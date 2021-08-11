#include <iostream>
#include <vector>

using namespace std;


class NumArray {
public:
    NumArray(vector<int>& nums) {

    	int some_sum = 0;
        for (auto n : nums) {
        	some_sum += n;
        	sum.push_back(some_sum);
        }
    }

    int sumRange(int left, int right) {

    	if (left == 0)
    		return sum[right];
    	return sum[right] - sum[left - 1];
    }

public:
    vector<int> sum;
};


int main() {

	vector<int> v = {-2, 0, 3, -5, 2, -1};
	NumArray num_array(v);

	cout << num_array.sumRange(0, 2) << endl;
	cout << num_array.sumRange(2, 5) << endl;
	cout << num_array.sumRange(0, 5) << endl;


	return 0;
}
