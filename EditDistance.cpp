class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int> > dp(n1+1,vector<int>(n2+2));
        dp[0][0]=0;
        for(int i=0;i<=n1;i++)
        for(int j=0;j<=n2;j++){
            if(i&&j&&word1[i-1]==word2[j-1])
           dp[i][j]=dp[i-1][j-1];
            else if(i&&j)dp[i][j]=dp[i-1][j-1]+1;
            else if(i||j)dp[i][j]=INT_MAX;
            if(i>0) dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            if(j>0) dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        }
        
        return dp[n1][n2];
    }
};
