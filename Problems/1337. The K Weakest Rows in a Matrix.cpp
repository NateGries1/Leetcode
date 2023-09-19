#include "../utils/Solution.hpp"
vector<int> Solution::kWeakestRows(vector<vector<int>>& mat, int k) {
    for (int i = 0; i < mat.size(); ++i) {
        mat[i].push_back(i);
    }
    std::sort(mat.begin(), mat.end());
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        res.push_back(mat[i].back());
    }
    return res;
}