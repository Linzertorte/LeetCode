class Solution {
public:
    void dfs(int i,int n,const string &s,const vector<vector<int> > &dp, vector<string> &path, 
    vector<vector<string> > &result){
        if(i==n){
            result.push_back(path);
            return;
        }
        for(int j=i+1;j<=n;j++){
            if(dp[i][j]){
                path.push_back(s.substr(i,j-i));
                dfs(j,n,s,dp,path,result);
                path.pop_back();
            }
        }
        
    }
    vector<vector<string> > partition(string s) {
        int n = s.size();
        vector<vector<int> > palindrome(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++) palindrome[i][i]=1;
        for(int len=1;len<=n;len++){
            for(int i=0;i<n;i++){
                int j = i+len;
                if(j>n) continue;
                if(len==1) palindrome[i][j]=1;
                else if(s[i]==s[j-1] && palindrome[i+1][j-1]) palindrome[i][j]=1;
            }
        }
        vector<vector<string> > result;
        vector<string> path;
        dfs(0,n,s,palindrome,path,result);
        return result;
    }
};
