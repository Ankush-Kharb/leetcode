class Solution {
public:
    void reverse(string& s, int i, int j){
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }

    string reverseWords(string s) {
        int j=0;
        for(int i =0; i<=s.length(); i++){
            if(s[i] == ' ' || s[i] == '\0'){
                reverse(s, j, i-1);
                j=i+1;
            }

        }
        return s;
    }
};