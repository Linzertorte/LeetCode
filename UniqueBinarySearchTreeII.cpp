/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> gen(int n,int plus){
        vector<TreeNode *> total;
        if(!n){
            total.push_back(NULL);
            return total;
        }
        if(n==1){
            total.push_back(new TreeNode(n+plus));
            return total;
        }
        vector<TreeNode *> left;
        vector<TreeNode *> right;
     
        for(int i=1;i<=n;i++){
            
            left=gen(i-1,plus);
            for(int j=0;j<left.size();j++){
                right=gen(n-i,plus+i);
                for(int k=0;k<right.size();k++){
                    TreeNode *n=new TreeNode(i+plus);
                    n->left=left[j],n->right=right[k];
                    total.push_back(n);
                }
            }
        }
        return total;
        
    }
    vector<TreeNode *> generateTrees(int n) {
        return gen(n,0);
    }
};
