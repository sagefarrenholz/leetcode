class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> seen; int count = 0;
        for (int& i :  nums) {
            count += seen[i]++;
        }
        return count;
    }
};
