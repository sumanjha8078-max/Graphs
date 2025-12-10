#define ll long long

#include <bits/stdc++.h>
using namespace std;

void fast_io(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(vector<vector<ll>>& adj, vector<ll>& vis, vector<vector<ll>>& ans, vector<ll>& use, int node){
    vis[node] = 1;
    use.push_back(node);
    ll c = 0;
    for(int i = 0 ; i < adj[node].size() ; i++){
        if(!vis[adj[node][i]]){
            dfs(adj, vis, ans, use, adj[node][i]);
            c++;
        }
    }
    if(c == 0) ans.push_back(use);
    use.pop_back();
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
    vector<vector<ll>> ans;
    vector<ll> use;
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            dfs(adj, vis, ans, use, i);
        }
    }
    for(vector<ll> t : ans){
        for(ll o : t) cout << o << " ";
        cout << "\n";
    }
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