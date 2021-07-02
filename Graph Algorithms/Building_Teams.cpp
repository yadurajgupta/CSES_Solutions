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
#define ordered_set(type) __gnu_pbds::tree<type, __gnu_pbds::null_type, less<type>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>
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
int N, M;
array<vector<int>, (int)1e5 + 10> adj;
array<int, (int)1e5 + 10> group_arr;
void dfs(int node, int group)
{
    if (group_arr[node] == -1)
    {
        group_arr[node] = group;
        for (int next : adj[node])
        {
            dfs(next, (group + 1) % 2);
        }
    }
    else if (group_arr[node] != group)
    {
        group_arr[node] = 2;
    }
}
void solve()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    forab(i, 1, N + 1)
    {
        if (group_arr[i] == -1)
        {
            dfs(i, 0);
        }
    }
    forab(i, 1, N + 1)
    {
        if (group_arr[i] == 2)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    forab(i, 1, N + 1)
    {
        cout << group_arr[i] + 1 << " ";
    }
    // PL;
    // cout << "YES";
}
int32_t main()
{
    IOS;
    group_arr.fill(-1);
    solve();
    return 0;
}