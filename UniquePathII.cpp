class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int dp[101][101];
        dp[0][0]=1;
        int n=obstacleGrid.size();
        if(!n) return 0;
        int m=obstacleGrid[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1) {
                    dp[i][j]=0;
                    continue;
                }
                if(!i&&!j) continue;
                if(!i) dp[i][j]=dp[i][j-1];
                if(!j) dp[i][j]=dp[i-1][j];
                if(i&&j) dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        return dp[n-1][m-1];
    }
};
