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
    ListNode *detectCycle(ListNode *head) {
         if (!head || !head->next) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if cycle exists using two pointers
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find cycle entry point
                ListNode* entry = head;
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry; // cycle entry point
            }
        }
        return NULL; // no cycle
        
    }
};