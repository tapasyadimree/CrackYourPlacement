class Solution {
public:
    bool helper(TreeNode* root, int sum, int targetSum){
        if(root->left == NULL && root->right == NULL){
            return sum + root->val == targetSum;
        }

        sum += root->val;
        if(root->left != NULL && helper(root->left, sum, targetSum)) return true;
        if(root->right != NULL && helper(root->right, sum, targetSum)) return true;
        sum -= root->val;

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        
        return helper(root, 0, targetSum);
    }
};