class Solution {
public:

  vector<int> compute_fail(char *s){
    vector<int> next(strlen(s));
    if(!next.size()) return next;
    next[0]=-1;
    int p=-1;
    for(int i=1;i<next.size();i++){
      while(p>-1 && s[p+1]!=s[i]) p=next[p];
      if(s[p+1]==s[i]) p++;
      next[i]=p;
    }
    return next;
  }
  char *kmp(char *s,char *p)
  {
    if(!strlen(p)) return s;
    vector<int> next=compute_fail(p);
    int t=-1;
    int n=strlen(s);
    int m=strlen(p);
    for(int i=0;i<n;i++){
      while(t>-1 && p[t+1]!=s[i]) t=next[t];
      if(p[t+1]==s[i]) t++;
      if(t==m-1) return s+i-m+1;
    }
    return NULL;
  }
  char *strStr(char *haystack, char *needle) {
    return kmp(haystack,needle);
  }
};
