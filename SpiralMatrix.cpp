class Solution {
public:
    void getLevel(int i1,int j1,int i2,int j2,vector<int> &spiral, vector<vector<int> >&matrix){
        if(i2<i1 || j2<j1) return;
        
        //get the level
        for(int k=j1;k<=j2;k++) spiral.push_back(matrix[i1][k]);
        for(int k=i1+1;k<=i2;k++) spiral.push_back(matrix[k][j2]);
        if(i2!=i1)
            for(int k=j2-1;k>=j1;k--) spiral.push_back(matrix[i2][k]);
        if(j1!=j2) for(int k=i2-1;k>i1;k--) spiral.push_back(matrix[k][j1]);
        
        //recur
        getLevel(i1+1,j1+1,i2-1,j2-1,spiral,matrix);
        
    }
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> spiral;
        if(!matrix.size()) return spiral;
        int m=matrix.size();
        int n=matrix[0].size();
        getLevel(0,0,m-1,n-1,spiral,matrix);
        return spiral;
    }
};
