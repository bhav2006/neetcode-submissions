class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        set<vector<int>> ans;

        for(int i=0;i<n;i++)
        {
            int j=i+1,k=n-1;

            int target = -nums[i];
            while(j<n && j<k)
            {
                int sum = nums[j]+nums[k];
                if(sum==target)
                {
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum>target)
                    k--;
                else
                    j++;
            }
        }

        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};
