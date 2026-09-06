class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1;
        int count = 0;
        while(i>=0){
            if(s[i]!=' '){
                i--;
                count++;
            }
            else if (s[i]==' '){
                if (count == 0){
                    i--;
                }
                else break;
            }
        }return count;
        
    }
};