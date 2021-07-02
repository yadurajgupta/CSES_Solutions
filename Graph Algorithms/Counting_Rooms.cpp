#include <bits/stdc++.h>
#include <iostream>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#undef INT_MAX
#define INT_MAX LLONG_MAX
#define endl '\n'
#define int long long
//#define ordered_set(type) __gnu_pbds::tree<type, __gnu_pbds::null_type, less<type>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>
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
bool vis[1001][1001];
string board[1001];
bool valid(int i, int j)
{
    return i >= 0 && i < N && j >= 0 && j < M && !vis[i][j] && board[i][j] == '.';
}
void dfs(int i, int j)
{
    vis[i][j] = true;
    if (valid(i + 1, j))
        dfs(i + 1, j);
    if (valid(i - 1, j))
        dfs(i - 1, j);
    if (valid(i, j + 1))
        dfs(i, j + 1);
    if (valid(i, j - 1))
        dfs(i, j - 1);
}
void solve()
{
    cin >> N >> M;
    forab(i, 0, N)
    {
        cin >> board[i];
    }
    int ans = 0;
    forab(i, 0, N)
    {
        forab(j, 0, M)
        {
            if (valid(i, j))
            {
                dfs(i, j), ans++;
            }
        }
    }

    cout << ans << endl;
}
int32_t main()
{
    IOS;
    memset(vis, false, sizeof(vis));
    // int T;
    // cin >> T;
    // while (T--)
    solve();
    return 0;
}