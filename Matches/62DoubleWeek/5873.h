/*
滑动窗口:
    找到连续相同的最大值,连续肯定会在一个区域内,用两个变量代表窗口大小,遍历数组,
    期间不断调整区域大小,过程中的最大值就是答案
*/

#pragma once
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int l = 0, res = 0;     //l和循环中的i代表了窗口大小
        int f = 0, t = 0;       //TF的数量,用于对比k,两者的最小值>k,说明需要缩减窗口大小,以保证可以使区域内全部连续
        for (int i = 0; i < n; i++) {
            if (answerKey[i] == 'T') t++;
            else f++;
            while (min(t, f) > k) {
                if (answerKey[l] == 'T') t--;
                else f--;
                l++;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};
