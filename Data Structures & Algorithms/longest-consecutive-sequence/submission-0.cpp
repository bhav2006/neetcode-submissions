class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> st(nums.begin(),nums.end());
        int maxLen = 0;

        for(int x: st)
        {
            if(st.find(x-1)==st.end())
            {
                int curr = 1;
                while(st.find(x+curr)!=st.end())
                    curr++;

                maxLen = max(maxLen,curr);
            }
        }

        return maxLen;
    }
};
