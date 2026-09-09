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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;
        if(head->next == head) return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL){
            if(slow == fast){
                return true;
            }
            else{
                slow = slow->next;
                fast = fast->next;
                if(fast == NULL){
                   return false;
                }
                fast = fast->next;
                
            }
            


        }return false;
        
    }
};