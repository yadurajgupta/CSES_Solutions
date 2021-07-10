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
void solve()
{
    cin >> N;
    if (N % 4 == 0)
    {
        cout << "YES" << endl;
        cout << N / 2 << endl;
        forabi(i, 1, N + 1, 4)
        {
            cout << i << " " << i + 3 << " ";
        }
        cout << endl;
        cout << N / 2 << endl;
        forabi(i, 1, N + 1, 4)
        {
            cout << i + 1 << " " << i + 2 << " ";
        }
        cout << endl;
    }
    else if (N % 4 == 3)
    {
        cout << "YES" << endl;
        cout << 2 + (N - 3) / 2 << endl;
        cout << 1 << " " << 2 << " ";
        forabi(i, 4, N + 1, 4)
        {
            cout << i << " " << i + 3 << " ";
        }
        cout << endl;
        cout << 1 + (N - 3) / 2 << endl;
        cout << 3 << " ";
        forabi(i, 4, N + 1, 4)
        {
            cout << i + 1 << " " << i + 2 << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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