class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int t = 0;

        for(int x: nums)
        {
            t = t ^ x;
        }

        for(int i=1;i<=n;i++)
        {
            t = t ^ i;
        }

        return t;
    }
};
