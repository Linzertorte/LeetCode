class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        //return first >=
        if(!n ||A[0]>=target) return 0;
        int l=0,r=n;
        while(l+1<r){
            int mid=(l+r)>>1;
            if(A[mid]<target) l=mid;
            else r=mid;
        }
        return r;
    }
};
