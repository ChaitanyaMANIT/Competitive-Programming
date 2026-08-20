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
    using ll = long long;

    void mergeSort(vector<int> &v, vector<int> &temp, int lo, int hi, ll &inv) {
        if (lo >= hi)   return;

        int mid = lo + (hi - lo) / 2;

        mergeSort(v, temp, lo, mid, inv);
        mergeSort(v, temp, mid + 1, hi, inv);

        int i = lo;
        int j = mid + 1;
        int k = lo;
            while (i != mid + 1  &&  j != hi + 1) {
                if (v[i] <= v[j]) inv += (j - (mid + 1)), temp[k++] = v[i++];
                else    temp[k++] = v[j++];
            }

            while (i != mid + 1)    inv += (j - (mid + 1)), temp[k++] = v[i++];
            while (j != hi + 1)     temp[k++] = v[j++];

            for (int i = lo; i <= hi; i++)  v[i] = temp[i];
    }

    int inversionCount(vector<int> &arr) {
        vector<int> temp = arr;
        ll inv = 0;
        mergeSort(arr, temp, 0, arr.size() - 1, inv);
        return (int)inv;
    }
};