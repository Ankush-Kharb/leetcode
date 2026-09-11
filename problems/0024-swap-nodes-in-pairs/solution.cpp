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
    ListNode* swapPairs(ListNode* head) {
        ListNode* slow = head;
        if(slow == NULL)return NULL;
        ListNode* fast = slow-> next;
        if(fast == NULL){
            return head;
        }
        swap(slow->val , fast-> val);
        slow = fast->next;
        
        swapPairs(slow);
        return head;
        
        
    }
};