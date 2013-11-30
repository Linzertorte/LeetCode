class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<unordered_set<string> > dp(n+1);
        dp[0].insert("");
        dp[1].insert("()");
        for(int i=2;i<=n;i++){
          for(auto j=dp[i-1].begin();j!=dp[i-1].end();j++){
              string s=*j;
              dp[i].insert("("+s+")");
          }
          for(int j=1;j<=i-1;j++)
          {
              for(auto k=dp[j].begin();k!=dp[j].end();k++)
                for(auto l=dp[i-j].begin();l!=dp[i-j].end();l++)
                    dp[i].insert(*k+*l);
          }
          
        }
        vector<string> all;
        for(auto j=dp[n].begin();j!=dp[n].end();j++)
            all.push_back(*j);
        return all;
    }
};
