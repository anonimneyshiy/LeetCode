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
    ListNode* middleNode(ListNode* head) {
    	ListNode* fast = head;
    	ListNode* slow = head;

    	while (fast != nullptr && fast->next != nullptr) {
    		fast = fast->next->next;
    		slow = slow->next;
    	}

    	return slow;
    }
};


ostream& operator<<(ostream& os, ListNode* head) {
	if (head == nullptr)
		return os;

	os << "[";
	ListNode* p = head;
	bool flag = false;
	while (p->next != nullptr) {
		if (flag)
			os << ", ";
		os << p->val;
		p = p->next;
		flag = true;
	}
	os << ", " << p->val;
	return os << "]";
}


int main() {

	ListNode list_node_8(8);
	ListNode list_node_7(7, &list_node_8);
	ListNode list_node_6(6, &list_node_7);
	ListNode list_node_5(5, &list_node_6);
	ListNode list_node_4(4, &list_node_5);
	ListNode list_node_3(3, &list_node_4);
	ListNode list_node_2(2, &list_node_3);
	ListNode list_node_1(1, &list_node_2);

	cout << &list_node_1 << endl;

	Solution solution;
	cout << solution.middleNode(&list_node_1)->val << endl;


	return 0;
}
