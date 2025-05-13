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
    void flatten(TreeNode* root) {
        if(!root) return;
        if(nullptr == root->left and nullptr == root->right) return;

        TreeNode* curr = root;
        while(nullptr != curr){

            // if curr has a left child
            if(curr->left){
                // finding the predecessor
                TreeNode* pre = curr->left;
                while(pre->right){
                    pre = pre->right;
                }

                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};
