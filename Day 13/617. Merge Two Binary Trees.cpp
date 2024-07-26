class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return NULL;
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;

        root1->val = root1->val + root2->val;
        
        if(root1->left == NULL && root2->left != NULL){
            root1->left = new TreeNode();
        }
        else if(root1->left != NULL && root2->left == NULL){
            root2->left = new TreeNode();
        }

        if(root1->right == NULL && root2->right != NULL){
            root1->right = new TreeNode();
        }
        else if(root1->right != NULL && root2->right == NULL){
            root2->right = new TreeNode();
        }

        mergeTrees(root1->left, root2->left);
        mergeTrees(root1->right, root2->right);

        return root1;
    }
};