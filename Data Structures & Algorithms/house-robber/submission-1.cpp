class Solution {
public:

    int logic(int idx, vector<int>& nums, vector<int>& dp)
    {
        if(idx < 0)
            return 0;
        
        if(idx == 0)
            return nums[idx];

        if(dp[idx] != -1)
            return dp[idx];

        int notRob = logic(idx-1,nums,dp);
        int Rob = nums[idx] + logic(idx-2,nums,dp);

        return dp[idx] = max(Rob,notRob);
    }

    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n,-1);
        return logic(n-1,nums,dp);
    }
};
