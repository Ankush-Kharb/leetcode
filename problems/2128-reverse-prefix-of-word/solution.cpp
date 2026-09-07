class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        int breakpoint = -1;
        for(int i = 0; i<n ;i++){
            if(word[i]== ch){
                breakpoint = i;
                break;
            }   
        } 
        if(breakpoint == -1 )return word;
        else {
        reverse(word.begin(),word.begin()+breakpoint+1);
        return word;
        }
        
    }
};