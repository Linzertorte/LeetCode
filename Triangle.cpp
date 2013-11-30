class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n=triangle.size();
        if(!n) return 0;
        vector<vector<int> > dp=triangle;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<i+1;j++) dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        }
        
        return dp[0][0];
    }
};
