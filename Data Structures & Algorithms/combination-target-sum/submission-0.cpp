class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(int idx, int target, vector<int>& nums)
    {
        if(target == 0)
        {
            ans.push_back(path);
            return;
        }
        if(idx == nums.size())
            return;

        if(nums[idx] <= target)
        {
            path.push_back(nums[idx]);
            solve(idx, target - nums[idx], nums);   // same index
            path.pop_back();                        // backtrack
        }
        solve(idx + 1, target, nums);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target)
    {
        solve(0, target, nums);
        return ans;
    }
};