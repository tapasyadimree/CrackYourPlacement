class Solution {
public:
    void inorder(TreeNode* root, vector<int> &arr){
        if(root == NULL) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);

        int mini = INT_MAX;
        for(int i = 1; i < arr.size(); i++){
            mini = min(mini, arr[i] - arr[i-1]);
        }

        return mini;
    }
};