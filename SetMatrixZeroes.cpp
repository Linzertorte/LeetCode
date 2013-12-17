class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row=1,col=1;
        int m=matrix.size();
        if(!m) return;
        int n=matrix[0].size();
        for(int i=0;i<n;i++) if(!matrix[0][i]) row=0;
        for(int i=0;i<m;i++) if(!matrix[i][0]) col=0;
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++) if(!matrix[i][j]) matrix[i][0]=0,matrix[0][j]=0;
        
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++) if(!matrix[i][0] ||!matrix[0][j]) matrix[i][j]=0;
        
        if(!row)
            for(int i=0;i<n;i++) matrix[0][i]=0;
        if(!col)
            for(int i=0;i<m;i++) matrix[i][0]=0;
        
    }
};
