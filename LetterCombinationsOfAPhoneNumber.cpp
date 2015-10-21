class Solution {
public:
    string tbl[10]={"xxx","xxx","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()==0) return result;
        result.push_back("");
        vector<string> cur;
        for(auto c:digits){
            cur = result;
            result.clear();
            for(auto d:tbl[c-'0'])
                for(auto s:cur) result.push_back(s+d);
        }
        return result;
    }
};
