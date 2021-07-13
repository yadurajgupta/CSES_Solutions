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
int N, M;
int x, y, w;
const int NMAX = 2510;
array<bool, NMAX> vis;
array<int, NMAX> dist;
array<int, NMAX> parent;
void print_cycle(int node)
{
    cout << "YES" << endl;
    vector<int> cycle;
    map<int, int> nodes;
    int end = -1;
    while (node != -1)
    {
        cycle.push_back(node);
        if (nodes.count(node))
        {
            end = node;
            break;
        }
        nodes[node] = cycle.size() - 1;
        node = parent[node];
    }
    forabd(i, cycle.size() - 1, nodes[end])
    {
        cout << cycle[i] << " ";
    }
    PL;
}
bool belamnFord(int node, vector<tuple<int, int, int>> &edges)
{
    dist.fill(LLONG_MAX);
    parent.fill(-1);
    int node_changed;
    dist[node] = 0;
    forab(i, 1, N)
    {
        node_changed = -1;
        for (auto &[src, des, wei] : edges)
        {
            if (dist[src] == LLONG_MAX)
                continue;
            if (dist[des] > dist[src] + wei)
            {
                node_changed = des;
                parent[des] = src;
                dist[des] = dist[src] + wei;
            }
        }
        if (node_changed == -1)
            break;
    }

    forab(i, 1, N + 1)
    {
        vis[i] = vis[i] || (dist[i] != LLONG_MAX);
    }
    if (node_changed != -1)
    {
        node_changed = -1;
        for (auto &[src, des, wei] : edges)
        {
            if (dist[src] == LLONG_MAX)
                continue;
            if (dist[des] > dist[src] + wei)
            {
                node_changed = des;
                parent[des] = src;
                dist[des] = dist[src] + wei;
                print_cycle(des);
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    cin >> N >> M;
    vector<tuple<int, int, int>> edges;
    vis.fill(false);
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> w;
        if (x == y)
        {
            if (w < 0)
            {
                cout << "YES" << endl;
                cout << x << " " << x << endl;
                return;
            }
            continue;
        }
        edges.push_back({x, y, w});
    }
    forab(i, 1, N + 1)
    {
        if (!vis[i] && belamnFord(i, edges))
            return;
    }
    cout << "NO" << endl;
}
int32_t main()
{
    IOS;
    solve();
    return 0;
}