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
int N, sum, x;
void solve()
{
    cin >> N >> sum;

    // vector<pair<int, int>> A(N);
    // forab(i, 0, N)
    // {
    //     cin >> x;
    //     A[i] = {x, i + 1};
    // }
    // sort(all(A));
    // int s = 0;
    // int e = N - 1;
    // while (s < e)
    // {
    //     if (A[s].first + A[e].first > sum)
    //     {
    //         e--;
    //     }
    //     else if (A[s].first + A[e].first < sum)
    //     {
    //         s++;
    //     }
    //     else
    //     {
    //         cout << min(A[s].second, A[e].second) << " " << max(A[s].second, A[e].second) << endl;
    //         return;
    //     }
    // }

    invec(int, A, N);
    map<int, int> mp;
    forab(i, 0, N)
    {
        if (mp.count(sum - A[i]))
        {
            cout << mp[sum - A[i]] + 1 << " " << i + 1 << endl;
            return;
        }
        mp[A[i]] = i;
    }
    cout << "IMPOSSIBLE" << endl;
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