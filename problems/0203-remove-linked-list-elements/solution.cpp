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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* curr = head;
        while(head != NULL && head-> val == val){
            temp = head;
            head = head-> next;
            temp -> next = NULL;
        }
        curr = head;
        temp = head;
        while(curr != NULL && curr->next!= NULL){
            if(curr -> next -> val == val){
                temp = curr;
                curr= curr-> next;
                temp -> next = temp -> next -> next;
                curr = temp;   
            }
            else {
                curr = curr -> next;
            }
        }
        return head;
        
    }
};