// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int amountOfTime(TreeNode* root, int start);
unordered_map<int, vector<int>> ConvertToList(TreeNode* root, vector<int>& tree);

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);

    // root->left = new TreeNode(2);
    // root->left->left = new TreeNode(3);
    // root->left->left->left = new TreeNode(4);
    // root->left->left->left->left = new TreeNode(5);

    cout << amountOfTime(root, 3);
}
// [1,2,null,3,null,4,null,5] : ans=2

int amountOfTime(TreeNode* root, int start) {
    if ((nullptr == root) || (nullptr == root->left && nullptr == root->right)) {
        return 0;
    }
    vector<int> keys;

    unordered_map<int, vector<int>> graph = ConvertToList(root, keys);
    unordered_map<int, bool> visited;
    int time = 0;

    queue<int> que;
    que.push(start);

    while(!que.empty()){
        int k = que.size();
        while(k--){
            int temp = que.front();
            que.pop();
            visited[temp] = true;
            for(auto it: graph[temp]){
                if(visited[it] == false){
                    que.push(it);
                }
            }
        }
        time++;
    }
    return time-1;
}

unordered_map<int, vector<int>> ConvertToList(TreeNode* root, vector<int>& tree) {
    unordered_map<int, vector<int>> m;
    tree.push_back(root->val);

    TreeNode* parent;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
        TreeNode* temp = que.front();
        que.pop();
        TreeNode* left = temp->left;
        TreeNode* right = temp->right;

        if (left) {
            tree.push_back(left->val);
            m[temp->val].push_back(left->val);
            m[left->val].push_back(temp->val);
            que.push(left);
        }
        if (right) {
            tree.push_back(right->val);
            m[temp->val].push_back(right->val);
            m[right->val].push_back(temp->val);
            que.push(right);
        }
    }
    return m;
}