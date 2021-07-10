#include <bits/stdc++.h>
#include <iostream>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#undef INT_MAX
#define INT_MAX LLONG_MAX
#define endl "\n"
#define int long long
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
#define print(vv)          \
    for (auto &ii : vv)    \
        cout << ii << ' '; \
    cout << endl;
#define printn(vv, NN)         \
    forab(ii, 0, NN)           \
    {                          \
        cout << vv[ii] << ' '; \
    }                          \
    cout << endl;
#define invec(type, vv, NN) \
    vector<type> vv(NN);    \
    for (auto &ii : vv)     \
        cin >> ii;

using namespace std;
int N;
vector<bool> rows(8, false);
vector<bool> cols(8, false);
vector<bool> diag1(15, false);
vector<bool> diag2(15, false);
int recur(int x, int y, vector<string> &board, int placed)
{
    if (x == 8)
        return (placed == 8);
    else
    {
        int ans = 0;
        if (board[x][y] == '.' && !rows[x] && !cols[y] && !diag1[7 + x - y] && !diag2[x + y])
        {
            rows[x] = true;
            cols[y] = true;
            diag1[7 + x - y] = true;
            diag2[x + y] = true;
            ans += recur(x + 1, 0, board, placed + 1);
            rows[x] = false;
            cols[y] = false;
            diag1[7 + x - y] = false;
            diag2[x + y] = false;
        }
        if (y <= 7)
            ans += recur(x, y + 1, board, placed);
        return ans;
    }
}
void solve()
{
    // cin >> N;
    invec(string, board, 8);
    cout << recur(0, 0, board, 0) << endl;
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