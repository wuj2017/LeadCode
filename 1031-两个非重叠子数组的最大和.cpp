    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
				int maxL = 0, maxM = 0;
				int res = 0;
				//L在前，M在后
				for(int i = 0;i <= A.size()-L-M;i++)
				{
					maxL = max(maxL, sumcal(A, i, i + L - 1));
					res = max(res, sumcal(A, i + L, i + L + M - 1) + maxL);
				}
				//M在前，L在后
				for(int i = 0; i <= A.size()-M-L; i++)
				{
					maxM = max(maxM, sumcal(A, i, i + M - 1));
					res = max(res, sumcal(A, i + M, i + M + L - 1) + maxM);
				}

				return res;
	}
	int sumcal(vector<int>& A,int left,int right )
	{
			int sum=0;
			for(int i = left; i <= right; i++)
			{
				sum+=A[i];
			}
			return sum;
	}