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
    bool helper(TreeNode* lt,TreeNode* rt){
        if(lt == NULL && rt == NULL){
            return true;
        }
        if(lt != NULL && rt == NULL || lt == NULL && rt != NULL){
            return false;
        }
        if(lt->val != rt->val){
            return false;
        }
        
        bool check1 = helper(lt->left,rt->right);
        bool check2 = helper(lt->right,rt->left);

        return check1 && check2;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return helper(root->left,root->right);
    }
};