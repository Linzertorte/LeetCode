class Solution {
public:
    //return the index of the first number larger than target
    int b_search(int A[],int n, int target){
        if(A[0]>target) return 0;
        int l=0,r=n;
        while(l+1<r){
            int mid=(l+r)>>1;
            if(A[mid]<=target) l=mid;
            else r=mid;
        }
        return r;
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        int a=b_search(A,n,target-1);
        int b=b_search(A,n,target);
        if(a==b) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        result.push_back(a);
        result.push_back(b-1);
        return result;
    }
};
