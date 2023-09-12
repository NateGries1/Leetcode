#include "../utils/Solution.hpp"
int Solution::minDeletions(string s) {
    int deletions = 0;
    vector<int> count(26);
    unordered_set<int> set;
    for (int i = 0; i < s.size(); ++i) {
        ++count[s[i]-'a'];
    }
    for (int i = 0; i < 26; ++i) {
        while( set.count(count[i]) ) {
            --count[i];
            ++deletions;
        }
        if (count[i]) {
            set.insert(count[i]);
        }
    }
    return deletions;
}