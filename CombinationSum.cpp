class Solution {
public:
    void dfs(int cur,int n,int target, vector<int> &cand,vector<int> comb,vector<vector<int> > &result){
        if(!target) {
            result.push_back(comb);
            return;
        }
        if(cur==n) return;
        dfs(cur+1,n,target,cand,comb,result);
        for(int i=1;;i++){
            if(i*cand[cur]>target) break;
            comb.push_back(cand[cur]);
            dfs(cur+1,n,target-i*cand[cur],cand,comb,result);
        }
    }
    vector<vector<int> > combinationSum(vector<int> &cand, int target) {
        sort(cand.begin(),cand.end());
        vector<vector<int> > result;
        dfs(0,cand.size(),target,cand,vector<int>(),result);
        return result;
    }
};
