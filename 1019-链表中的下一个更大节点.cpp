class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
		vector<int> res,stack;//stack保存下一个最大节点的索引
		for (ListNode * pNode = head; pNode != NULL; pNode = pNode->next)
		{
			while (stack.size()!=0 && res[stack.back()]<pNode->val)
			{
				res[stack.back()] = pNode->val;//
				stack.pop_back();
			}
			stack.push_back(res.size());
			res.push_back(pNode->val);//将节点的值依次压入res
		}
		for (int i = 0; i < stack.size();i++)
		{
			res[stack[i]] = 0;
		}
		return res;
	}
};