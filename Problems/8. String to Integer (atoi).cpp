
#include "../utils/Solution.hpp"
int Solution::myAtoi(string s) {
    bool negative = false;
    long res = 0;
    int i = 0;
    while(s[i] == ' ') {
        ++i;
    }
    if (s[i] == '-') {
        negative = true;
        ++i;
    } else if (s[i] == '+') {
        ++i;
    }
    if (negative) {
        while(s[i] >= '0' and s[i] <= '9') {
            res *= 10;
            res -= s[i]-'0';
            if (res < -pow(2, 31)) {
                return -(pow(2, 31));
            }
            ++i;
        }
    } else {
        while(s[i] >= '0' and s[i] <= '9') {
            res *= 10;
            res += s[i]-'0';
            if (res >= pow(2, 31)-1) {
                return pow(2, 31)-1;
            }
            ++i;
        }
    }
    return res;
}