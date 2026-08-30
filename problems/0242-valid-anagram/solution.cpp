class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int n2= t.length();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t && s.length()==t.length())return true ;
        else return false;
    }
};