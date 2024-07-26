class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;

        int sum = 0;
        if(root->val >= low && root->val <= high) sum += root->val;
        if(root->left != NULL) sum += rangeSumBST(root->left, low, high);
        if(root->right != NULL) sum += rangeSumBST(root->right, low, high);

        return sum;
        
    }
};