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
int N, Q, x, y;
const int NMAX = 2 * (1e5) + 10;
const int LGMAX = 30;
array<vector<int>, NMAX> adj;
array<int, NMAX> depth;
array<array<int, LGMAX>, NMAX> dp;
void pre_calc_depth(int node, int par, int dep)
{
    depth[node] = dep;
    dp[node][0] = par;
    // debug(node, par);
    for (int next : adj[node])
    {
        if (next == par)
            continue;
        pre_calc_depth(next, node, dep + 1);
    }
}
int jump(int node, int times)
{
    int index = 0;
    // int node_bu = node;
    // int times_bu = times;
    while (times)
    {
        if (times % 2)
            node = dp[node][index];
        index++;
        times /= 2;
    }
    // debug("temp", node_bu, times_bu, node);
    return node;
}
int binser(int n1, int n2)
{
    if (n1 == 1 || n2 == 1)
        return 1;
    else if (n1 == n2)
        return n1;
    forabd(j, LGMAX - 1, 0)
    {
        if (dp[n1][j] != dp[n2][j])
        {
            n1 = dp[n1][j];
            n2 = dp[n2][j];
        }
    }
    return dp[n1][0];
}
void solve()
{
    cin >> N >> Q;
    for (auto &row : dp)
    {
        row.fill(0);
    }
    forab(i, 0, N - 1)
    {
        cin >> x >> y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    pre_calc_depth(1, 1, 0);
    // forab(i, 1, N + 1)
    // {
    //     cout << i << " : ";
    //     for (int j : adj[i])
    //     {
    //         cout << j << " ";
    //     }
    //     PL;
    // }
    forab(j, 1, LGMAX)
    {
        forab(i, 1, N + 1)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
    // forab(j, 0, LGMAX)
    // {
    //     forab(i, 1, N + 1)
    //     {

    //         cout << dp[i][j] << " ";
    //     }
    //     PL;
    // }
    // printn(depth, N + 1);
    forab(i, 0, Q)
    {
        cin >> x >> y;
        if (depth[x] > depth[y])
            swap(x, y);
        int n_y = jump(y, depth[y] - depth[x]);
        int lca = binser(x, jump(y, depth[y] - depth[x]));
        // debug(x, y, n_y, lca);
        cout << depth[x] + depth[y] - 2 * depth[lca] << endl;
    }
}
int32_t main()
{
    IOS;
    // int T;
    // cin >> T;
    // while (T--)
    // freopen("C:\\Users\\yadur\\Desktop\\CC\\IN.txt", "w", stdin);
    solve();
    return 0;
}