class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       /* vector<int> dp(nums.size(),1);
        if(nums.size()==1) return 1;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;*/
        vector<int> temp;
       // temp.push_back(nums[0]);
        for(auto i : nums)
        {
            if(temp.empty()) temp.push_back(i);
            else if(i<=temp[0]) temp[0]=i;
            else if(i>temp.back()) temp.push_back(i);
            else
            {
                int begin=0,end=temp.size()-1;
                while(begin<end)
                {
                    int mid=(begin+end)/2;
                    if(i>temp[mid]) begin=mid+1;
                    else end=mid;
                }
                temp.at(end)=i;
            }
        }
        return temp.size();
    }
};