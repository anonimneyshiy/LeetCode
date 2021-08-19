#include <iostream>
#include <vector>

using namespace std;


using iter = vector<char>::iterator;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
    	iter start = begin(letters);
    	iter finish = --end(letters);

    	while(start <= finish) {
    		iter current_iter = start + (finish - start) / 2;
    		cerr << (finish - start) << " " << *current_iter << "\n";

    		if (*current_iter > target) {
    			finish = current_iter - 1;
    		}
    		else {
    			start = current_iter + 1;
    		}
    	}
    	return start != end(letters) ? *start : letters[0];
    }
};


int main() {

	vector<char> letters = {'c', 'f', 'j'};
	char target = 'w';

	Solution solution;
	cout << solution.nextGreatestLetter(letters, target) << "\n";

	return 0;
}












