/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
		if (head->val == val) {
			return head->next;
		}
		ListNode *prev = head;
		ListNode *curr = head->next;

		while (curr != nullptr && curr->val != val) {
			prev = curr;
			curr = curr->next;
		}
		if (curr != nullptr) {
			prev->next = curr->next;
		}
		return head;
    }
};
