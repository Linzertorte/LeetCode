class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101];
        dp[1][1]=1;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(i==1&&j==1) continue;
                if(i==1) dp[i][j]=dp[i][j-1];
                else if(j==1) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        return dp[m][n];
    }
};
