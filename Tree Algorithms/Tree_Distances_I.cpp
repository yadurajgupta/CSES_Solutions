#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
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
const int NMAX = 2 * (1e5) + 10;
array<vector<int>, NMAX> adj;
array<set<pair<int, int>>, NMAX> depth;
array<int, NMAX> farthest;
array<int, NMAX> parent;
set<pair<int, int>> max_depth(int node, int par)
{
    parent[node] = par;
    set<pair<int, int>> max_depths2;
    for (int next : adj[node])
    {
        if (next == par)
            continue;
        auto child_depths = max_depth(next, node);
        auto [max_depth_child, max_depth_child_node] = *child_depths.rbegin();
        max_depths2.insert({max_depth_child + 1, next});
        while (max_depths2.size() > 2)
            max_depths2.erase(max_depths2.begin());
    }
    if (max_depths2.empty())
        max_depths2.insert({0, -1});
    return depth[node] = max_depths2;
}
void recur(int node, int par, int max_depth_above)
{
    // debug(node, par, max_depth_above);
    int max_dist = (*depth[node].rbegin()).first;
    farthest[node] = max(max_dist, max_depth_above);
    for (int next : adj[node])
    {
        if (next == par)
            continue;
        int curr_max_depth = max_depth_above + 1;
        for (auto [dep, nod] : depth[node])
        {
            if (nod == next)
                continue;
            curr_max_depth = max(curr_max_depth, 1 + dep);
        }
        recur(next, node, curr_max_depth);
    }
}
void solve()
{
    cin >> N;
    M = N - 1;
    forab(i, 0, M)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    max_depth(1, -1);
    recur(1, -1, 0);
    forab(i, 1, N + 1)
    {
        cout << farthest[i] << " ";
    }
    PL;
}
int32_t main()
{
    IOS;
    solve();
    return 0;
}