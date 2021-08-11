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
	ListNode* deleteDuplicates(ListNode* head) {

    	ListNode* curr = head;
    	while (curr && curr->next) {
    		if (curr->val == curr->next->val) {
    			curr->next = curr->next->next;
    		}
    		else {
    			curr = curr->next;
    		}
    	}

    	return head;
    }
};

ostream& operator<<(ostream& os, ListNode* list_node) {
	os << "[";
	bool flag = false;

	while (list_node) {
		if (flag) {
			os << ", ";
		}
		os << list_node->val;
		list_node = list_node->next;
		flag = true;
	}

	return os << "]";
}


int main() {

	ListNode list_node_7(5);
	ListNode list_node_6(5, &list_node_7);
	ListNode list_node_5(4, &list_node_6);
	ListNode list_node_4(3, &list_node_5);
	ListNode list_node_3(2, &list_node_4);
	ListNode list_node_2(1, &list_node_3);
	ListNode list_node_1(1, &list_node_2);

	cout << &list_node_1 << "\n";

	Solution solution;
	cout << solution.deleteDuplicates(&list_node_1) << "\n";


	return 0;
}
