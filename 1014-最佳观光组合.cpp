class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int left_max = 0;
		int res = 0;
//根据计算公式A[i] + A[j] + j - i，先计算并保存A[j]+j的最大值，再加上A[i] + i，取最大
		for (int i = 0; i < A.size();i++)
		{
			res = max(res, left_max + A[i] - i);
			left_max = max(left_max, i + A[i]);
		}
		return res;
    }
};