class Solution {
    //vector<string> words;
public:
    
    bool dfs(const string &s,string word,int cur,bool f,unordered_set<string> &dict){
        if(cur==s.size()){
            if(word!=""&&dict.find(word)==dict.end())
            return false;
            else return true;
        }
        word.append(1,s[cur]);
        if(dfs(s,word,cur+1,0,dict)) return true;
        if(dict.find(word)==dict.end()) return false;
        if(dfs(s,"",cur+1,1,dict)) return true;
        return false;
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int alpha1[26]={0};
        int alpha2[26]={0};
        for(int i=0;i<s.size();i++) alpha1[s[i]-'a']=1;
        for(unordered_set<string>::iterator it=dict.begin();it!=dict.end();it++){
            for(int i=0;i<(*it).size();i++)
            alpha2[(*it)[i]-'a']=1;
        }
        for(int i=0;i<26;i++) if(alpha1[i]>alpha2[i]) return false;
        return dfs(s,"",0,true,dict);
    }
};
