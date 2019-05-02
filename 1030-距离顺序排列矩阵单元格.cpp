class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
     	vector<vector<int>> res;
		//r0,c0后面
		for (int i = r0+1; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				res.push_back({i, j});
			}
		}
		for (int i = r0-1; i >= 0; i--)
		{
			for(int j = C-1; j >= 0; j--)
			{
				res.push_back({i, j});
			}
		}
		for (int i = r0; i == r0; i++)
		{
			for (int j = 0; j < C; j++)
			{
				res.push_back({i, j});
			}
		}
        //两种方法
		// sort(res.begin(), res.end(), [&](vector<int> a, vector<int> b){
        //       return abs(a[0]-r0) + abs(a[1]-c0) < abs(b[0]-r0) + abs(b[1]-c0);});
 
		sort(res.begin(), res.end(), [r0,c0](vector<int> a, vector<int> b){
        	return abs(a[0]-r0) + abs(a[1]-c0) < abs(b[0]-r0) + abs(b[1]-c0);});
		return res;
    }
};
