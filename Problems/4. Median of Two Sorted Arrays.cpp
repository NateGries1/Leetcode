#include "../utils/Solution.hpp"

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int idx1 = 0;
    int idx2 = 0;
    vector<int> merged;
    while(idx1 < nums1.size() && idx2 < nums2.size()) {
        if (nums1[idx1] < nums2[idx2]) {
            merged.push_back(nums1[idx1]);
            ++idx1;
        } else {
            merged.push_back(nums2[idx2]);
            ++idx2;
        }
    }

    while(idx1 < nums1.size()) {
        merged.push_back(nums1[idx1]);
        ++idx1;
    }

    while(idx2 < nums2.size()) {
        merged.push_back(nums2[idx2]);
        ++idx2;
    }
    
    int size = merged.size();
    if (size % 2 == 1) {
        return double(merged[size/2]);
    } else {
        return double(merged[size/2-1]) + (double(merged[size/2] - merged[size/2-1])/2);
    }
}