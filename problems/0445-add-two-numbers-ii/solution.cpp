class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* fwd = NULL;
        ListNode* prev = NULL;
        while(curr != NULL){
            fwd = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Rl1 = reverse(l1);
        ListNode* Rl2 = reverse(l2);
        ListNode* sumNode = new ListNode(0);
        ListNode* traverser = sumNode;
        int sum = 0;
        int carry = 0;
        while(Rl1 != NULL && Rl2 != NULL){
            if(Rl1 -> next == NULL &&  Rl2-> next != NULL){
                Rl1 -> next= new ListNode(0);
            }
            if(Rl2 -> next == NULL &&  Rl1-> next != NULL){
                Rl2 -> next= new ListNode(0);
            }
            sum = Rl1-> val + Rl2 -> val + carry;
            if(sum > 9){
                carry = 1;
            }
            else carry = 0;
            traverser -> next= new ListNode(sum%10);
            traverser = traverser -> next;
            Rl1 = Rl1 -> next;
            Rl2 = Rl2 -> next;
        }
        if(carry == 1){
            traverser -> next = new ListNode(carry);
        }
       sumNode = reverse(sumNode->next);

        return sumNode ;
        
    }
};