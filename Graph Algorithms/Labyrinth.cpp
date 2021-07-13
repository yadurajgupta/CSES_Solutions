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
int N, M;

array<array<bool, 1010>, 1010> vis;
array<string, 1010> board;
array<array<pair<int, int>, 1010>, 1010> parent;

bool valid(int i, int j)
{
    return i >= 0 && i < N && j >= 0 && j < M && !vis[i][j] && board[i][j] == '.';
}
char give_dir(pair<int, int> &parent, pair<int, int> &child)
{
    auto &[x1, y1] = parent;
    auto &[x2, y2] = child;
    if (x1 - 1 == x2)
        return 'U';
    if (x1 + 1 == x2)
        return 'D';
    if (y1 - 1 == y2)
        return 'L';
    if (y1 + 1 == y2)
        return 'R';
    return 'X';
}
void solve()
{
    cin >> N >> M;
    forab(i, 0, N)
    {
        cin >> board[i];
    }
    pair<int, int> empty{-1, -1};
    pair<int, int> start(empty), end(empty);
    forab(i, 0, N)
    {
        forab(j, 0, M)
        {
            if (board[i][j] == 'A')
            {
                start = {i, j};
                board[i][j] = '.';
            }
            if (board[i][j] == 'B')
            {
                end = {i, j};
                board[i][j] = '.';
            }
        }
    }
    // cout << start.first << " " << start.second << endl;
    // cout << end.first << " " << end.second << endl;
    if (start == empty || end == empty)
    {
        cout << "NO" << endl;
        return;
    }

    queue<pair<int, int>> que;
    int i, j;
    tie(i, j) = start;
    que.push(start);
    vis[i][j] = true;
    bool found = false;
    while (!que.empty())
    {
        tie(i, j) = que.front();
        if (end == que.front())
        {
            found = true;
            break;
        }
        que.pop();
        if (valid(i + 1, j))
        {
            que.push({i + 1, j});
            parent[i + 1][j] = {i, j};
            vis[i + 1][j] = true;
        }
        if (valid(i - 1, j))
        {
            que.push({i - 1, j});
            parent[i - 1][j] = {i, j};
            vis[i - 1][j] = true;
        }
        if (valid(i, j + 1))
        {
            que.push({i, j + 1});
            parent[i][j + 1] = {i, j};
            vis[i][j + 1] = true;
        }
        if (valid(i, j - 1))
        {
            que.push({i, j - 1});
            parent[i][j - 1] = {i, j};
            vis[i][j - 1] = true;
        }
    }
    if (!found)
    {
        cout << "NO" << endl;
        return;
    }
    auto point = end;
    string ans;
    while (true)
    {
        tie(i, j) = point;
        auto &curr_parent = parent[i][j];
        if (curr_parent == make_pair(-1LL, -1LL))
            break;
        ans += give_dir(curr_parent, point);
        point = curr_parent;
    }
    reverse(all(ans));
    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;
}
int32_t main()
{
    IOS;
    for (auto &row : vis)
        row.fill(false);
    for (auto &row : parent)
        row.fill({-1, -1});
    // memset(vis, false, sizeof(vis));
    // int T;
    // cin >> T;
    // while (T--)
    solve();
    return 0;
}