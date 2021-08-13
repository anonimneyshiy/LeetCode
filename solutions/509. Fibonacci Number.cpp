#include <iostream>

using namespace std;


class Solution {
public:
	/*
    int fib(int n) {

    	if (n == 0) {
    		return 0;
    	}
    	if (n == 1) {
    	   	return 1;
     	}

    	return fib(n - 1) + fib(n - 2);
    }
    */
	int fib(int n) {

		if (n == 0) {
			return 0;
		}

		int n1 = 1;
		int n2 = 1;
		for (int i = 2; i < n; i++) {
			int temp = n1;
			n1 = n2;
			n2 = temp + n2;
		}

		return n2;
	}

};


int main() {

	Solution solution;
	cout << "n = 1 -> " << solution.fib(1) << "\n";
	cout << "n = 2 -> " << solution.fib(2) << "\n";
	cout << "n = 3 -> " << solution.fib(3) << "\n";
	cout << "n = 4 -> " << solution.fib(4) << "\n";
	cout << "n = 8 -> " << solution.fib(8) << "\n";

	return 0;
}
