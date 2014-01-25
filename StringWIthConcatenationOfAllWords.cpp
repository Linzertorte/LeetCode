class Solution {
public:
    inline bool bingo(int len,string S,map<string,int> &dict){
        map<string,int> cnt;
        for(int i=0;i<S.size();i+=len){
            string sub=S.substr(i,len);
            if(!dict[sub]) return false;
            cnt[sub]++;
            if(cnt[sub]>dict[sub]) return false;
        }
        
        return true;
    }
    vector<int> findSubstring(string S, vector<string> &L) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n=S.size();
        int len=L[0].size();
        int cnt=L.size();
        map<string,int> dict;
        for(int i=0;i<L.size();i++) dict[L[i]]++;
        vector<int> result;
        for(int i=0;i<=n-len*cnt;i++){
            if(bingo(len,S.substr(i,len*cnt),dict)) result.push_back(i);
        }
        return result;
        
    }
};
