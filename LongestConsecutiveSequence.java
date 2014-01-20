public class Solution {
    public int longestConsecutive(int[] num) {
        HashSet<Integer> set=new HashSet<Integer>();
        for(int i:num) set.add(i);
        int ans=0;
        for(int i:num){
            int len=1;
            for(int j=i-1;set.contains(j);j--){
                set.remove(j);
                len++;
            }
            for(int j=i+1;set.contains(j);j++){
                set.remove(j);
                len++;
            }
            ans=Math.max(ans,len);
            
        }
        return ans;
    }
}
