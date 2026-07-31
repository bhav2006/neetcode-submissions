class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        int reachable = 0;

        for(int i=0;i<n;i++)
        {
            if(i<=reachable)
            {
                if(i == n-1)    return true;
                reachable = max(reachable,i+nums[i]);
            }
            else
            {
                break;
            }
        }
        return false;
    }
};
