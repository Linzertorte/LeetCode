class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(!dungeon.size()) return 1;
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        dp[n-1][m-1] = 1;
        //dp(i,j) after eat room, min energy
        for(int i=n-1;i>=0;i--)
            for(int j=m-1;j>=0;j--){
                if(i+1<n) dp[i][j] = min(dp[i][j],dp[i+1][j]-dungeon[i+1][j]);
                if(j+1<m) dp[i][j] = min(dp[i][j],dp[i][j+1]-dungeon[i][j+1]);
                dp[i][j] = max(1,dp[i][j]);
            }
        return max(1,dp[0][0]-dungeon[0][0]);
    }
};
