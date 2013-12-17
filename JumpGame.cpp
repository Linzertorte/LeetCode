class Solution {
public:
    bool canJump(int A[], int n) {
        if(!n) return true;
        vector<int> dp(n);
        dp[0]=A[0];
        for(int i=1;i<n;i++){
            if(!dp[i-1]) dp[i]=0;
            else dp[i]=max(A[i],dp[i-1]-1);
        }
        return n==1||dp[n-2];
    }
};
