// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxAncestorDiff(TreeNode *root);
void dfs(TreeNode* root, vector<int> temp, vector<vector<int>>& paths);

int main()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    cout << maxAncestorDiff(root) << '\n';
    return 0;
}

void dfs(TreeNode* root, vector<int> temp, vector<vector<int>>& paths){
    if(nullptr == root){
        return;
    }

    temp.push_back(root->val);

    if(nullptr == root->left && nullptr == root->right){
        paths.push_back(temp);
    }
    else{
        dfs(root->left, temp, paths);
        dfs(root->right, temp, paths);
    }
}

int maxAncestorDiff(TreeNode *root){
    if(nullptr == root){
        return 0;
    }

    vector<vector<int>> paths;
    vector<int> temp;
    dfs(root, temp, paths);

    for(int i=0; i<paths.size(); i++){
        sort(paths[i].begin(), paths[i].end());
    }

    int maxDiff = -1;
    for(int i=0; i<paths.size(); i++){
        int t = abs(paths[i][0] - paths[i][paths[i].size()-1]);
        maxDiff = max(maxDiff, t);
    }

    return maxDiff;
}