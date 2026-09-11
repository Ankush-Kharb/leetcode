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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* new1 = l1;
        ListNode* new2 = l2;
        ListNode* sumNode = new ListNode(0);
        ListNode* traverser = sumNode;
        int sum ;
        int carry = 0;
        while(new1 != NULL && new2 != NULL){
            if(new1 -> next == NULL && new2 -> next != NULL ){
                new1 -> next = new ListNode(0);
            }
            if(new2 -> next == NULL && new1 -> next != NULL ){
                new2 -> next = new ListNode(0);
            }
            sum = new1 -> val + new2 -> val + carry;
            if(sum > 9) {
                carry = 1;
            }
            else carry = 0;
            traverser->next = new ListNode(sum%10);
            traverser = traverser->next;
            new1 = new1->next;
            new2 = new2->next;
        }
        if(carry == 1){
            traverser -> next = new ListNode(carry);
        }
        return sumNode->next;
        
    }
};