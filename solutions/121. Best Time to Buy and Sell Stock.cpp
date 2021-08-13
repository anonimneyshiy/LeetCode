#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_buy_stock = prices[0];

        for (int i = 0; i < prices.size() - 1; i++) {
        	min_buy_stock = min(min_buy_stock, prices[i]);
        	max_profit = max(max_profit, (prices[i + 1] - min_buy_stock));
        }

        return max_profit;
    }
};


int main() {

	vector<int> v1 = {7, 1, 5, 3, 6, 4};
	vector<int> v2 = {4, 5, 6, 1, 9, 2, 3, 12};
	vector<int> v3 = {1, 2, 3, 4, 5};
	vector<int> v4 = {7, 6, 4, 3, 1};

	Solution solution;
	cout << solution.maxProfit(v1) << "\n";
	cout << solution.maxProfit(v2) << "\n";
	cout << solution.maxProfit(v3) << "\n";
	cout << solution.maxProfit(v4) << "\n";


	return 0;
}
