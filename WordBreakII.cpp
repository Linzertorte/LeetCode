
class Solution {
    //vector<string> words;
public:
    
    void dfs(const string &s,string word,int cur,unordered_set<string> &dict,string seq,vector<string> &result){
        if(cur==s.size()){
            if(word=="")
                result.push_back(seq);
            return;
        }
        word.append(1,s[cur]);
        dfs(s,word,cur+1,dict,seq,result);
        if(dict.find(word)==dict.end()) return;
        dfs(s,"",cur+1,dict,seq==""?word:(seq+" "+word),result);
        
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> result;
         int alpha1[26]={0};
        int alpha2[26]={0};
        for(int i=0;i<s.size();i++) alpha1[s[i]-'a']=1;
        for(unordered_set<string>::iterator it=dict.begin();it!=dict.end();it++){
            for(int i=0;i<(*it).size();i++)
            alpha2[(*it)[i]-'a']=1;
        }
        for(int i=0;i<26;i++) if(alpha1[i]>alpha2[i]) return result;
        dfs(s,"",0,dict,"",result);
        return result;
    }
};
