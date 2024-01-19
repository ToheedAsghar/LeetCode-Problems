// https://leetcode.com/problems/balanced-binary-tree/description/ 
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

void inOrder(TreeNode* node);
bool isBalanced(TreeNode* root);
int countChilds(TreeNode* root);

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->right->right->right = new TreeNode(4);

/*
    [1,2,2,3,null,null,3,4,null,null,4]
                        1
                       / \
                      2   2
                    /     \
                   3       3
                  /         \
                 4           4
*/
    cout << isBalanced(root) << endl;
    return 0;
}

bool isBalanced(TreeNode* root){
    if(nullptr == root){
        return true;
    }
    int leftCount = countChilds(root->left);
    int rightCount = countChilds(root->right);

    if(abs(leftCount - rightCount) > 1){
        return false;
    }
    else{
        return isBalanced(root->left) && isBalanced(root->right);
    }
}

int countChilds(TreeNode* root){
    if(nullptr == root){
        return 0;
    }
    if(nullptr == root->left && nullptr == root->right){
        return 1;
    }
    else{
        return 1 + max(countChilds(root->left), countChilds(root->right));
    }
}

void inOrder(TreeNode* node){
    if(nullptr == node){
        return;
    }
    else{
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }
}