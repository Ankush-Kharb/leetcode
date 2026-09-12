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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* newNode = new ListNode(0);
        ListNode* traverser = newNode;
        if(list1 == NULL ) return list2;
        else if(list2 == NULL )return list1;
        while(temp1  && temp2 ){
            if(temp1 -> val <= temp2 -> val){
                traverser -> next = new ListNode(temp1 -> val);
                traverser = traverser -> next;
                temp1 = temp1->next;
            }
            else if(temp1 -> val > temp2 -> val){
                traverser -> next = new ListNode(temp2 -> val);
                traverser = traverser -> next;
                temp2 = temp2->next;
            }  
        }    
            while(temp2 != NULL){
                traverser -> next = new ListNode(temp2->val);
                temp2 = temp2->next;
                traverser = traverser -> next;
            }
            while(temp1 != NULL){
                traverser -> next = new ListNode (temp1->val);
                temp1 = temp1 -> next;
                traverser = traverser -> next;
            }     
        return newNode->next;
        
    }
};