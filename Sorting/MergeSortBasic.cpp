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

void combine(vector<int> &v, vector<int> &v1, vector<int> &v2) {
    int i, j, k;
    i = j = k = 0;

        while (i != v1.size()  &&  j != v2.size()) {
            if (v1[i] <= v2[j]) v[k++] = v1[i++];
            else    v[k++] = v2[j++];
        }

        while (i != v1.size()) v[k++] = v1[i++];
        while (j != v2.size()) v[k++] = v2[j++];
}

void mergeSort(vector<int> &v) {
    if (v.size() <= 1)  return;

    vector<int> v1, v2;
    int n = v.size();
        for (int i = 0; i < n; i++) {
            if (i < (n / 2))   v1.push_back(v[i]);
            else    v2.push_back(v[i]);
        }

    mergeSort(v1);
    mergeSort(v2);

    combine(v, v1, v2);

    return;
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums;
    }
};