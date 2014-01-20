public class Solution {
    public int bsearch(int[] A,int i,int j,int target) {
        if(target<A[i] || target>A[j]) return -1;
        int l=i,r=j+1;
        int mid;
        while(l+1<r){
            mid=(l+r)>>1;
            if(A[mid]<=target) l=mid;
            else r=mid;
        }
        return A[l]==target?l:-1;

    }
    public int search(int[] A, int target) {

        if(A.length==0) return -1;
        if(A.length==1) return A[0]==target?0:-1;
        if(A[0]<A[A.length-1]) return bsearch(A,0,A.length-1,target);

        //find the pivot                                                                         
        int l=0,r=A.length-1;
        int mid;
        while(l+1<r){
            mid = (l+r)>>1;
            if(A[mid]<A[r]) r=mid;
            else l=mid;
        }
        int ans = bsearch(A,0,l,target);
        if(ans==-1) return bsearch(A,r,A.length-1,target);
        else return ans;
    }
};
