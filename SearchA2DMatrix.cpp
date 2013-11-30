class Solution {
public:
    bool searchMatrix_sub(vector<vector<int> > &matrix,int i,int j,int m,int n,int target){
        if(i>=m || j<0) return false;
        int x=matrix[i][j];
        if(x==target) return true;
        if(x<target) return searchMatrix_sub(matrix,i+1,j,m,n,target);
        else return searchMatrix_sub(matrix,i,j-1,m,n,target);
        
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m=matrix.size();
        if(!m) return false;
        int n=matrix[0].size();
        return searchMatrix_sub(matrix,0,n-1,m,n,target);
    }
};
