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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        vector<int> nums;
        while(temp != NULL){
            nums.push_back(temp-> val);
            temp = temp-> next;
        }
        int i = 0 ;
        int n = nums.size();
        int sum = 0;
        int max_sum = INT_MIN;
        int j = n-1;
        while(i<j){
            sum = nums[i]+nums[j];
            max_sum = max( sum , max_sum);
            i++;
            j--;
        }
        return max_sum;
        
    }
};