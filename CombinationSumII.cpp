
class Solution {
public:
    void dfs(int cur,int n,int target, vector<int> &d,vector<int> &cnt,vector<int> comb,vector<vector<int> > &result){
        if(!target) {
            result.push_back(comb);
            return;
        }
        
        if(cur==n) return;
        if(d[cur]>target) return;
        dfs(cur+1,n,target,d,cnt,comb,result);
        for(int i=1;i<=cnt[cur];i++){
            if(target<i*d[cur]) return;
            comb.push_back(d[cur]);
            dfs(cur+1,n,target-i*d[cur],d,cnt,comb,result);
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &S, int target) {
        vector<vector<int> > result;
        if(!S.size()){
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
        
        
        dfs(0,cnt.size(),target,distinct,cnt,vector<int>(),result);
        return result;
    }
};
