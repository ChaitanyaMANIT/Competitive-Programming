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

void mergeSort(vector<int> &v, vector<int> &temp, int lo, int hi) {
    if (lo >= hi)   return;

    int mid = lo + (hi - lo) / 2;

    mergeSort(v, temp, lo, mid);
    mergeSort(v, temp, mid + 1, hi);

    int i = lo;
    int j = mid + 1;
    int k = lo;
        while (i != mid + 1  &&  j != hi + 1) {
            if (v[i] <= v[j]) temp[k++] = v[i++];
            else    temp[k++] = v[j++];
        }

        while (i != mid + 1)    temp[k++] = v[i++];
        while (j != hi + 1)     temp[k++] = v[j++];

        for (int i = lo; i <= hi; i++)  v[i] = temp[i];
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp = nums;
        mergeSort(nums, temp, 0, nums.size() - 1);
        return nums;
    }
};