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
array<string, 1010> board;
array<array<bool, 1010>, 1010> vis;
array<array<int, 1010>, 1010> safe_till;
array<array<pair<int, int>, 1010>, 1010> parent_arr;
bool is_valid(int i, int j)
{
    return i >= 0 && i < N && j >= 0 && j < M && board[i][j] != '#' && !vis[i][j];
}
void insert_into_queue_if_valid(int x, int y, int d, queue<tuple<int, int, int>> &que)
{
    if (is_valid(x, y))
    {
        que.push({x, y, d});
        vis[x][y] = true;
        safe_till[x][y] = d;
    }
}
bool is_valid_A(int i, int j, int t)
{
    return i >= 0 && i < N && j >= 0 && j < M && board[i][j] != '#' && !vis[i][j] && t < safe_till[i][j];
}
void insert_into_queue_if_valid_A(int x, int y, int t, const pair<int, int> &parent, queue<tuple<int, int, int>> &que)
{
    if (is_valid_A(x, y, t))
    {
        que.push({x, y, t});
        parent_arr[x][y] = parent;
        vis[x][y] = true;
    }
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
    pair<int, int> start{-1, -1}, end{-1, -1};
    queue<tuple<int, int, int>> que;
    forab(i, 0, N)
    {
        forab(j, 0, M)
        {
            if (board[i][j] == 'M')
                insert_into_queue_if_valid(i, j, 0, que);
            else if (board[i][j] == 'A')
                start = {i, j};
        }
    }
    while (!que.empty())
    {
        auto [x, y, t] = que.front();
        que.pop();
        insert_into_queue_if_valid(x + 1, y, t + 1, que);
        insert_into_queue_if_valid(x - 1, y, t + 1, que);
        insert_into_queue_if_valid(x, y + 1, t + 1, que);
        insert_into_queue_if_valid(x, y - 1, t + 1, que);
    }
    for (auto &row : vis)
        row.fill(false);
    while (!que.empty())
        que.pop();
    insert_into_queue_if_valid_A(start.first, start.second, 0, {-1, -1}, que);
    while (!que.empty())
    {
        auto [x, y, t] = que.front();
        que.pop();
        pair<int, int> par{x, y};
        if (x == 0 || y == 0 || x == N - 1 || y == M - 1)
        {
            end = {x, y};
            break;
        }
        insert_into_queue_if_valid_A(x + 1, y, t + 1, par, que);
        insert_into_queue_if_valid_A(x - 1, y, t + 1, par, que);
        insert_into_queue_if_valid_A(x, y + 1, t + 1, par, que);
        insert_into_queue_if_valid_A(x, y - 1, t + 1, par, que);
    }
    if (end == make_pair(-1LL, -1LL))
    {
        cout << "NO" << endl;
        return;
    }
    auto point = end;
    string ans;
    int i, j;
    while (true)
    {
        tie(i, j) = point;
        auto &curr_parent = parent_arr[i][j];
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
    for (auto &row : safe_till)
        row.fill(LLONG_MAX);
    for (auto &row : vis)
        row.fill(false);
    for (auto &row : parent_arr)
        row.fill({-1, -1});
    solve();
    return 0;
}