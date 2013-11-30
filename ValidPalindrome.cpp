class Solution {
public:
    bool plainPalidrome(string s){
        for(int i=0;i<s.size()/2;i++)
            if(s[i]!=s[s.size()-1-i]) return false;
        return true;
    }
    bool isPalindrome(string s) {
        string filtered;
        for(int i=0;i<s.size();i++)
            if(isalnum(s[i])) filtered.push_back(tolower(s[i]));
        return plainPalidrome(filtered);
    }
};
