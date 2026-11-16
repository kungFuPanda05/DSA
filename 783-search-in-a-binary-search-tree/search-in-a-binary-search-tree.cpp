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
    TreeNode* f(TreeNode* root, int val){
        if(!root) return root;
        if(val==root->val) return root;

        if(val<root->val) return f(root->left, val);
        if(val>root->val) return f(root->right, val);
        return NULL;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return f(root, val);
    }
};