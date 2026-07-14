#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define mod 1000000007

/*  Problem Statement :-
    
*/

/*  Observations :-
    

*/

/* Logic :-

*/

class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> manacher(2 * n + 1);
            for (int i = 0; i < n; i++) {
                manacher[2 * i + 1] = nums[i];
            }

        vector<int> P(2 * n + 1);
        int C = 0;
        int R = 0;
            for (int i = 0; i < manacher.size(); i++) {
                if (i < R) {
                    int mirror = 2 * C - i;
                    P[i] = min(P[mirror], R - i + 1);
                }
                else P[i] = 0;

                // P[i] is the length of the palindron centered at i
                int l = i - P[i];
                int r = i + P[i];
                    while (l >= 0  &&  r < manacher.size()  &&  manacher[l] == manacher[r]) {
                        l--;
                        r++;
                        P[i]++;
                    }

                if (r - 1 > R) {
                    C = i;
                    R = r - 1;
                }
            }

        vector<long long> Psum(2 * n + 1);
            for (int i = 1; i < manacher.size(); i++) {
                Psum[i] = Psum[i - 1] + (long long)manacher[i];
            }

        long long res = 0;
            for (int i = 0; i < manacher.size(); i++) {
                int l = i - P[i];
                int r = i + P[i] - 1;

                long long sum = Psum[r] - ((l == -1) ? 0 : P[l]);
                res = max(res, sum);
            }

        return res;
    }
};