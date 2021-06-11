#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl '\n'
#define int long long
#define ordered_set(type) __gnu_pbds::tree<type, __gnu_pbds::null_type, less<type>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>
#define forab(ii, aa, bb) for (int ii = aa; ii < bb; ii++)
#define forabd(ii, aa, bb) for (int ii = aa; ii >= bb; ii--)
#define forabi(ii, aa, bb, inc) for (int ii = aa; ii < bb; ii += inc)
#define forabdi(ii, aa, bb, inc) for (int ii = aa; ii >= bb; ii -= inc)
#define all(aa) aa.begin(), aa.end()
#define rall(aa) aa.rbegin(), aa.rend()
#define twodi(type, name, NN, MM, II) vector<vector<type>> name(NN, vector<type>(MM, II))
#define twod(type, name, NN, MM) vector<vector<type>> name(NN, vector<type>(MM))
#define threedi(type, name, NN, MM, LL, II) vector<vector<vector<type>>> name(NN, vector<vector<type>>(MM, vector<type>(LL, II)))
#define threed(type, name, NN, MM, LL) vector<vector<vector<type>>> name(NN, vector<vector<type>>(MM, vector<type>(LL)))
#define PL cout << endl
#define PS(aa) cout << #aa << ' ' << aa << ' '
#define PSL(aa)               \
    cout << #aa << ' ' << aa; \
    PL;
#define print(vv)          \
    for (auto &ii : vv)    \
        cout << ii << ' '; \
    PL;
#define print2d(vv)            \
    for (auto &row : vv)       \
    {                          \
        for (auto &ii : row)   \
            cout << ii << ' '; \
        cout << endl;          \
    }
#define printp(vv) cout << "{" << vv.firt << "," << vv.second << "} "
#define printn(vv, NN)                      \
    forab(ii, 0, NN) cout << vv[ii] << ' '; \
    PL;
#define invec(type, vv, NN) \
    vector<type> vv(NN);    \
    for (auto &ii : vv)     \
        cin >> ii;
void debug()
{
    PL;
}
template <typename T, typename... Types>
void debug(T var1, Types... var2)
{
    cout << var1 << " ";
    debug(var2...);
}
/* TEMPLATE END */
int N, M, x, y;
const int NMAX = 1e5 + 20;
array<vector<int>, NMAX> adj;
array<vector<int>, NMAX> rev_adj;
array<int, NMAX> coins;
array<int, NMAX> max_coins;
array<bool, NMAX> curr_vis;
array<int, NMAX> scc_id;
array<bool, NMAX> vis;

void dfs(int node, vector<int> &topo, array<vector<int>, NMAX> &adj)
{
    curr_vis[node] = true;
    vis[node] = true;
    for (int next : adj[node])
    {
        if (vis[next] || curr_vis[next])
            continue;
        dfs(next, topo, adj);
    }
    topo.push_back(node);
    curr_vis[node] = false;
}
int find_max_coins(int node, vector<vector<int>> &adj, vector<int> &cumu_coin)
{
    if (max_coins[node] == -1)
    {
        int curr_coin = cumu_coin[node];
        for (int &next : adj[node])
        {
            curr_coin = max(curr_coin, cumu_coin[node] + find_max_coins(next, adj, cumu_coin));
        }
        max_coins[node] = curr_coin;
    }
    return max_coins[node];
}
void solve()
{
    cin >> N >> M;
    forab(i, 1, N + 1)
    {
        cin >> coins[i];
    }
    forab(i, 0, M)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        rev_adj[y].push_back(x);
    }
    vector<int> topo;
    forab(i, 1, N + 1)
    {
        if (!vis[i])
            dfs(i, topo, adj);
    }
    reverse(all(topo));
    max_coins.fill(-1);
    vector<int> scc;
    int id = 0;
    vector<int> cumu_coins;
    vis.fill(false);
    for (int i : topo)
    {
        if (!vis[i])
        {
            dfs(i, scc, rev_adj);
            int cumu_coin = 0;
            for (int j : scc)
            {
                scc_id[j] = id;
                cumu_coin += coins[j];
            }
            cumu_coins.push_back(cumu_coin);
            scc.clear();
            id++;
        }
    }
    vector<vector<int>> adj_scc(id);
    forab(src, 1, N + 1)
    {
        for (int des : adj[src])
        {
            if (scc_id[src] != scc_id[des])
            {
                adj_scc[scc_id[src]].push_back(scc_id[des]);
            }
        }
    }
    int mx = 0;
    forab(i, 0, id)
    {
        mx = max(mx, find_max_coins(i, adj_scc, cumu_coins));
    }
    cout << mx << endl;
}
int32_t main()
{
    IOS;
    // int T;
    // cin >> T;
    // while (T--)
    solve();
    return 0;
}