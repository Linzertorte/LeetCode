/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    public boolean Balanced(TreeNode root,int Ai[]) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root==null){
            Ai[0]=0;
            return true;
        }
        int A[]=new int[1];
        int B[]=new int[1];
        if(!Balanced(root.left,A)) return false;
        if(!Balanced(root.right,B)) return false;
        Ai[0]=Math.max(A[0],B[0])+1;
        return Math.abs(A[0]-B[0])<=1;
    }
    public boolean isBalanced(TreeNode root){
        int A[]=new int[1];
        return Balanced(root,A);
    }
}
