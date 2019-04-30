class Solution {
public:
//必须是静态函数
    static bool cmp( vector<int> a, vector<int> b){
        return a[0] - a[1] > b[0] - b[1];
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0;
        
        sort( costs.begin(), costs.end(), cmp);
  
        for( int i = 0, j = costs.size()-1; i < j; i++, j--)
            res += costs[i][1] + costs[j][0];
        return res;
    }
};