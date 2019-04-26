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
  int maxAncestorDiff(TreeNode* root) {
		int res = 0;
		Diff(root, res);
		return res;
	}
	void Diff(TreeNode* pNode,int &res)
	{
		if (!pNode) return;
		if (pNode)
		{
			int root_val = pNode->val;
			calculateDiff(pNode, root_val, res);
			Diff(pNode->left,res);
			Diff(pNode->right, res);
		}
	}
	void calculateDiff(TreeNode* pNode,int root_val,int &res)
	{
        if (!pNode) return;
		if (pNode)
		{
			res = max(res, abs(root_val - pNode->val));
			calculateDiff(pNode->left, root_val, res);
			calculateDiff(pNode->right, root_val, res);
		}
	}
};