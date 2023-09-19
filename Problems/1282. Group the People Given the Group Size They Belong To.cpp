#include "../utils/Solution.hpp"
vector<vector<int>> Solution::groupThePeople(vector<int>& groupSizes) {
    vector<vector<int>> res;
    vector<vector<int>> groups(groupSizes.size()+1);
    for (int i = 0; i < groupSizes.size(); ++i) {
        groups[groupSizes[i]].push_back(i);
        if (groups[groupSizes[i]].size() == groupSizes[i]) {
            res.push_back(groups[groupSizes[i]]);
            groups[groupSizes[i]].clear();
        }
    }
    return res;
}