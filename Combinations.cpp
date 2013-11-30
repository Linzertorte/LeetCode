class Solution {
public:
    void dfs(int cur,int last,int n,int k,vector<int> &entry, vector<vector<int> > &result){
        if(cur==k) {
            result.push_back(entry);
            return;
        }
        for(int i=last+1;i<=n;i++){
            entry.push_back(i);
            dfs(cur+1,i,n,k,entry,result);
            entry.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> entry;
        dfs(0,0,n,k,entry,result);
        return result;
    }
};
