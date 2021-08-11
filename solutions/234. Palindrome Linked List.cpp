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
    bool isPalindrome(ListNode* head) {

    	ListNode* fast = head;
    	ListNode* slow = head;

    	int half_len = 0;
    	while (fast != nullptr && fast->next != nullptr) {
    		fast = fast->next->next;
    		slow = slow->next;
    		half_len++;
    	}

    	ListNode* new_head = reverseList(slow);

    	while (half_len != 0) {
    		if (head->val != new_head->val) {
    			return false;
    		}
    		head = head->next;
    		new_head = new_head->next;
    		half_len--;
    	}

    	return true;
    }

    ListNode* reverseList(ListNode* head) {
    	ListNode* prev_node = nullptr;

    	while (head != nullptr) {
    		ListNode* next_node = head->next;
    		head->next = prev_node;
    		prev_node = head;
    		head = next_node;
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

	ListNode list_node_8(1);
	ListNode list_node_7(2, &list_node_8);
	ListNode list_node_6(3, &list_node_7);
	ListNode list_node_5(4, &list_node_6);
	ListNode list_node_4(4, &list_node_5);
	ListNode list_node_3(3, &list_node_4);
	ListNode list_node_2(2, &list_node_3);
	ListNode list_node_1(1, &list_node_2);

	cout << &list_node_1 << "\n";

	Solution solution;
	cout << solution.isPalindrome(&list_node_1) << "\n";


	return 0;
}
