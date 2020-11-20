/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
		// dfs 一遍过了，我真牛逼(看过一遍就会了)
		int res = 0;
		if (root == nullptr)
			return res;
		res++;
		if (root->left != nullptr && root->right != nullptr)
			return res + countNodes(root->left) + countNodes(root->right);
		if (root->left != nullptr)
			return res + countNodes(root->left);
		if (root->right != nullptr)
			return res + countNodes(root->right);
		return res;
    }
};
