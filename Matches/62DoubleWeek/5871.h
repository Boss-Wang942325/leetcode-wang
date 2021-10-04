// 将一维整数数组转化为m行n列二维数组
// 不能有空缺位置,否则返回空数组
#include <vector>
using namespace std;

#pragma once

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m*n) return {};      //返回空数组
        vector<vector<int>> a(m, vector<int>(n));   //m行n列数组
        for (int i = 0, p = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = original[p++];            //先用p再p++
            }
        }

        /*
        for (int i = 0; i < original.size(); i++) {
            a[i / n][i % n] = original[i];          //  i/n是取行数, i%n是取列数
        }
        */
        return a;
    }
};