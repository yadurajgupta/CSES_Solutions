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
void debug()
{
    cout << endl;
}
template <typename T, typename... Types>
void debug(T var1, Types... var2)
{
    cout << var1 << " ";
    debug(var2...);
}
int N, M, x, y, w;
const int NMAX = 1e5 + 10;
array<vector<pair<int, int>>, NMAX> adj;
array<int, 2 * NMAX> dist[2];
void update_node(const int &node, const int &d, const bool &discount, set<tuple<int, int, bool>> &st)
{
    if (dist[discount][node] > d)
    {
        if (dist[discount][node] != LLONG_MAX)
            st.erase({dist[discount][node], node, discount});
        dist[discount][node] = d;
        st.insert({dist[discount][node], node, discount});
    }
}
void solve()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }
    dist[0].fill(LLONG_MAX);
    dist[1].fill(LLONG_MAX);
    dist[0][1] = 0;
    set<tuple<int, int, bool>> st;
    st.insert({dist[false][1], 1, 0});

    while (!st.empty())
    {
        auto [d, node, discount] = *st.begin();
        debug(d, node, discount);
        st.erase(st.begin());
        for (auto &[next, wei] : adj[node])
        {
            if (!discount)
                update_node(next, d + wei, false, st);
            update_node(next, d + wei / (discount ? 1 : 2), true, st);
        }
    }
    cout << min(dist[0][N], dist[1][N]) << endl;
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