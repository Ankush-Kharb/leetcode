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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;  // points to last node known to be unique

        while (head) {
            // If we find duplicates
            if (head->next && head->val == head->next->val) {
                int dupVal = head->val;
                // Skip all nodes with this value
                while (head && head->val == dupVal) {
                    head = head->next;
                }
                prev->next = head; // Remove the whole duplicate block
            }
            else { // No duplicate — move prev
                prev = head;
                head = head->next;
            }
        }

        return dummy->next;
    }
};


