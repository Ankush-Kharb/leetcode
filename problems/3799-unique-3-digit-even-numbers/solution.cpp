class Solution {
public:
    void f(int element, vector<int>& digits, vector<int>& vis ,set<int>& st) {

        if (element >= 100 && element <= 999) {
            if (element % 2 == 0) {
                st.insert(element);
            }
            return;
        }
        
        for(int i = 0 ; i< digits.size() ; i++){
            if(!vis[i]){
                if(element == 0 && digits[i] == 0){
                    continue;
                }
                vis[i] = 1;
                f(element*10+digits[i] , digits , vis,st);
                vis[i] = 0;
            }
        }
    }
    int totalNumbers(vector<int>& digits) {
        vector<int> vis(digits.size(), 0);
        set<int> st;
         f(0, digits, vis,st);
         return st.size();
    }
};