class Solution {
public:
    void rotate_i_j(vector<vector<int> >& A,int i,int j,int n){
        int t=A[n-j-1][i];
        A[n-j-1][i]=A[n-i-1][n-j-1];
        A[n-i-1][n-j-1]=A[j][n-i-1];
        A[j][n-i-1]=A[i][j];
        A[i][j]=t;
    }
    void rotate(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n=matrix.size();
        
        for(int i=0;i<n/2;i++)
            for(int j=i;j<n-i-1;j++) rotate_i_j(matrix,i,j,n);
        
    }
};
