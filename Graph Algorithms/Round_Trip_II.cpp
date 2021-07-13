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
int N, M, x, y, w;
const int NMAX = 1e5 + !0;
array<vector<int>, NMAX> adj;
array<bool, NMAX> vis;
array<bool, NMAX> curr_vis;
bool find_cycle(int node, map<int, int> &mp, vector<int> &path)
{
    vis[node] = true;
    curr_vis[node] = true;
    mp[node] = path.size();
    path.push_back(node);
    bool has_cycle = false;
    for (int next : adj[node])
    {
        if (next == node)
            continue;
        else if (curr_vis[next])
        {
            cout << path.size() - mp[next] + 1 << endl;
            forab(i, mp[next], path.size())
            {
                cout << path[i] << " ";
            }
            cout << next << endl;
            has_cycle = true;
        }
        else if (vis[next])
            continue;
        else
            has_cycle = has_cycle || find_cycle(next, mp, path);
        if (has_cycle)
            break;
    }
    curr_vis[node] = false;
    path.pop_back();
    mp.erase(node);
    return has_cycle;
}
void solve()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        if (x == y)
            continue;
        adj[x].push_back(y);
    }
    vis.fill(false);
    vector<int> path;
    map<int, int> mp;
    forab(i, 1, N + 1)
    {
        if (!vis[i] && find_cycle(i, mp, path))
            return;
    }
    cout << "IMPOSSIBLE" << endl;
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