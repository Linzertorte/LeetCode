class Solution {
public:
    int lengthOfLastWord(const char *s) {
        istringstream iss(s);
        string word;
        while(iss>>word);
        return word.size();
    }
};
