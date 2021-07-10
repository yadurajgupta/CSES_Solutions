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
vector<int> VEC;
int MXD = 18;
vector<int> num_of_nums(int dgMx)
{
    int mn = 1;
    int mx = 10;
    vector<int> temp(dgMx + 1);
    forab(i, 1, dgMx + 1)
    {
        temp[i] = mx - mn;
        mx = mx * 10;
        mn = mn * 10;
    }
    return temp;
}
char get_dig(int N, int digits)
{
    int mn = pow(10, digits - 1);
    int num = mn + N / digits;
    return to_string(num)[N % digits];
}
void solve()
{
    cin >> N;
    N--;
    forab(i, 1, MXD + 1)
    {
        if (N > VEC[i] * i)
            N -= VEC[i] * i;
        else
        {
            cout << get_dig(N, i) << endl;
            return;
        }
    }
}
int32_t main()
{
    IOS;
    int T;
    VEC = num_of_nums(MXD);
    cin >> T;
    while (T--)
        solve();
    return 0;
}