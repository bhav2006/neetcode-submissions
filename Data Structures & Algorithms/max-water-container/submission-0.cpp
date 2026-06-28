class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int n = heights.size();
        int area = INT_MIN;

        int i=0,j=n-1;

        while(i<j)
        {
            int curr_area = min(heights[i],heights[j])*(j-i);

            if(curr_area > area)
            {
                area = curr_area;
            }

            if(heights[i]<heights[j])
                i++;
            else
                j--;
        }

        return area;
    }
};
