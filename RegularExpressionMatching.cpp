class Solution {
public:
    bool isMatch_helper(const char *s,const char *p,int i,int j,int len1,int len2){
        if(i==len1 && j==len2) return true;
        
        if(j==len2) return false;
        if(j+1<len2&&p[j+1]=='*'){
            if(isMatch_helper(s,p,i,j+2,len1,len2)) return true;
            for(int k=i;(p[j]=='.' || s[k]==p[j])&&k<len1; k++)
                if(isMatch_helper(s,p,k+1,j+2,len1,len2)) return true;
        }
        return (p[j]=='.'||s[i]==p[j]) && isMatch_helper(s,p,i+1,j+1,len1,len2);

    }
    bool isMatch(const char *s, const char *p){
        //cout<<strlen(s)<<endl;                                                                                                                    
     
        return isMatch_helper(s,p,0,0,strlen(s),strlen(p));
    }
};

