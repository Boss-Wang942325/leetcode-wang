#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int len = nums.size(), ans = 0;
        vector<long long> s(len + 1);
        for (int i = 0; i < len; i++) { //求前缀和
            s[i + 1] = s[i] + nums[i];
        }
        if (s[len] % 2 == 0) {          //不改变元素的情况
            for (int i = 1;i < len; i++) {
                if (s[i] * 2 == s[len]) ans++;  //出现 前缀和==总和一半 的情况
            }
        }
        int res = ans;
        
        for (int i = 0; i < len; i++) {
            s[i+1] += k-nums[i];
            for (int i = 1; i < len; i++) {
                if (s[i] * 2 == s[len]) ans++;
            }
        }
        
        return max(res, ans);
    }
};

// s[0] 
// s[1] 0-i-1





// class Solution {
// public:
//     vector<int> s(vector<int> nums, int a, int b) {
//         vector<int> x;
//         int s = 0;
//         while (a <= b) {
//             s += nums[a++];
//             x.push_back(s);
            
//         }
//         return x;
//     }
    
//     int waysToPartition(vector<int>& nums, int k) {
//         int len = nums.size();
//         vector<int> sum1 = s(nums, 0, len - 1);
//         vector<int> sum2 = sum1;
//         int num1= 0, num2 = 0, p = 0, max = 0;
//         for (int i = 1;i < len; i++) {
//             if (sum1[i-1] == sum1[len - 1] - sum1[i-1]) num1++;
            
//         }
//         max = num1;
//         for (int j = p; j < len; p++) {
//                 sum2 = sum1;
//                 sum2[j] += k-nums[j];
//                 for (int i = 1;i < len; i++) {
//                     if (sum2[i-1] == sum2[len - 1] - sum2[i-1]) num2++;
//                 }
//                 if (max < num2) max = num2;
//             }
//         // if (max < num1) max = num1;
//         // int max = num1;
//         // for (int p = 0; p < len; p++) {
//         //     vector<int> a = nums;
//         //     a[p] = k;
//         //     sum = s(a, 0, len - 1);
            
//         //     num2 = 0;
//         //     for (int i = 1;i < len; i++) {
//         //         if (sum[i-1] == sum[len - 1] - sum[i-1]) num2++;
//         //     }
//         //     if (max < num2) max = num2;
//         // }
//         return max;
//     }
// };