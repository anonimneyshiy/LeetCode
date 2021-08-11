#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	ListNode* prev_node = nullptr;
    	ListNode* current_node = head;

    	while (current_node != nullptr) {
    		ListNode* next_node = current_node->next;
    		current_node->next = prev_node;
    		prev_node = current_node;
    		current_node = next_node;
    	}

    	return prev_node;
    }
};


ostream& operator<<(ostream& os, ListNode* list_node) {
	os << "[";
	bool flag = false;
	ListNode* p = list_node;

	while (p != nullptr) {
		if (flag) {
			os << ", ";
		}
		os << p->val;
		p = p->next;
		flag = true;
	}

	return os << "]";
}


int main() {

	ListNode list_node_7(7);
	ListNode list_node_6(6, &list_node_7);
	ListNode list_node_5(5, &list_node_6);
	ListNode list_node_4(4, &list_node_5);
	ListNode list_node_3(3, &list_node_4);
	ListNode list_node_2(2, &list_node_3);
	ListNode list_node_1(1, &list_node_2);

	cout << &list_node_2 << "\n";

	Solution solution;
	cout << solution.reverseList(&list_node_2) << "\n";


	return 0;
}
