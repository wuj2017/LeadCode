class Solution {
public:
bool queryString(string S, int N) {
		for (int i = 1; i <= N;i++)
		{
			string sub = changeBit(i);
			if (!findStr(S, sub))
				return false;
		}
		return true;
	}
	string changeBit(int N)//转化为二进制
	{
		string str;
		string ch = "";
		if (N <= 0)
			return NULL;
		while (N != 0)
		{
			ch = to_string(N % 2);
			str = ch + str;
			N /= 2;
		}
		return str;
	}
	bool findStr(string str, string sub)// 是否存在
	{
		if (str.empty() && sub.empty())
			return false;
		for (int i = 0; i < str.size();i++)
		{
			int temp = i;
			for (int j = 0; j < sub.size();j++)
			{			
				if (str[temp] == sub[j])
				{
					temp++;
					//j++;
				}
				else
					break;
				if (j == sub.size() - 1)
					return true;
			}
		}
		return false;
	}
};