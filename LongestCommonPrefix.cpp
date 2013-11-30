class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string lcp="";
        if(!strs.size()||strs[0]=="") return "";
        int flag=0;
        for(int i=0;;i++){
            if(i>=strs[0].size()) break;
            char c=strs[0][i];
            int j;
            for(j=1;j<strs.size();j++){
                if(i>=strs[j].size()) {
                    flag=1;
                    break;
                }
                if(strs[j][i]!=c) {
                    flag=1;
                    break;
                }
            }
            
            if(j==strs.size()) lcp.push_back(c);
            if(flag) break;
        }
        
        return lcp;
    }
};
