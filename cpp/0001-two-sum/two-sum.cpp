#include <map>
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mem;
        std::vector<int> res;
        
        auto size = nums.size();
        for (auto i = 0; i < size; ++i) {
            auto x = target - nums[i];
            if (mem.find(x) != mem.end()) {
                res.push_back(i);
                res.push_back(mem[x]);
                return res;
            } else {
                mem[nums[i]] = i;
            }
        }
        return res;
    }
};
