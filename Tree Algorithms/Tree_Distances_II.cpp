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
const int NMAX = 2 * (1e5) + 10;
array<vector<int>, NMAX> adj;
array<int, NMAX> subtree;
array<int, NMAX> sum_of_dist;
int total_dist_from_nodes = 0;
int element_in_subtree(int node, int par, int dep)
{
    int children = 0;
    for (int next : adj[node])
    {
        if (next == par)
            continue;
        children += element_in_subtree(next, node, dep + 1);
    }
    total_dist_from_nodes += dep;
    return subtree[node] = children + 1;
}
void calc_sum_of_dist(int node, int par, int sum)
{
    sum_of_dist[node] = sum;
    for (int next : adj[node])
    {
        if (next == par)
            continue;
        calc_sum_of_dist(next, node, sum + (N - 2 * (subtree[next])));
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
    element_in_subtree(1, -1, 0);
    calc_sum_of_dist(1, -1, total_dist_from_nodes);
    // printn(subtree, N + 1);
    // p    rintn(sum_of_dist, N + 1);
    forab(i, 1, N + 1)
    {
        cout << sum_of_dist[i] << " ";
    }
    // cout << total_dist_from_nodes << endl;
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