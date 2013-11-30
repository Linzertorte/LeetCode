class Solution {
public:
    void fill(int &start,int x,int n,vector<vector<int> > &ans){
        int i,j;
        i=x;
        for(j=x;j<n-x-1;j++) ans[i][j]=start++;
        j=n-x-1;
        for(i=x;i<n-x-1;i++) ans[i][j]=start++;
        i=n-x-1;
        for(j=n-x-1;j>x;j--) ans[i][j]=start++;
        j=x;
        for(i=n-x-1;i>x;i--) ans[i][j]=start++;
        
    }
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n,vector<int>(n));
        int start=1;
        for(int i=0;i<n/2;i++) fill(start,i,n,ans);
        if(n%2) ans[n/2][n/2]=n*n;
        return ans;
    }
};
