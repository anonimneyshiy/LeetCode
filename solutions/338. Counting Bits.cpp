#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        result[0] = 0;

        for (int i = 1; i < n + 1; i++) {
        	result[i] = result[i >> 1] + i % 2;
        }

        return result;
    }
};

ostream& operator<<(ostream& os, const vector<int>& v) {
	os << "{";
	bool flag = false;
	for (auto n : v) {
		if (flag) {
			os << ", ";
		}
		os << n;
		flag = true;
	}
	return os << "}";
}


int main() {

	Solution solution;
	cout << "n = 2  ->  " << solution.countBits(2) << "\n";
	cout << "n = 5  ->  " << solution.countBits(5) << "\n";
	cout << "n = 10  ->  " << solution.countBits(11) << "\n";

	return 0;
}
