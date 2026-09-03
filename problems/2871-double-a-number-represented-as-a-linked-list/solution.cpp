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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fwd = NULL;
        while (curr != NULL) {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* prev = reverse(head);
        ListNode* dummy = prev;
        ListNode* peeche = NULL;
        int carry = 0;

        while (dummy != NULL) {
            int val = dummy->val;
            int total = val*2+carry;
            dummy->val = total%10;
            carry = total/10;
            peeche = dummy;
            dummy = dummy->next;
        }
        if (carry == 1) {
            ListNode* extra = new ListNode(carry);
            peeche->next = extra;
        }
        prev = reverse(prev);
        return prev;
    }
};