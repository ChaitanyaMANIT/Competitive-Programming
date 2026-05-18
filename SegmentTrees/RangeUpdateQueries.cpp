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
 
struct node{
    ll sum;
    node(){
        sum = 0;
    }
};
 
node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}
 
node st[4*200005];
 
void build(ll id, ll l, ll r) {
    if (l == r) {
        st[id].sum = 0;
        return;
    }
 
    ll mid = (l + r) / 2;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);
    st[id] = merge(st[2*id], st[2*id + 1]);
}
 
void update(ll id, ll l, ll r, ll pos, ll val) {
    if (pos < l  ||  pos > r) return;
    if (l == r) {
        st[id].sum += val;
        return;
    }
 
    ll mid = (l + r) / 2;
    update(2*id, l, mid, pos, val);
    update(2*id + 1, mid + 1, r, pos, val);
    st[id] = merge(st[2*id], st[2*id + 1]);
}
 
node query(ll id, ll l, ll r, ll lq, ll rq) {
    if (lq > r  ||  rq < l) return node();
    if (lq <= l  &&  rq >= r) return st[id];
 
    ll mid = (l + r) / 2;
    node left = query(2*id, l, mid, lq, rq);
    node right = query(2*id + 1, mid + 1, r, lq, rq);
    return merge(left, right);  
}
 
void solve() {
    ll n, q;
        cin >> n >> q;
 
    vector<ll> v(n);
        for(ll i = 0; i < n; i++) {
            cin >> v[i];
        }
 
    build(1, 0, n - 1);
        while (q--) {
            ll type;
                cin >> type;
 
            if (type == 1) {
                ll lq, rq, val;
                    cin >> lq >> rq >> val;
                lq--; rq--;
                update(1, 0, n - 1, lq, val);
                if (rq != n - 1)    update(1, 0, n - 1, rq + 1, -val);
            }
            else {
                ll pos;
                    cin >> pos;
                pos--;
 
                node ans = query(1, 0, n - 1, 0, pos);
                cout << ans.sum + v[pos] << "\n";
            }
        }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    // ll T;
    // cin >> T;
 
    // while (T--) {
        solve();
    // }
 
    return 0;
}
