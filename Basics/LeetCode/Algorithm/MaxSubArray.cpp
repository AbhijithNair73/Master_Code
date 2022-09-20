// kadane's algorithm to find max sub array 
//   https://www.youtube.com/watch?v=YxuK6A3SvTs
 int maxSubArray(vector<int>& nums) {
        //kadane's algo modified to give negative number
        int currentMax = 0;
        int maxSoFar = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            currentMax = currentMax + nums[i];
            if(currentMax<nums[i])
            {
                currentMax = nums[i];
            }
            if(maxSoFar < currentMax)
            {
                maxSoFar = currentMax;
            }
        }
        return maxSoFar;
        
    }