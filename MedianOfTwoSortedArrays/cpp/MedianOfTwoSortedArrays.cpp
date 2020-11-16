class Solution {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            if (nums1.empty()) {
                return (nums2[nums2.size() / 2.0] + nums2[nums2.size() / 2.0 - 0.5]) / 2.0;
            } else {
                return (nums1[nums1.size() / 2.0] + nums1[nums1.size() / 2.0 - 0.5]) / 2.0;
            }
        } else {
            int leftLen = (nums1.size() + nums2.size() + 1) / 2;
            int oneMax, oneMin;
            int one, two;
            if (nums1.size() > nums2.size()) {
                oneMax = leftLen;
                oneMin = leftLen - nums2.size();
            } else {
                oneMax = nums1.size();
                oneMin = 0;
            }
            while (oneMin <= oneMax) {
                one = (oneMin + oneMax) / 2;
                two = leftLen - one;
                
                if (two < nums2.size() && one - 1 >= 0 && nums1[one - 1] > nums2[two]) {
                    oneMax = one - 1;
                } else if (one < nums1.size() && two - 1 >= 0 && nums2[two - 1] > nums1[one]) {
                    oneMin = one + 1;
                } else {
                    if (two == 0 || (one - 1 >= 0 && nums1[one - 1] > nums2[two - 1])) {
                        oneMin = oneMax = nums1[one - 1];
                    } else {
                        oneMin = oneMax = nums2[two - 1];                      
                    }
                    if ((nums1.size() + nums2.size()) % 2 == 0) {
                        if (one < nums1.size() && two < nums2.size() && nums1[one] < nums2[two]) {
                            oneMax = nums1[one];
                        } else if (two < nums2.size()) {
                            oneMax = nums2[two];
                        } else {
                            oneMax = nums1[one];
                        }
                    } 
                    return (oneMin + oneMax) / 2.0;
                }
            }
            return -1;
        }
    }
};
