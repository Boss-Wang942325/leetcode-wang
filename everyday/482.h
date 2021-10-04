#pragma once
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        int cnt = 0;
        for (int i = s.size()-1; i >= 0; i++) {
            if (s[i] == '-') continue;
            ans.push_back(toupper(s[i]));
            cnt++;
            if (cnt % k == 0) ans.push_back('-');
        }
        if (cnt > 0 && ans.back() == '-') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};