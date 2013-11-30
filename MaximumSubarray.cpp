class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum=A[0];
        int m=0;
        int i,j=0;
        for(i=0;i<n;i++){
            m+=A[i];
            sum=max(sum,m);
            while(m<0) m-=A[j++];
        }
        return sum;
    }
};
