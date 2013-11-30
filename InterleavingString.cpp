class Solution {
    
public:
   
  bool isInterleave(string s1, string s2, string s3) {
    int n1=s1.size();
    int n2=s2.size();
    int n3=s3.size();
    if(n1+n2!=n3) return false;
    if(!n3) return true;
    if(!n1) return s2==s3;
    s1=" "+s1;
    s2=" "+s2;
    s3=" "+s3;
    vector<vector<bool> > dp(n1+1,vector<bool> (n3+1));
        
    dp[0][0]=true;
    for(int i=0;i<=n1;i++)
      for(int k=1;k<=n3;k++)
	{
	  bool flag=false;
	  int j=k-i;
	  if(i>k) flag=false;
	  else {
	    if(i&& s1[i]==s3[k] && dp[i-1][k-1]) flag=true;
	    if(j&& s2[j]==s3[k] && dp[i][k-1]) flag=true;
	  }
	  dp[i][k]=flag;
	}
    }
    return dp[n1][n3];
  }
};
