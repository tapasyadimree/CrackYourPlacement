class Solution {
public:
    int count = 0;
    void helper(TreeNode* root, long long preSum, int targetSum, map<long long, int> &mpp){
        if(root == NULL) return;

        preSum += root->val;

        long long remove = preSum - targetSum;
        if(mpp.find(remove) != mpp.end()) count += mpp[remove];

        mpp[preSum]++;

        helper(root->left, preSum, targetSum, mpp);
        helper(root->right, preSum, targetSum, mpp);

        mpp[preSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;

        map<long long, int> mpp;
        mpp[0] = 1;
        long long preSum = 0;
        
        helper(root, preSum, targetSum, mpp);

        return count;
    }
};