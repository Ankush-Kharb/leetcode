class Solution {
public:
    bool isValid(string word) {
        if(word.length()< 3)return false;
        string vowels = "aeiouAEIOU";
        string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ"; 
        int vowel_count = 0;
        int consonant_count = 0;
        for (char c : word){
            if(!isalnum(c))return false;
            if(vowels.find(c) != string::npos ){
                vowel_count++;
            }
            if(consonants.find(c) != string::npos){
                consonant_count++;
            }
            
        }return (vowel_count >=1 && consonant_count >=1 );
        
    }
};