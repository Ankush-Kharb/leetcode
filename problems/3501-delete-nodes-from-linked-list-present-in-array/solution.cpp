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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* list = new ListNode(0);
        ListNode* add = list;
        ListNode* dummy = head;
        unordered_map <int,int> mpp;
        for (int i = 0; i< nums.size();i++){
            mpp[nums[i]]= i;
        }
        while(dummy != NULL){
            if(mpp.find(dummy->val) != mpp.end()){
                dummy = dummy -> next;
            }
            else {
                add -> next = new ListNode(dummy->val);
                add = add->next;
                dummy = dummy->next;
            }
        }
        return list->next;
        
    }
};