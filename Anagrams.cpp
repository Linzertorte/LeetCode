class Solution {
public:
    static string count_str(const string& s){
        string cnt(26,'0');
        for(int i=0;i<s.size();i++)
            cnt[s[i]-'a']++;
        return cnt;
    }
    bool static cmp(const string& s1,const string& s2){
        return count_str(s1)<count_str(s2);
    }
    vector<string> anagrams(vector<string> &strs) {

        vector<string> ans;
        sort(strs.begin(),strs.end(),cmp);

        //for(int i=0;i<strs.size();i++)                                                                              
        //    cout<<strs[i]<<" "<<count_str(strs[i])<<endl;                                                           


        for(int i=1;i<=strs.size();i++)
            if(i<strs.size() && count_str(strs[i])==count_str(strs[i-1])) ans.push_back(strs[i-1]);
            else {
                if(ans.size()>0 && count_str(strs[i-1])==count_str(*(ans.end()-1))) ans.push_back(strs[i-1]);
            }

        //for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;                                                           
        return ans;
    }
};

