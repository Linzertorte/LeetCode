struct Node
{
    int x,y;
    Node(int i,int j):x(i),y(j){}
};
class Solution {
public:
   
    
    void bfs(int i,int j,int n,int m,vector<vector<char> > &board,char f,char t){
        const static int dx[4]={0,1,0,-1};
        const static int dy[4]={1,0,-1,0};
        if(board[i][j]!=f) return;
        queue<Node> que;
        que.push(Node(i,j));
        board[i][j]=t;
        while(!que.empty()){
            Node nd=que.front();
            que.pop();
            for(int k=0;k<4;k++){
                int ii=nd.x+dx[k];
                int jj=nd.y+dy[k];
                if(ii>=0 && ii < n && jj>=0 && jj<m &&board[ii][jj]==f) que.push(Node(ii,jj)),board[ii][jj]=t;
            }
        }
        
    }
    
    void solve(vector<vector<char>> &board) {
        //flip the boundary 0 to 1
        if(!board.size()) return;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')bfs(0,i,n,m,board,'O','1');
            if(board[n-1][i]=='O')bfs(n-1,i,n,m,board,'O','1');
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')bfs(i,0,n,m,board,'O','1');
            if(board[i][m-1]=='O')bfs(i,m-1,n,m,board,'O','1');
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) if(board[i][j]=='O')bfs(i,j,n,m,board,'O','X');
        for(int i=0;i<m;i++){
            if(board[0][i]=='1')bfs(0,i,n,m,board,'1','O');
            if(board[n-1][i]=='1')bfs(n-1,i,n,m,board,'1','O');
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='1')bfs(i,0,n,m,board,'1','O');
            if(board[i][m-1]=='1')bfs(i,m-1,n,m,board,'1','O');
        }
        
    }
};
