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
    pair<int, int> f(TreeNode* root){

        if(!root) return {0, 0};
        if(!root->left && !root->right) return {1, root->val};

        pair<int, int> left = f(root->left);
        pair<int, int> right = f(root->right);


        int sum = left.first + right.first;

        if((root->val >= left.second) && (root->val >= right.second)){
            sum++;
        }
        return {sum, max({left.second, right.second, root->val})};
    }


    int countDominantNodes(TreeNode* root) {
        return f(root).first;
    }
};