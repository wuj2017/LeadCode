//方法一
class Solution {
public:
    string removeOuterParentheses(string S) {
	    if (S.size() == 0) return nullptr;
		int left = 0, right = 0;
		string res;
		for (int i = 1; i < S.size(); i++)
		{
			if (left == right  && S[i] == ')')
				i++;
			else if (S[i] == '(')
			{
				left++;
				res += '(';
			}
			else if (S[i] == ')')
			{
				right++;
				res += ')';
			}
		}
		return res;
    }
};

//方法二，用栈的方法
class Solution {
public:
    string removeOuterParentheses(string S) {
        if (S.size() == 0) return nullptr;
		string res;
        vector<char> stack;
		for (char ch: S)
		{
			if (ch=='(')
			{
				stack.push_back(ch);
				if (stack.size()!=1)
					res += '(';
			}
			else if (ch==')')
			{
				if (stack.size() != 1)
					res += ')';	
				stack.pop_back();
			}	
		}
		return res;
    }
};