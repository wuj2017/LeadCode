class Solution {
public:
    string baseNeg2(int N) {
        
        string str;
		string ch;
        if(N==0)
            return str="0";
		while (N!=0)
		{
			ch = to_string(abs(N % 2));
			str = ch + str;
			N = ceil(N / -2.0);//C++������ȡ�࣬����ȡ����floor();
		}
		return str;
    }
};