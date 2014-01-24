class Solution {
public:
    int total;
    vector<int> queens; // i row, place queens at (i,queens[i])
    vector<int> vis;//which column has been placed a queen
    vector<vector<string> > solutions;
    bool no_attack(int cur,int q){ //0..cur no attack with 0...
        for(int i=0;i<cur;i++){
            if(i+queens[i]==cur+q) return false;
            if(i-queens[i]==cur-q) return false;
        }
        return true;
    }
    int n;
    vector<string> get_solution_vector(){
        vector<string> config;
        string row;
        for(int i=0;i<n;i++){
            int col=queens[i];
            row="";
            for(int j=0;j<n;j++)
                if(j==col) row+="Q";
                else row+=".";
            config.push_back(row);
        }
        return config;
    }
    void dfs(int cur,int n){
        if(cur==n) {
            total++;
            solutions.push_back(get_solution_vector());
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
    vector<vector<string> >  solveNQueens(int nn) {
        n=nn;
        total=0;
        solutions.clear();
        queens=vector<int>(n);
        vis=vector<int>(n,0);
        dfs(0,n);
        //return total;
        return solutions;
    }
};
