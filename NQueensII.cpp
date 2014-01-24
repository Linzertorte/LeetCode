class Solution {
public:
    int total;
    vector<int> queens; // i row, place queens at (i,queens[i])
    vector<int> vis;//which column has been placed a queen
    
    bool no_attack(int cur,int q){ //0..cur no attack with 0...
        for(int i=0;i<cur;i++){
            if(i+queens[i]==cur+q) return false;
            if(i-queens[i]==cur-q) return false;
        }
        return true;
    }
    void dfs(int cur,int n){
        if(cur==n) {
            total++;
            return;
        }
        for(int i=0;i<n;i++)
        if(!vis[i] && no_attack(cur,i)){
            vis[i]=1;
            queens[cur]=i;
            dfs(cur+1,n);
            vis[i]=0;
        }
    }
    int totalNQueens(int n) {
        total=0;
        queens=vector<int>(n);
        vis=vector<int>(n,0);
        dfs(0,n);
        return total;
    }
};
