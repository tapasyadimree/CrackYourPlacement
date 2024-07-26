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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t == NULL) return true;
        if(s == NULL) return false;

        if(sameTree(s,t)) return true;

        return (isSubtree(s->left, t) || isSubtree(s->right, t));
    }

    bool sameTree(TreeNode* s, TreeNode* t){
        if(s == NULL && t == NULL) return true;

        if(s && t && s->val == t->val)
            return (sameTree(s->left, t->left) && sameTree(s->right, t->right));

        return false;
    }
};