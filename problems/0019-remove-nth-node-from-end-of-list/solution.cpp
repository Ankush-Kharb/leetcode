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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummy = head;
        int len  = 0;
        while(dummy != NULL){
            len++;
            dummy = dummy->next;
        }
        if(len == 1 )return NULL;
        if(len == n)return head->next;
        int point = len - n -1;
        int i = 0;
        dummy = head ;
        while(i<point){
            i++;
            dummy = dummy->next;
        }
        ListNode *ele = dummy->next;
        dummy ->next = dummy ->next ->next;
        ele -> next = NULL;
       
       
        return head;
    
        
    }
};