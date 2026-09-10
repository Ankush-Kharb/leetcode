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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        int count = 0;
        int len = 0;
        int i = 0;
        int j= 0;
        while(temp1 != NULL){
            temp1 = temp1 -> next ;
            len++;
        }
        temp1 = head;
        while(i!=k-1){
            temp1 = temp1->next;
            i++;
        }
        while(j != len-k){
            temp2 = temp2-> next;
            j++;
        }
        swap(temp1-> val , temp2->val);
        return head;
        
    }
};