public class Solution {
    public int numDistinct(String S, String T) {
        int n=S.length();
        int m=T.length();
        int dp[][]=new int[n+2][m+1];
        dp[0][0]=1;
        dp[0][1]=0;
        for(int i=1;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                dp[i][j]=0;
                if(S.charAt(i-1)==T.charAt(j-1)) dp[i][j]+=dp[i-1][j-1];
                dp[i][j]+=dp[i-1][j]; //delete one letter
                
            }
        
        return dp[n][m];
    }
}
