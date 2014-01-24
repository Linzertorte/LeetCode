class Solution {
public:
    bool no_conflict(int r,int c, vector<vector<char> > &board){
        char at=board[r][c];
        for(int k=0;k<9;k++)
            if(k!=c && board[r][k]==at) return false; //same row;                                                     
        for(int k=0;k<9;k++)
            if(k!=r && board[k][c]==at) return false;
        int box_r=(r/3)*3;
        int box_c=(c/3)*3;
        for(int i=box_r;i<box_r+3;i++)
            for(int j=box_c;j<box_c+3;j++){
                if((i!=r || j!=c) && board[i][j]==at) return false;
            }
        return true;
    }
    bool dfs(int r,int c,vector<vector<char> >&board){
        if(r==9) return true;
        if(c==9) return dfs(r+1,0,board);
        if(board[r][c]!='.'){
            if(dfs(r,c+1,board)) return true;
        }else
        {
            for(int k=1;k<=9;k++)
            {
                board[r][c]='0'+k;
                if(no_conflict(r,c,board) && dfs(r,c+1, board)) return true;
                board[r][c]='.';
            }
        }
        return false;

    }
    void solveSudoku(vector<vector<char> > &board) {
        dfs(0,0,board);
    }
};
