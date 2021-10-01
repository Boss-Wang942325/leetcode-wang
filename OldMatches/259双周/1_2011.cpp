/*
题目大意:
    给一字符串, 有若干个字符, 识别其中的+-操作

方法1: 遍历识别

*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (int i = 0; i < operations.size(); i++) {
            string word = operations[i];
            if (word[1] == '+') X++;
            else X--;
        }
        return X;
    }
};

class Solution {
public:
    int finalValueAfterOperations(vector<string>& ops) {
        int ans = 0;
        for (string i : ops) {
            if (i[1] == '-')    --ans;
            else                ++ans;
        }
        return ans;
    }
};