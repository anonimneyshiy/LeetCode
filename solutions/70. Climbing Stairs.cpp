#include <iostream>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
    	if (n == 1) {
    		return 1;
    	}

    	int n1 = 1;
    	int n2 = 2;
    	for (int i = 3; i < (n + 1); i++) {
    		int temp = n1;
    		n1 = n2;
    		n2 = temp + n2;
    	}
    	return n2;
    }
};


int main() {

	Solution solution;
	cout << "n = 1 -> " << solution.climbStairs(1) << "\n";
	cout << "n = 2 -> " << solution.climbStairs(2) << "\n";
	cout << "n = 3 -> " << solution.climbStairs(3) << "\n";
	cout << "n = 4 -> " << solution.climbStairs(4) << "\n";
	cout << "n = 7 -> " << solution.climbStairs(7) << "\n";


	return 0;
}
