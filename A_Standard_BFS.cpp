#define ll long long
#define mod (1000000007)

#include <bits/stdc++.h>
using namespace std;

void fast_io(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
}

void bfs(vector<vector<ll>>& adj, vector<ll>& ans, vector<ll>& vis, ll node){
    multiset<ll> q;
    q.insert(node);
    while(!q.empty()){
        ll use = *q.begin();
        ans.push_back(use);
        q.erase(*q.begin());
        for(int i = 0 ; i < adj[use].size() ; i++){
            if(!vis[adj[use][i]]){
                vis[adj[use][i]] = 1;
                q.insert(adj[use][i]);
            }
        }
    }
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    while(m--){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> ans;
    vector<ll> vis(n+1,0);
    for(int i = 1; i <= n ; i++){
        if(!vis[i]){
            vis[i] = 1;
            bfs(adj, ans, vis, i);
        }
    }
    for(ll t : ans) cout << t << " ";
    cout << "\n";
}

int main(){
    fast_io();
    ll Test_Cases = 1; // cin >> Test_Cases;
    while(Test_Cases--){
        solve();
    }
    return 0;
}