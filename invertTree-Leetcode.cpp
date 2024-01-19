#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root);
void inOrder(struct TreeNode* node);

int main(){
    struct TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    inOrder(root);
    cout << endl;
    
    struct TreeNode* invertedRoot;
    invertedRoot = invertTree(root);
    inOrder(invertedRoot);
    return 0;
}

TreeNode* invertTree(TreeNode* root){
    if(nullptr == root){
        return root;
    }
    if(nullptr == root->left && nullptr == root->right){
        return root;
    }
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);

    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}

void inOrder(struct TreeNode* node){
    if(nullptr == node){
        return;
    }
    else{
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }
}