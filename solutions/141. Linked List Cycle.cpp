#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
    	ListNode* fast = head;
    	ListNode* slow = head;

    	while (fast != nullptr && fast->next != nullptr) {
    		fast = fast->next->next;
    		slow = slow->next;

    		if (fast == slow)
    			return true;
    	}

    	return false;
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

	ListNode list_node_5(5);
	ListNode list_node_4(4, &list_node_5);
	ListNode list_node_3(3, &list_node_4);
	ListNode list_node_2(2, &list_node_3);
	ListNode list_node_1(1, &list_node_2);

	list_node_4.next = &list_node_3;


	// cout << &list_node_1 << endl;

	Solution solution;
	cout << solution.hasCycle(&list_node_1) << endl;

	return 0;
}
