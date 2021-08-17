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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode merge;
    	ListNode* merge_head = &merge;
    	ListNode* current_node = &merge;
    	merge_head->next = current_node;

    	merge_head->next = current_node;
    	while (l1 && l2) {
    		if (l1->val <= l2->val) {
    			current_node->next = l1;
    			l1 = l1->next;
    		}
    		else {
    			current_node->next = l2;
    			l2 = l2->next;
    		}
    		current_node = current_node->next;
    	}

    	current_node->next = l1 ? l1 : l2;

    	return merge_head->next->next;
    }
};

ostream& operator<<(ostream& os, ListNode* list_node) {
	os << "[";
	bool flag = false;

	while (list_node != nullptr) {
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

	ListNode list_node_l1_7(12);
	ListNode list_node_l1_6(10, &list_node_l1_7);
	ListNode list_node_l1_5(8, &list_node_l1_6);
	ListNode list_node_l1_4(6, &list_node_l1_5);
	ListNode list_node_l1_3(4, &list_node_l1_4);
	ListNode list_node_l1_2(2, &list_node_l1_3);
	ListNode list_node_l1_1(0, &list_node_l1_2);

	ListNode list_node_l2_7(13);
	ListNode list_node_l2_6(11, &list_node_l2_7);
	ListNode list_node_l2_5(9, &list_node_l2_6);
	ListNode list_node_l2_4(7, &list_node_l2_5);
	ListNode list_node_l2_3(5, &list_node_l2_4);
	ListNode list_node_l2_2(3, &list_node_l2_3);
	ListNode list_node_l2_1(1, &list_node_l2_2);

	cout << &list_node_l1_4 << "\n";
	cout << &list_node_l2_1 << "\n";

	Solution solution;
	cout << solution.mergeTwoLists(&list_node_l1_4, &list_node_l2_1) << endl;

	return 0;
}
