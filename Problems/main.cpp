#include "../utils/Solution.hpp"

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 3};
    std::cout << sol.findDuplicate(nums) << std::endl;
    return 0;
}