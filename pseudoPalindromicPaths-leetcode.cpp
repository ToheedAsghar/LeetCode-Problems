// link: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/
#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int pseudoPalindromicPaths(TreeNode* root);

int main() {
	TreeNode* root = new TreeNode(2);
	/*root->left = new TreeNode(1);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->left->right->right = new TreeNode(3);
	root->right = new TreeNode(1);*/

	root->left = new TreeNode(3);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(1);
	root->right->right = new TreeNode(1);

	cout << pseudoPalindromicPaths(root);

}

void dfs(TreeNode* root, unordered_map<int, int>& hm, int& cnt) {
	if (nullptr == root) {
		return;
	}
	hm[root->val]++;
	if (nullptr == root->left && nullptr == root->right) { // leaf node
		// iterating the hashmap for checking the odd parity
		int t = 0; // storing the odd count
		for (const auto& pair : hm) {
			if (pair.second % 2 != 0) {
				t++;
				if (t > 1) {
					hm[root->val]--;
					return;
				}
			}
		}
		cnt++;
	}
	else {
		dfs(root->left, hm, cnt);
		dfs(root->right, hm, cnt);
	}
	hm[root->val]--;
}

int pseudoPalindromicPaths(TreeNode* root) {
	if (nullptr == root) {
		return 0;
	}
	int cnt = 0;
	unordered_map<int, int> hm;
	dfs(root, hm, cnt);
	return cnt;
}