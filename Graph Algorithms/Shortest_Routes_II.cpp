#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
int N, M, Q, x, y;
array<array<int, 510>, 510> dist;
// array<vector<pair<int, int>>, 510> adj;
void solve()
{
    cin >> N >> M >> Q;
    forab(i, 0, M)
    {
        int x, y, w;
        cin >> x >> y >> w;
        if (dist[x][y] == -1)
            dist[x][y] = w;
        else
            dist[x][y] = min(dist[x][y], w);

        if (dist[y][x] == -1)
            dist[y][x] = w;
        else
            dist[y][x] = min(dist[y][x], w);
    }
    forab(middle, 1, N + 1)
    {
        forab(start, 1, N + 1)
        {
            forab(end, 1, N + 1)
            {
                if (start == middle || end == middle || start == end || dist[start][middle] == -1 || dist[middle][end] == -1)
                    continue;
                if (dist[start][end] == -1)
                    dist[start][end] = dist[start][middle] + dist[middle][end];
                else
                    dist[start][end] = min(dist[start][end], dist[start][middle] + dist[middle][end]);
            }
        }
    }
    forab(i, 0, Q)
    {
        cin >> x >> y;
        cout << dist[x][y] << endl;
    }
}
int32_t main()
{
    IOS;
    int index = 0;
    for (auto &row : dist)
    {
        row.fill(-1);
        row[index++] = 0;
    }
    solve();
    return 0;
}