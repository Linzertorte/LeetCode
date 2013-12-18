
class Solution {
public:
    bool noConflict(const vector<char> &nine){
        int cnt[10]={0};

        for(int i=0;i<9;i++){
            if(nine[i]!='.'){
	      if(cnt[nine[i]-'0']!=0) {
//		cout<<"conflict"<<endl;
		return false;
	      }
                else cnt[nine[i]-'0']++;
            }
        }
        return true;
    }
    void fillBox(vector<char> &nine,vector<vector<char> >&board,int i0,int j0){
        for(int i=i0;i<i0+3;i++)
        for(int j=j0;j<j0+3;j++)
            nine[(i-i0)*3+j-j0]=board[i][j];
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<char> nine(9);
        for(int i=0;i<9;i++){
            if(!noConflict(board[i])) return false;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                nine[j]=board[j][i];
            if(!noConflict(nine)) return false;
        }
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                fillBox(nine,board,3*i,3*j);
                if(!noConflict(nine)) return false;
            }
        
        
        return true;
    }
};
