class Solution {
public:
    void dfs(int cnt,vector<int> &num,vector<int> &perm,vector<vector<int> > &result){
        if(cnt==num.size()) {
            result.push_back(perm);
            return;
        }
        for(int i=cnt;i<num.size();i++){
            swap(num[i],num[cnt]);
            perm.push_back(num[cnt]);
            dfs(cnt+1,num,perm,result);
            perm.pop_back();
            swap(num[i],num[cnt]);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > result;
        vector<int> perm;
        dfs(0,num,perm,result);
        return result;
        
    }
};
