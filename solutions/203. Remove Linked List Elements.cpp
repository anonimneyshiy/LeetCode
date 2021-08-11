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
    ListNode* removeElements(ListNode* head, int val) {

    	// if (head == nullptr) {
    	// 	return head;
    	// }
        //
    	// while (head != nullptr && head->val == val) {
    	// 	head = head->next;
     	// }

    	ListNode fake_head(0, head);
    	ListNode* p_of_fake_head = &fake_head;

    	ListNode* curr = p_of_fake_head;
    	while (curr != nullptr && curr->next != nullptr) {
    		if (curr->next->val == val) {
    			curr->next = curr->next->next;
    		}
    		else {
    			curr = curr->next;
    		}
    	}

    	return p_of_fake_head->next;
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

	ListNode list_node_7(3);
	ListNode list_node_6(6, &list_node_7);
	ListNode list_node_5(5, &list_node_6);
	ListNode list_node_4(3, &list_node_5);
	ListNode list_node_3(2, &list_node_4);
	ListNode list_node_2(1, &list_node_3);
	ListNode list_node_1(3, &list_node_2);

	cout << &list_node_1 << "\n";

	Solution solution;
	cout << solution.removeElements(&list_node_1, 3) << "\n";


	return 0;
}
