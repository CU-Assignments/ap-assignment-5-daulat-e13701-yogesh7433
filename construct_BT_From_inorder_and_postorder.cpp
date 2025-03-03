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
    TreeNode* solve(vector<int>&postorder,int postStart,int postEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&mp){
        if(postStart > postEnd  || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inLeftEnd = mp[postorder[postEnd]]-1;
        int inRightStart = mp[postorder[postEnd]]+1;
        int postLeftEnd = postStart + (inLeftEnd - inStart);
        int postRightStart = postLeftEnd + 1;

        root->left = solve(postorder,postStart,postLeftEnd,inorder,inStart,inLeftEnd,mp);
        root->right = solve(postorder,postRightStart,postEnd-1,inorder,inRightStart,inEnd,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // do the mapping of the inorder to keep track of indices
        // all same as inorder and preorder, just make the right recursive calls
        int n = postorder.size();
        int m = inorder.size();

        map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[inorder[i]] = i;
        }
        return solve(postorder,0,n-1,inorder,0,m-1,mp);
        // TC = O(n*log(n)), SC = O(n)
    }
};