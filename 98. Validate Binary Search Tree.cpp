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
    TreeNode* lastVisited;
    bool dfs(TreeNode* root){

        if(!root) return true;

        if(!dfs(root->left)) return false;

        if(lastVisited and lastVisited->val >= root->val) return false;

        lastVisited = root;

        if(!dfs(root->right)) return false;

        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        lastVisited = nullptr;
        return dfs(root);
    }
};
