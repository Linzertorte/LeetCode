class Solution {
public:
    int jump(int A[], int n) {
        if(n==1) return 0;
        int right=A[0]; //current rightmost reachable
        int cnt=1;
        int i=1;
        while(i<n){
            if(right>=n-1) break;
            int local=0;
            while(i<=right) local=max(local,A[i]+i),i++;
            cnt++,right=local;
        }
        return cnt;
    }
};
