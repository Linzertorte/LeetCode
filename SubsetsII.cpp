class Solution {
public:
    void dfs(int cur,vector<int> &d,vector<int> &cnt,vector<int> sub,vector<vector<int> > &result){
        if(cur==d.size()) {
            result.push_back(sub);
            return;
        }
        dfs(cur+1,d,cnt,sub,result);
        for(int i=1;i<=cnt[cur];i++){
            sub.push_back(d[cur]);
            dfs(cur+1,d,cnt,sub,result);
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > result;
        if(!S.size()){
            result.push_back(vector<int>());
            return result;
        }
        sort(S.begin(),S.end());
        vector<int> distinct;
        vector<int> cnt;
        int i=0;
        int local=0;
        while(i<S.size()){
            distinct.push_back(S[i]);
            local=0;
            while(i<S.size() && S[i]==distinct.back()) i++,local++;
            cnt.push_back(local);
            
        }
        dfs(0,distinct,cnt,vector<int>(),result);
        return result;
    }
};
