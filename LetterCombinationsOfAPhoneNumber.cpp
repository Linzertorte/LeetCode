class Solution {
     char table[10][5]={"xxx","xxx","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void dfs(const string &digits,string word,int cur,vector<string> &result){
        if(cur==digits.size()) {
            result.push_back(word);
            return;
        }
        int d=digits[cur]-'0';
        char letter;
        string tmp;
        for(int i=0;letter=table[d][i];i++){
            tmp=word;
            dfs(digits,tmp.append(1,letter),cur+1,result);
        }
    }
    vector<string> letterCombinations(string digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
       vector<string> result;
       
       dfs(digits,"",0,result);
       return result;
    }
};
