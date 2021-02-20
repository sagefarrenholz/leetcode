class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int16_t size = nums.size();
        if (size <= 1 || k == size || k <= 0) return;
        int32_t heldValue = nums[0], tmp;
        int16_t at = 0, start = 0, count = 0;
        do {  
            at = (at + k) % size;
            tmp = nums[at];
            nums[at] = heldValue;
            heldValue = tmp;
            if (at == start) heldValue = nums[start = ++at];
        } while(++count < size);
    }
};
