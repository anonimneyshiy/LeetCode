#include <iostream>
#include <vector>

using namespace std;


using iter = vector<int>::iterator;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    	iter start = begin(arr);
    	iter finish = --end(arr);

    	while (start <= finish) {
    		iter current_iter = start + (finish - start) / 2;
    		if (*current_iter < *(current_iter + 1)) {
    			start = current_iter + 1;
    		}
    		else {
    			finish = current_iter - 1;
    		}
    	}
    	return start - begin(arr);
    }
};


int main() {

	vector<int> mountain_array = {24, 69, 72, 75, 100, 99, 97, 78, 67, 36, 26, 19};

	Solution solution;
	cout << "Peak index for Mounaint Array -> "
		 << solution.peakIndexInMountainArray(mountain_array) << "\n";

	return 0;
}
