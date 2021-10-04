// #include <iostream>
// #include <vector>

// using namespace std;
// int sum(vector<int> a) {
//         int s = 0;
//         for (int i = 0; i < a.size(); i++) {
//             s += a[i];
//         }
//         return s;
//     }

// bool x() {
//     vector<int> stones(2);
//     stones[0] = 2;
//     stones[1] = 1;
//     int len = stones.size();
//         vector<int> a(len, 0);
//         for (int i = 0; i < len; i++) {
//             for (int j = 0;j < len; j++) {
//                 if (stones[j] == 0) continue;
//                 a[i] = stones[j];
//                 if (sum(a) % 3 != 0) {
//                     stones[j] = 0;
//                     break;
//                 }
//             }
//             if (i % 2 == 1 && sum(a) % 3 == 0) return true;
//         }
//         return false;
// }

// int main() {
//     cout << x();

//     cin.get();
// }



// class Solution {
// public:
//     int sum(vector<int> a) {
//         int s = 0;
//         for (int i = 0; i < a.size(); i++) {
//             s += a[i];
//         }
//         return s;
//     }
    
//     bool stoneGameIX(vector<int>& stones) {
//         int len = stones.size();
//         vector<int> a(len, 0);
//         for (int i = 0; i < len; i++) {
//             for (int j = 0;j < len; j++) {
//                 if (stones[j] == 0) continue;
//                 a[i] = stones[j];
//                 if (sum(a) % 3 != 0) {
//                     stones[j] = 0;
//                     break;
//                 }
//             }
//             if (i % 2 == 0 && sum(a) % 3 == 0) return false;
//             if (i % 2 == 1 && sum(a) % 3 == 0) return true;
//         }
//         return false;
//     }
// };
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s = "5F3Z-2e-9-w";
    int x = s.size();
    s.erase(0);
    cout << x;
    for (int i = 0; i < x; i++) {
        if (s[i] <= 'z' && s[i] >= 'a') s[i] += 'Z'-'z';
        if (s[i] == '-') {
            s.erase(i--);
            x--;
        }
        cout << s[i];
    }

    cin.get();
    return 1;
}