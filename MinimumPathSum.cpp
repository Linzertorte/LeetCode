class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m=grid.size();
        if(!m) return 0;
        int n=grid[0].size();
        vector<vector<int> > dp(m,vector<int>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                dp[i][j]=grid[i][j];
                if(!i&&!j) continue;
                if(!i) dp[i][j]=grid[i][j]+dp[i][j-1];
                else if(!j) dp[i][j]=grid[i][j]+dp[i-1][j];
                else dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);
            }
        
        
        return dp[m-1][n-1];
    }
};
