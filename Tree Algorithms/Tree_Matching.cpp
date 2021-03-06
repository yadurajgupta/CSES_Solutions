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
template <class type>
using oset = __gnu_pbds::tree<type, __gnu_pbds::null_type, less<type>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
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
const int NMAX = 2 * (1e5) + 1;
array<array<int, NMAX>, 2> dp;
array<vector<int>, NMAX> adj;
int recur(int node, int par, bool can_include_root)
{
    // debug(node, par, can_include_root);
    if (dp[can_include_root][node] == -1)
    {
        int tot = 0;
        for (int next : adj[node])
        {
            if (next == par)
                continue;
            tot += recur(next, node, true);
            // recur(next, false);
        }
        if (!can_include_root)
            dp[can_include_root][node] = tot;
        else
        {
            int ans = tot;
            for (int next : adj[node])
            {
                if (next == par)
                    continue;
                ans = max(ans, 1 + tot - recur(next, node, true) + recur(next, node, false));
            }
            dp[can_include_root][node] = ans;
        }
    }
    return dp[can_include_root][node];
}
void solve()
{
    cin >> N;
    forab(i, 0, N - 1)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dp[0].fill(-1);
    dp[1].fill(-1);
    cout << recur(1, -1, true) << endl;
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