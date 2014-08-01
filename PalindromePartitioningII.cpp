class Solution {
public:
    int minCut(string s) {
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
        vector<int> dp(n,INT_MAX);
        dp[0]=1;
        for(int i=1;i<n;i++)
            for(int j=i;j>=0;j--)
            if(palindrome[j][i+1]){
            if(j==0) dp[i]=min(dp[i],1);
            else dp[i] = min(dp[i],dp[j-1]+1);
            }
        return dp[n-1]-1;
        
    }
};
