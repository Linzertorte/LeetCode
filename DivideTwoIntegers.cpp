class Solution {
public:
    int divide(int dividend, int divisor) {
        long long total=0;
        
        long long quo=0;
        int sign=1;
        long long dd=(long long)dividend;
        if(dd<0) sign=-sign,dd=-dd;
        long long d=(long long)divisor;
        if(d<0) sign=-sign,d=-d;
        
        for(int k=31;k>=0;k--)
            if(total+(d<<k)<=dd) total+=(d<<k),quo+=(1<<k);
        
        
        if(sign<0) quo=-quo;
        return quo;
    }
};
