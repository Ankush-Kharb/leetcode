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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* traverse1 = list1;
        ListNode* add = list2;
        ListNode* justLESS = list1;
        ListNode* traverse2 = list1;
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        while(count1 != a-1 ){
            traverse1 = traverse1 -> next;
            count1++;
        }
        while(count2!=b+1 && traverse2 != NULL){
            traverse2 = traverse2 -> next;
            count2++;    
        }
        while(count3 != b){
            justLESS = justLESS -> next;
            count3++;
        }
        traverse1 -> next = add;
        while(add-> next!= NULL){
            add= add-> next;
        }
        add -> next = traverse2;
        justLESS -> next = NULL;
        return list1;
        
    }
};