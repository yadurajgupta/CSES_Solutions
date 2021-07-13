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
int N;
const int NMAX = 2 * (1e5) + 10;
array<int, NMAX> dp;
array<int, NMAX> adj;
array<bool, NMAX> vis;
array<int, NMAX> cycle_size;
void find_cycles(int node, map<int, int> &mp, vector<int> &path)
{
    mp[node] = path.size();
    path.push_back(node);
    vis[node] = true;
    int next = adj[node];
    if (mp.count(next))
    {
        int sz = path.size() - mp[next];
        forab(i, mp[next], path.size())
            dp[path[i]] = cycle_size[path[i]] = sz;
    }
    else if (!vis[next])
        find_cycles(next, mp, path);
    path.pop_back();
    mp.erase(node);
}
int find_rest(int node)
{
    if (dp[node] == -1)
        dp[node] = 1 + find_rest(adj[node]);
    return dp[node];
}
void solve()
{
    cin >> N;
    dp.fill(-1);
    cycle_size.fill(-1);
    forab(i, 1, N + 1)
    {
        cin >> adj[i];
        if (i == adj[i])
            dp[i] = 1;
    }
    map<int, int> mp;
    vector<int> path;

    forab(i, 1, N + 1)
    {
        if (!vis[i] && dp[i] == -1)
            find_cycles(i, mp, path);
    }
    forab(i, 1, N + 1)
    {
        if (dp[i] == -1)
            find_rest(i);
    }
    forab(i, 1, N + 1)
    {
        cout << dp[i] << " ";
    }
}
int32_t main()
{
    IOS;
    // freopen("C:\\Users\\yadur\\Desktop\\CC\\Competitive\\CSES\\Sorting and Searching\\IN.txt", "r", stdin);
    // int T;
    // cin >> T;
    // while (T--)
    solve();
    return 0;
}