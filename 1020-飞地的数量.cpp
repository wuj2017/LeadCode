 	int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };  
class Solution {
public: 
    int numEnclaves(vector<vector<int>>& A) {
		int row = A.size();//行数
		int col = A[0].size();//列数

		//从边界开始
		int result = 0;
		for (int i = 0; i < row;i++)
		{
			if (A[i][0] == 1)	DFS(i, 0, A);
			if (A[i][col - 1] == 1)	DFS(i, col - 1, A);
		}
		for (int j = 0; j < col; j++)
		{
			if (A[0][j] == 1) DFS(0, j, A);
			if (A[row-1][j] == 1) DFS(row-1, j, A);
		}
		for (int i = 0; i < row;i++)
		{
			for (int j = 0; j < col;j++)
			{
				if (A[i][j] == 1) result++;
			}
		}
		return result;
	}
	void DFS(int i, int j,vector<vector<int>>& map)
	{
		map[i][j] = 0;
		for (int k = 0; k < 4; k++)
		{
			int x = i + dx[k];
			int y = j + dy[k];
			if (x >= 0 && x < map.size() && y >= 0 && y < map[0].size() && map[x][y] == 1)
			{
				DFS(x, y, map);
			}
		}
	}
};


方法二：思路没错，递归层数太多，提示堆栈溢出
class Solution {
public:
	int numEnclaves(vector<vector<int>>& A) {
		int row = A.size();//行数
		int col = A[0].size();//列数
		//从边界开始
		int result = 0;
		for (int i = 0; i < row;i++)
		{
			if (A[i][0] == 1) DFS(i, 0, A);
			if (A[i][col - 1] == 1) DFS(i, col - 1, A);
		}
		for (int j = 0; j < col; j++)
		{
			if (A[0][j] == 1) DFS(0, j, A);
			if (A[row-1][j] == 1) DFS(row-1, j, A);
		}
		for (int i = 0; i < row;i++)
		{
			for (int j = 0; j < col;j++)
			{
				if (A[i][j] == 1) result++;
			}
		}
		return result;
	}
	void DFS(int i, int j,vector<vector<int>>& map)
	{
		if (i<0 || i>map.size() || j<0 || j>map[0].size() || map[i][j] == 0)
			return;
		map[i][j] = 0;
		DFS(i - 1, j, map);
		DFS(i, j - 1, map);
		DFS(i + 1, j, map);
		DFS(i, j + 1, map);
	}
};