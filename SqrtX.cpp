class Solution {
public:
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(x<=1) return x;
        int low=0,hi=x;
        while(low+1<hi){
            long long mid=(low+hi)>>1;
            if(mid*mid<=x) low=mid;
            else hi=mid;
        }
        return low;
    }
};
