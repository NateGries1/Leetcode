#include "../utils/Solution.hpp"

int Solution::removeElement(std::vector<int>& nums, int val) {
    int i = 0;
    int j = 0;
    //j stays at the spot to move to, i checks every element
    //element at i is moved to j if it's not val

    while(i < nums.size()) {
        if (nums[i] != val) {
            nums[j] = nums[i];
            ++j;
        }
        ++i;
    }
    //j is the index equal to the number of items moved(size)
    return j;
}