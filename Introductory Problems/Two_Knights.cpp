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
vector<int> saved_ans{0, 0, 6, 28, 96};
void find_pos(int N)
{
    if (N < 5)
    {
        cout << saved_ans[N] << endl;
    }
    else
    {
        int ans = (N - 4) * (N - 4) * (N * N - 9);
        ans += (4 * N - 12 - 4) * (N * N - 7);
        ans += (4 * N - 12) * (N * N - 5);
        ans += (8) * (N * N - 4);
        ans += (4) * (N * N - 3);
        cout << ans / 2 << endl;
    }
}
void solve()
{
    cin >> N;
    forab(i, 1, N + 1)
        find_pos(i);
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