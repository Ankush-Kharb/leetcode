class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();
        int i= 0;int j = n;
        while(i+n<=m){
            if(haystack.substr(i,n)==needle)return i ;
            else {i++;j++;}
        }return -1;
        
    }
};