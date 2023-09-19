#include "../utils/Solution.hpp"
int Solution::findDuplicate(vector<int>& nums) {
    int s = nums[0];
    int f = nums[nums[0]];
    while(s != f) {
        s = nums[s];
        f = nums[nums[f]];
    }
    f = 0;
    while(s != f) {
        s = nums[s];
        f = nums[f];
    }
    return s;
}