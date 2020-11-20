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
    bool isSymmetric(TreeNode* root) {
		return isMirror(root, root);	
    }

	bool isMirror(TreeNode* p, TreeNode* q) {
		if ((p == nullptr) && (q == nullptr))
			return true;
		if ((p->left == nullptr) ^ (q->right == nullptr))
			return false;
		if ((p->right == nullptr) ^ (q->left == nullptr))
			return false;
		return isMirror(p->left, q->right) && isMirror(p->right, q->left);
	}
};
