class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size()!= s2.size())return false;
        if(s1 == s2 )return true;
        int count = 0;
        string m1;
        string m2;
       for(int i = 0 ;i<s1.size() ;i++){
        if(s1[i]!=s2[i]){
            count++;
            m1.push_back(s1[i]);
            m2.push_back(s2[i]);
            
        }
        
       }if (count > 2)return false;
        reverse(m2.begin(),m2.end());
        if (count == 2 && m1 == m2)return true;
        else return false;
        
    }
};