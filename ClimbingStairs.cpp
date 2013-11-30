class Solution {
public:
    int climbStairs(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n<=2) return n;
        int a=1,b=2;
        int c,i;
        for(i=3;i<=n;i++)
        {    c=a+b;
             a=b;
             b=c;
        }
        return b;
    }
};
