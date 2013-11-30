class Solution {
public:
    double pow(double x, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!n) return 1.0;
        if(!x) return 0;
        int sign=1;
        if(x<0) sign=-1,x=-x;
        double ans=1;
        for(int i=0;i<abs(n);i++){
            if(fabs(ans-ans*x)<1e-20) break;
            ans*=x;
        }
        if(n<0) return ((n%2)?sign:1)*1.0/ans;
        else return ((n%2)?sign:1)*ans;
    }
};
