class Solution {
private:
    void solve(string digits , int index , string output , string mapping[] , vector<string> &ans){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];

        for(int i = 0; i<value.length();i++){
            output.push_back(value[i]);
            cout<<output[i];
            solve(digits , index+1 , output ,mapping , ans);
            output.pop_back();   // to delete the prev added when we move to next value of number(Back tracking)
        }
 
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int index = 0;
        string output;
        if(digits.length()== 0)return ans;
        string mapping[10] = {"","" , "abc" , "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits , index , output ,mapping , ans);
        return ans;
        
    }
};