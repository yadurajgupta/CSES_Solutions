#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#undef INT_MAX
#define INT_MAX LLONG_MAX
#define endl '\n'
#define int long long
template <class type>
using oset = __gnu_pbds::tree<type, __gnu_pbds::null_type, less<type>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
#define forab(ii, aa, bb) for (int ii = aa; ii < bb; ii++)
#define forabd(ii, aa, bb) for (int ii = aa; ii >= bb; ii--)
#define forabi(ii, aa, bb, inc) for (int ii = aa; ii < bb; ii += inc)
#define all(aa) aa.begin(), aa.end()
#define rall(aa) aa.rbegin(), aa.rend()
#define twodi(type, name, NN, MM, II) vector<vector<type>> name(NN, vector<type>(MM, II));
#define twod(type, name, NN, MM) vector<vector<type>> name(NN, vector<type>(MM));
#define threedi(type, name, NN, MM, LL, II) vector<vector<vector<type>>> name(NN, vector<vector<type>>(MM, vector<type>(LL, II)));
#define threed(type, name, NN, MM, LL) vector<vector<vector<type>>> name(NN, vector<vector<type>>(MM, vector<type>(LL)));
#define PL cout << endl
#define PS(aa) cout << #aa << ' ' << aa << ' ';
#define PSL(aa)               \
    cout << #aa << ' ' << aa; \
    PL;
#define print(vv)          \
    for (auto &ii : vv)    \
        cout << ii << ' '; \
    PL;
#define printn(vv, NN)                      \
    forab(ii, 0, NN) cout << vv[ii] << ' '; \
    PL;
#define invec(type, vv, NN) \
    vector<type> vv(NN);    \
    for (auto &ii : vv)     \
        cin >> ii;

using namespace std;
int N, M, Q, x, y;
array<int, 2510> dist;
array<vector<int>, 2510> adj_dfs;
array<vector<int>, 2510> rev_adj_dfs;
array<bool, 2510> vis;
array<bool, 2510> is_relevant;
array<bool, 2510> curr_vis;
void dfs(int node, int target, const array<vector<int>, 2510> &adj)
{
    vis[node] = true;
    for (int next : adj[node])
    {
        if (vis[next])
            continue;
        dfs(next, target, adj);
    }
}
void set_relevence(int target, const array<vector<int>, 2510> &adj, bool first)
{
    vis.fill(false);
    dfs(target, target, adj);
    forab(i, 1, N + 1)
    {
        is_relevant[i] = vis[i] && (is_relevant[i] || first);
    }
    vis.fill(false);
}
void solve()
{
    cin >> N >> M;
    vector<tuple<int, int, int>> edges;
    vector<tuple<int, int, int>> edges_relevant;
    forab(i, 0, M)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj_dfs[x].push_back(y);
        rev_adj_dfs[y].push_back(x);
        edges.push_back({x, y, w});
    }
    set_relevence(1, adj_dfs, true);
    set_relevence(N, rev_adj_dfs, false);
    for (auto &[x, y, w] : edges)
    {
        if (!is_relevant[x] || !is_relevant[y])
            continue;
        edges_relevant.push_back({x, y, -w});
    }
    int relevent = 0;
    forab(i, 1, N + 1)
    {
        if (is_relevant[i])
            relevent++;
    }
    dist.fill(LLONG_MAX);
    dist[1] = 0;
    bool change;
    forab(i, 0, relevent + 1)
    {
        change = false;
        for (auto &[src, des, wei] : edges_relevant)
        {
            if (dist[src] == LONG_MAX)
                continue;
            change = change || (dist[des] > dist[src] + wei);
            dist[des] = min(dist[des], dist[src] + wei);
        }
        if (!change)
            break;
    }
    cout << (change ? -1 : -dist[N]) << endl;
}
int32_t main()
{
    IOS;
    solve();
    return 0;
}