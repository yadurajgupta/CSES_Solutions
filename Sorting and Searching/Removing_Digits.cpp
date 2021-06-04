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
int N;
int dp[(int)1e6 + 10];
vector<int> digs(int num)
{
    vector<int> dig;
    while (num)
    {
        dig.push_back(num % 10);
        num /= 10;
    }
    return dig;
}
int recur(int num)
{
    if (num == 0)
        return 0;
    else if (num < 10)
        return 1;
    if (dp[num] == -1)
    {
        vector<int> dig = digs(num);
        int ans = LLONG_MAX;
        for (int i : dig)
        {
            if (i)
                ans = min(ans, 1 + recur(num - i));
        }
        dp[num] = ans;
    }
    return dp[num];
}
void solve()
{
    cin >> N;
    cout << recur(N) << endl;
}
int32_t main()
{
    IOS;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    forab(i, 1, 10)
        dp[i] = 1;
    // int T;
    // cin >> T;
    // while (T--)
    solve();
    return 0;
}