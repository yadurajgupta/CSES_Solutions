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
const int NMAX = 1e5 + 10;
array<vector<pair<int, int>>, NMAX> adj;
array<int, NMAX> dist;
array<int, NMAX> max_steps;
array<int, NMAX> min_steps;
array<int, NMAX> routes;
int MOD = 1e9 + 7;
int modAdd(int a, int b) { return (a % MOD + b % MOD) % MOD; }
int modMult(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
void solve()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
    set<pair<int, int>> st;
    dist.fill(LLONG_MAX);
    dist[1] = 0;
    st.insert({dist[1], 1});
    max_steps[1] = 0;
    min_steps[1] = 0;
    routes[1] = 1;
    while (!st.empty())
    {
        auto [d, node] = *st.begin();
        // debug(d, node);
        st.erase(st.begin());
        for (auto &[next, wei] : adj[node])
        {
            if (dist[next] > d + wei)
            {
                if (dist[next] != LLONG_MAX)
                    st.erase({dist[next], next});
                dist[next] = d + wei;
                st.insert({dist[next], next});
                max_steps[next] = max_steps[node] + 1;
                min_steps[next] = min_steps[node] + 1;
                routes[next] = routes[node];
            }
            else if (dist[next] == d + wei)
            {
                max_steps[next] = max(max_steps[node] + 1, max_steps[next]);
                min_steps[next] = min(min_steps[node] + 1, min_steps[next]);
                routes[next] = modAdd(routes[next], routes[node]);
            }
        }
    }
    debug(dist[N], routes[N], min_steps[N], max_steps[N]);
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