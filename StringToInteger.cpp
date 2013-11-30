class Solution {
public:
    int atoi(const char *str) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        const char *s=str;
        int sign=1;
        long long ans=0;
        while(*s==' ') s++;
        if(*s=='+') sign=1,s++;
        if(*s=='-') sign=-1,s++;
        while(*s>='0' && *s<='9'){
          ans=(*s -'0')+ans*10;
          if(sign==1&& ans>2147483647LL) return INT_MAX;
          if(sign==-1 && ans>2147483648LL) return INT_MIN;
          s++;
        }
        
        return sign*ans;
        
        
    }
};
