class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int ans = 0;
		// dp records the index of A with pair <diff,cnt>
		vector<unordered_map<int, int>> dp(A.size());
		for (int i = 1; i < (int)A.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				int diff = A[i] - A[j];
				int len = 2;
				if (dp[j][diff]>0){
					len = dp[j][diff] + 1;
				}
				int curr = dp[i][diff];
				dp[i][diff] = max(curr, len);
				ans = max(ans, dp[i][diff]);
			}
		}
		return ans;
    }
};