class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int16_t winSize = nums.size() - k + 1;
        int win[nums.size() - k + 1];
        int winSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            winSum += nums[i];
            if (i >= k) {
                winSum -= nums[i - k];
            } 
            if (i >= k - 1) {
                win[i - k + 1] = winSum;
            }
        }
   
        int16_t leftSize = winSize - k;
        int leftMax[leftSize];  
        vector<int>& rightMax = nums; 
         
        int best = 0;
        for (int i = 0; i < winSize - k; i++) {
            if (win[i] > win[best]) {
                 best = i;
            }
            leftMax[i] = best;
        }
         
        best = winSize - 1;
        for (int i = winSize - 1; i >= 0; i--) {
            if (win[i] >= win[best]) {
                 best = i;
            }
            rightMax[i] = best;
        }
        
        vector<int> ans = {-1, -1, -1};
        int i = -1, l = -1;
        for (int j = k; j < winSize - k; j++) {
            i = leftMax[j - k]; l = rightMax[j + k];
            if (ans[0] == -1 || win[i] + win[j] + win[l] > win[ans[0]] + win[ans[1]] + win[ans[2]]) {
                ans[0] = i;
                ans[1] = j;
                ans[2] = l;
            }
        }
        
        return ans;
    }
};
