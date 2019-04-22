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
    TreeNode* recoverFromPreorder(string S) {
     	vector<TreeNode*> pNode;
		for (int i = 0; i < S.size();)
		{
			int num = 0;
			int num_d = 0;
			while (i<S.size() && S[i] == '-')
			{
				num_d++;
				i++;
			}
			while (i<S.size() && S[i] >= '0' && S[i] <= '9')
			{
				num = num * 10 + S[i] - '0';
				i++;
			}
			while (pNode.size() != num_d)
			{
				pNode.pop_back();
			}
			TreeNode* node = new TreeNode(num);
			if (num_d!=0)
			{
				TreeNode * pRoot = pNode.back();
				if (pRoot->left == NULL)
					pRoot->left = node;
				else
					pRoot->right = node;
			}
			pNode.push_back(node);
		}
		return pNode[0];   
    }
};