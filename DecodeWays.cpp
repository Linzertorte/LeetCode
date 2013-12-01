class Solution {
public:

    bool check(char c1,char c2){
        if(c1=='1') return true;
        if(c1=='2') return c2<='6';
        return false;
    }
    int numDecodings(string s) {
        if(!s.size()) return 0;
        vector<int> dp(s.size()+1);
        dp[0]=1;
        for(int i=1;i<=s.size();i++){
            dp[i]=0;
            if(s[i-1]!='0')dp[i]+=dp[i-1];
            if(i-2>=0&&check(s[i-2],s[i-1])) dp[i]+=dp[i-2];
        }
        return  dp[s.size()];
    }
};
