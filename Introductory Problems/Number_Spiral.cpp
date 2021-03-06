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
int N, x, y;
int transform(int x, int y)
{
    int band = max(x, y);
    int start = (band) * (band) + 1;
    int end = (band + 1) * (band + 1);
    int num_ele = 2 * band + 1;
    bool dir = band % 2;
    if (dir)
    {
        if (y == band)
        {
            return start + x;
        }
        else
        {
            return start + band + band - y;
        }
    }
    else
    {
        if (x == band)
        {
            return start + y;
        }
        else
        {
            return start + band + band - x;
        }
    }
}
void solve()
{
    cin >> x >> y;
    --x;
    --y;
    cout << transform(x, y) << endl;
    // invec(int, A, N);
}
int32_t main()
{
    IOS;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}