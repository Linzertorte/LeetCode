class Solution {
public:
    
    
    bool subword(int x,int i,int j,int n,int m,vector<vector<char> >&board,string &word,vector<vector<char> > &vis){
        const static int dx[4]={0,1,0,-1};
        const static int dy[4]={1,0,-1,0};
        if(x==word.size()) return true; //match complete
        if(i<0||i>=n || j<0 || j>=m || vis[i][j] || board[i][j]!=word[x]) return false;
        vis[i][j]=1;
        bool ans = false;
        for(int k=0;k<4;k++)
            if(subword(x+1,i+dx[k],j+dy[k],n,m,board,word,vis))
            {
                ans=true;
                break;
            }
        vis[i][j]=0;
        return ans;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n=board.size();
        if(!n) return !word.size();
        int m=board[0].size();
        vector<vector<char> > vis(n,vector<char>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(subword(0,i,j,n,m,board,word,vis)) return true;
        return false;
        
    }
};
