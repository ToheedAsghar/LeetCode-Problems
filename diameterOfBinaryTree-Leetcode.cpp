#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rec(TreeNode* root, int &d) {
       if(root == NULL) return 0;
       int ld = rec(root->left, d);
       int rd = rec(root->right, d);
       d=max(d,ld+rd);
       return max(ld,rd)+1;
}

int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        rec(root, d);
        return d;
}

int main(){
    TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);

    root->left = new TreeNode(2);
    //root->left->left = new TreeNode(3);

    cout << diameterOfBinaryTree(root);
    return 0;
}