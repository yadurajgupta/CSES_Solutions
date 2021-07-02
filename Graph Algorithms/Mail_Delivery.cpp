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
const int NMAX = 1e5 + 10;
array<set<int>, NMAX> adj;
array<int, NMAX> degree;
set<pair<int, int>> edges;
void solve()
{
    cin >> N >> M;
    degree.fill(0);
    forab(i, 0, M)
    {
        cin >> x >> y;
        if (edges.count({min(x, y), max(x, y)}))
            continue;
        edges.insert({min(x, y), max(x, y)});
        adj[x].insert(y);
        adj[y].insert(x);
        degree[y]++;
        degree[x]++;
    }
    forab(i, 1, N + 1)
    {
        if (degree[i] % 2)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    int curr = 1;
    stack<int> stk;
    stk.push(curr);
    vector<int> path;
    while (!stk.empty() || !adj[curr].empty())
    {
        if (adj[curr].empty())
        {
            path.push_back(curr);
            curr = stk.top();
            stk.pop();
            continue;
        }
        for (int next : adj[curr])
        {
            stk.push(curr);
            adj[curr].erase(next);
            adj[next].erase(curr);
            // cout << curr << " " << next << endl;
            edges.erase({min(curr, next), max(curr, next)});
            curr = next;
            break;
        }
    }
    // vector<int> path;
    // eularian_circuit(1, path);
    if (edges.empty())
    {
        print(path);
    }
    else
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
