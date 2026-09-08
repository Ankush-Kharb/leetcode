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
    void deleteNode(ListNode* node) {
        ListNode * dummy = node;
        ListNode * temp = dummy -> next;
        dummy -> val = dummy -> next-> val;
        dummy -> next = dummy ->next -> next;
        temp -> next = NULL; 
    }
};