// It is never about winning, it is just about finishing.

/*
    Claims : 

*/

#define ll long long
#define mod (1000000007)
 
#include <bits/stdc++.h>
using namespace std;

class UnionFind{
    public:
    vector<ll> p, rank, setSize;
    ll numSets;

    UnionFind(ll n){
        p.assign(n+1,0);
        for(int i = 1 ; i <= n ; i++){
            p[i] = i;
        }
        rank.assign(n+1,0);
        setSize.assign(n+1,1);
        numSets = n;
    }

    ll findSet(ll i){
        if(p[i] == i) return i;
        else return p[i] = findSet(p[i]);
    }

    bool sameSet(ll i, ll j){
        return findSet(i) == findSet(j);
    }

    void UnionSet(ll i, ll j){
        if(sameSet(i,j)) return;
        ll x = findSet(i);
        ll y = findSet(j);
        if(rank[x] > rank[y]) swap(x,y);
        p[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
        setSize[y] += setSize[x];
        numSets--;
    }

};

void fast_io(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(){
    ll n, q; cin >> n >> q;
    UnionFind u(n);
    while(q--){
        string str; cin >> str;
        if(str[0] == 'g'){
            ll a, b; cin >> a >> b;
            if(u.sameSet(a,b)) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
        else{
            ll a, b; cin >> a >> b;
            u.UnionSet(a,b);
        }
    }
}
 
int main(){
    fast_io();
    ll Test_Cases = 1; // cin >> Test_Cases;
    while(Test_Cases--){
        solve();
    }
    return 0;
}

// Author : Krishna Chandra Jha
// Country : INDIA

