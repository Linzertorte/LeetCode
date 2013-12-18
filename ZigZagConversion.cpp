class Solution {
public:
    string convert(string s, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.  
        string r=s;
        int step=2*n-2;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i==0 || i==n-1){
                for(int j=i;j<s.size();j+=step?step:1)
                    r[cnt++]=s[j];
            }
            else{
                for(int j=i;j<s.size();j+=step?step:1){
                    r[cnt++]=s[j];
                    int k=j+step-2*i;
                    if(k<s.size()) r[cnt++]=s[k];
                    
                }
            }
        }
        return r;
    }
};
