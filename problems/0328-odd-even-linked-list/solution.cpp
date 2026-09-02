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
    ListNode* oddEvenList(ListNode* head) {
    ListNode * oddNum = new ListNode();
    if(head == NULL)return NULL;
    
    ListNode * dummy = oddNum;
    ListNode * traverse = head;
    while(traverse != NULL){
        ListNode * toInsert = new ListNode(traverse->val);
        dummy->next =  toInsert;
        dummy = dummy->next;
       traverse = traverse ->next;
        if(traverse != NULL) {
          traverse =  traverse ->next;
        }
        
    }
    traverse = head->next;
    while(traverse != NULL){
        ListNode * toInsert2 = new ListNode(traverse ->val);
        dummy ->next = toInsert2;
        dummy = dummy->next;
        traverse = traverse -> next;
        if(traverse != NULL) {
          traverse =  traverse ->next;
        }

    }return oddNum->next;
        
    }
};