/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void helper(TreeNode* root,int &k,int &ans){
        if(!root) return;

        helper(root->left,k,ans);
        k--;
        if(k==0){
            ans = root->val; return;
        }
        helper(root->right,k,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // use the property of BST, its inorder is always sorted so everytime
        // so everytime visiting the smallest node do k-- and if k is 0 that root will be the kth 
        // smallest
        // TC = O(n), SC = O(1)
        int ans = 0;
        helper(root,k,ans);
        return ans;
    }
};