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
    ListNode* partition(ListNode* head, int x) {
        ListNode * lessThen = new ListNode();
        ListNode * dummy = lessThen;
        ListNode * traverser = head;
        while(traverser != NULL){
            ListNode * toInsert = new ListNode(traverser->val);
            if(traverser->val<x) {  
            dummy -> next = toInsert;
            dummy = dummy->next;
            }traverser = traverser -> next;
        }
        traverser = head;
        while(traverser != NULL){ 
            ListNode * toInsert = new ListNode(traverser->val);
            if(traverser->val>=x) {  
            dummy -> next = toInsert;
            dummy = dummy->next;
            }traverser = traverser -> next;
        }return lessThen->next;

        
    }
};