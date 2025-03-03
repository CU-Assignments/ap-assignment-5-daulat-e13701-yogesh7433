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
    long getLeftMax(TreeNode* root){
        long maxi = LONG_MIN;
        TreeNode* cur = root->left;
        while(cur){
            maxi = max(maxi,(long)cur->val);
            cur = cur->right;
        }
        return maxi;
    }

    long getRightSmall(TreeNode* root){
        long  mini = LONG_MAX;
        TreeNode* cur = root->right;
        while(cur){
            mini = min(mini,(long)cur->val);
            cur = cur->left;
        }
        return mini;
    }
    bool helper(TreeNode* root){
        if(!root) return true;

        long leftMax = getLeftMax(root);
        long rightSmall = getRightSmall(root);

        if(leftMax >= (long)root->val || rightSmall <= (long)root->val) return false;

        return helper(root->left) && helper(root->right);
    }
    
    bool helper2(TreeNode* root,long mini,long maxi){
        // simply defining the range for the cur root node
        if(!root) return true;
        if(mini >= root->val || root->val >= maxi) return false;

        return helper2(root->left,mini,root->val) && helper2(root->right,root->val,maxi);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        // the idea is to check if the cur root's leftSubree's maxVal < curRoot's val
        // and the cur root's rightSubtree's minValue > curRoot's val, then that tree is BST   
        if(!root) return true;
        if(!root->left && !root->right) return true;
        // return helper(root);
        return helper2(root,LONG_MIN,LONG_MAX);
        // TC = O(n), SC = O(1) 
    }
};