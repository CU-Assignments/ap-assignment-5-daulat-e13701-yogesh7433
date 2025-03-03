class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;

        // normal bfs traversal, 
        // catch is that when you switch to new level reverse the order of nodes
        queue<TreeNode*>q;
        q.push(root);

        int flag = 0;   // maintain a flag to check for level switch
        while(!q.empty()){
            int sz = q.size();

            vector<int>v;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                v.push_back(node->val);

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);                
            }
            if(flag == 1){
                reverse(v.begin(),v.end());
            }
            ans.push_back(v);
            flag = !flag;
        }

        return ans;
    }
};