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
	int sumRootToLeaf(TreeNode* root) {
        int res=0;
		dfs(root,0,res);
		return res;
    }
	void dfs(TreeNode* root,int value, int & res)
	{
        if(root==nullptr) return;
		int Cvalue= value*2+root->val;
		if(root->left==nullptr&&root->right==nullptr)
			res+=Cvalue;
		else
		{
			dfs(root->left,Cvalue,res);
			dfs(root->right,Cvalue,res);
		}
	}
};