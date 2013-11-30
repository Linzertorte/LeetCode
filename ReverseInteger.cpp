class Solution {
public:
    int reverse(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int sign=1;
        if(x<0) sign=-1,x=-x;
        long long res=0;
        while(x){
            res=res*10+(x%10);
            x/=10;
        }
        return res*sign;
    }
};
