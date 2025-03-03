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
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            if(root == NULL) return {};
    
            queue<TreeNode*>pending;
            vector<vector<int>>ans;
    
            pending.push(root);
            while(!pending.empty()){
                int size = pending.size();
                vector<int>v;
                // storing all the elements at the same level in the v ans pushing back their child
                for(int i=0;i<size;i++){
                    TreeNode* node = pending.front();
                    pending.pop();
                    // store all the children of node in the queue
                    if(node->left != NULL){
                        pending.push(node->left);
                    }
                    if(node->right != NULL){
                        pending.push(node->right);
                    }
                    v.push_back(node->val);
                }
    
                // push back all elements of same level in the ans vector
                ans.push_back(v);
            }
            return ans;
        }
    };