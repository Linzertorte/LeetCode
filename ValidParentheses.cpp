class Solution {
public:
    char left_paren(char p){
        if(p==')') return '(';
        if(p=='}') return '{';
        if(p==']') return '[';
    }
    bool isValid(string s) {
        stack<char> unmatched;
        if(!s.size()) return true;
        unmatched.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            char p=s[i];
            if(p=='['||p=='('||p=='{') unmatched.push(p);
            else {
                if(unmatched.empty() || left_paren(p)!=unmatched.top()) return false;
                unmatched.pop();
            }
        }
        return unmatched.empty();
    }
};
