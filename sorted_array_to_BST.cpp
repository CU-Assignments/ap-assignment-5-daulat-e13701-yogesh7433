class Solution {
    TreeNode* helper(vector<int>&nums,int start,int end){
        int mid = (start+end)/2;
        if(start > end) return NULL;

        TreeNode* finalroot = new TreeNode(nums[mid]);

        TreeNode* leftroot = helper(nums,start,mid-1);
        finalroot->left = leftroot;

        TreeNode* rightroot = helper(nums,mid+1,end);
        finalroot->right = rightroot;

        return finalroot;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,n-1);
    }
};
