// https://leetcode.com/problems/largest-bst-subtree/

class Solution {
    class InfoBST{
        public:
            int mx;
            int mn;
            int sz;
        InfoBST(int m, int n, int s) : mx(m), mn(n), sz(s){}
    };
    
    InfoBST postOrderBST(Node* root){
        if(!root) return InfoBST(INT_MIN, INT_MAX, 0);
        
        auto left = postOrderBST(root->left);
        auto right = postOrderBST(root->right);
        
        if(root->data > left.mx and root->data < right.mn){
            // the tree is BST
            return InfoBST(max(root->data, right.mx), min(root->data, left.mn), 1 + left.sz + right.sz);
        }
        
        return InfoBST(INT_MAX, INT_MIN, max(left.sz, right.sz));
    }
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        return postOrderBST(root).sz;
    }
};
