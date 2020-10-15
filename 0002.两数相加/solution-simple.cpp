/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // define an empty new ListNode
		ListNode* root = new ListNode(0);
        ListNode* res = root;
        int carry = 0;
        while(l1 != NULL && l2!=NULL) {
			res->next = new ListNode((l1->val + l2->val + carry) % 10);
			carry = ((l1->val + l2->val + carry) >= 10) ? 1 : 0;
			l1 = l1->next;
			l2 = l2->next;
			res = res->next;
		}
		while(l1 != NULL) {
			res->next = new ListNode((l1->val + carry) % 10);
			carry = ((l1->val + carry) >= 10) ? 1 : 0;
			l1 = l1->next;
			res = res->next;
		}
		while(l2 != NULL) {
			res->next = new ListNode((l2->val + carry) % 10);
			carry = ((l2->val + carry) >= 10) ? 1 : 0;
			l2 = l2->next;
			res = res->next;
		}
		if(carry == 1) {
			res->next = new ListNode(1);
		}
		return root->next;
    }
};
