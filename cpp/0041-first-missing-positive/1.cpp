class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int s = nums.size();
        int i = 0;
        while(i != s) {
            if (nums[i] <= 0 || nums[i] > s || nums[i] == i+1) {
                ++i;
            } else {
                if (nums[nums[i] - 1] != nums[i]) {
                    swap(nums[i], nums[nums[i]-1]);
                } else {
                    ++i;
                }
            }
        }
        
        for (int i = 0; i < s; i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return s+1;
    }
};
