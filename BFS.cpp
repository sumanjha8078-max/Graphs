#define ll long long

#include <bits/stdc++.h>
using namespace std;

void fast_io(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
}

void bfs(vector<vector<ll>>& adj, vector<ll>& vis, vector<ll>& ans, int node){
    vis[node] = 1;
    queue<ll> q;
    q.push(node);
    while(!q.empty()){
        ll use = q.front();
        q.pop();
        for(int i = 0 ; i < adj[use].size() ; i++){
            if(!vis[adj[use][i]]){
                q.push(adj[use][i]);
                vis[adj[use][i]] = 1;
            }
        }
        ans.push_back(use);
    }
}

void solve(){
    ll n; cin >> n;
    vector<ll> vis(n+1,0);
    vector<vector<ll>> adj(n+1);
    for(int i = 1 ; i < n ; i++){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> ans;
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            bfs(adj, vis, ans, i);
        }
    }
    for(ll t : ans) cout << t << " ";
    cout << "\n";
}

int main(){
    fast_io();
    ll Test_Cases = 1; cin >> Test_Cases;
    while(Test_Cases--){
        solve();
    }
    return 0;
}