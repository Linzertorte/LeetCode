public class Solution {
    
    public int trap(int[] A) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int left[]=new int[A.length];
        int right[]=new int[A.length];
        int cur_max=0;
        for(int i=0;i<A.length;i++){
            left[i]=cur_max;
            cur_max=Math.max(cur_max,A[i]);
        }
        cur_max=0;
        for(int i=A.length-1;i>=0;i--){
            right[i]=cur_max;
            cur_max=Math.max(cur_max,A[i]);
        }
        int water=0;
        for(int i=0;i<A.length;i++){
            if(Math.min(left[i],right[i])>A[i]) water+=Math.min(left[i],right[i])-A[i];
        }
        return water;
    }
}
