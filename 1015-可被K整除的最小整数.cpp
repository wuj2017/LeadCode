class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0)
			return -1;
		int count = 1;
		for (int N = 1;;)
		{
			if (N % K == 0)
				return count;
			N = (N * 10 + 1)%K;//大数取余，原理可以查看https://blog.csdn.net/qq_32779119/article/details/79513480
			count++;
		}
    }
};